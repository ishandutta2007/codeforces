#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 604000;
struct dot{int x,y;}s[N];int f[N],n,m,q;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x, int y){
	x=find(x);y=find(y);f[x]=y;
}
int main() {
	int a,b;read(a);read(b);read(n);int res=0,x,y;
	rep(i,1,a+b)f[i]=i;
	rep(i,1,n)read(x),read(y),merge(x,a+y);
	rep(i,1,a+b)res+=find(i)==i;res--;
	cout<<res;
	return 0;
}