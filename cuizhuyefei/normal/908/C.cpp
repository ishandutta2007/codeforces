#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 5050;
int n,r,x[N];
double p[N];
inline double abs(double x) {return x>0 ? x : -x;}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); read(r); rep(i,1,n) read(x[i]);
	rep(i,1,n) {
		p[i]=r;
		rep(j,1,i-1) if (abs(x[j]-x[i])<=r*2) 
			p[i]=max(p[i],p[j]+sqrt(r*r*4-(x[i]-x[j])*(x[i]-x[j])));
	}
	rep(i,1,n) printf("%.8lf ",p[i]);
	return 0;
}