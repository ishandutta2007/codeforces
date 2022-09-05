#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 366666,inf=0x3f3f3f3f;
int n,a[N];multiset<int>Set;
bool ck(int p){
	if(Set.empty())return 0;
	return *Set.rbegin()>2*a[p+1];
}
int main() {
	int mx=-inf,mn=inf;
	read(n);rep(i,1,n)read(a[i]),umax(mx,a[i]),umin(mn,a[i]);
	if(mn*2>=mx){rep(i,1,n)printf("-1 ");return 0;}
	rep(i,1,n)a[n+i]=a[n+n+i]=a[i];
	Set.insert(a[1]);
	for(int i=1,j=1;i<=n;i++){
		while(!ck(j))j++,Set.insert(a[j]);
		printf("%d ",j-i+1);Set.erase(Set.find(a[i]));
	}
	return 0;
}