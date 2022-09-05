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
const int N = 666666;
int n,a[N];
bool win(){
	ll res=0;rep(i,1,n)res+=a[i]-(i-1);
	return res%2;
}
int main() {
	read(n);rep(i,1,n)read(a[i]);
	sort(a+1,a+n+1);bool find=0;
	rep(i,1,n-1)if(a[i]==a[i+1]){
		a[i]--;find=1;break;
	}
	if(!find)printf("%s\n",win()?"sjfnb":"cslnb");
	else{
		sort(a+1,a+n+1);find=0;
		rep(i,1,n-1)find|=a[i]==a[i+1];
		if(find||a[1]<0||win())puts("cslnb");
		else puts("sjfnb");
	}
	return 0;
}