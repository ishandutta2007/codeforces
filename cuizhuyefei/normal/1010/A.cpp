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
const int N = 6666;const double eps = 1e-9;
int n,m,a[N],b[N];
void Get(long double &x, int y){
	x=x*(y-1)/y;
}
int main() {
	read(n);read(m);
	rep(i,1,n)read(a[i]);rep(i,1,n)read(b[i]);
//	rep(i,1,n)if(a[i]==1||b[i]==1){puts("-1");return 0;}
	double l=0,r=1e9+10,res=2e9;
	per(t,70,1){
		double mid=(l+r)/2;long double now=m+mid;
		rep(i,1,n)Get(now,a[i]),Get(now,b[i<n?i+1:1]);
		if(now>=m)res=mid,r=mid;else l=mid;
	}
	if(res>1e9+1e-6)puts("-1");else 
	printf("%.9lf",res);
	return 0;
}