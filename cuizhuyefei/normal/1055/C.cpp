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
int l,r,t,L,R,T;
int gcd(int a, int b){return !b?a:gcd(b,a%b);}
int main() {
	read(l);read(r);read(t);
	read(L);read(R);read(T);
	if(r-l<R-L){swap(l,L);swap(r,R);swap(t,T);}
	int g=gcd(t,T),k=(L-l)%g;
	if(k<0)k+=g;int res=max(0,min(k+R-L,r-l)-max(0,k)+1);
	k-=g;res=max(res,min(k+R-L,r-l)-max(0,k)+1);
	printf("%d",res);
	return 0;
}