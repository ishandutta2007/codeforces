#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
const int N = 3000000;
int mrk[N],len,prime[N];
inline void init() {
	int n=2000000;
	mrk[1]=1;
	rep(i,2,n) {
		if (!mrk[i]) prime[++len]=i;
		rep(j,1,len) {
			if (i*prime[j]>n) break;
			mrk[i*prime[j]]=1; if (i%prime[j]==0) break;
		}
	}
}
bool is_p(int n) {
	return !mrk[n];
}
int a[12];
bool is_p1(int n) {
	int len=0; while (n) {a[++len]=n%10; n/=10;}
	rep(i,1,len>>1) if (a[i]!=a[len-i+1]) return 0;
	return 1;
}
int main() {
	int p,q; read(p); read(q);
	int a=0,b=0,ans=-1; init();
	for (int n=1;n<=2000000;n++) {
		a+=is_p(n); b+=is_p1(n);
		
//	if (n>=999700) 	printf("%d %.2lf\n",n,1.0*a/b);
		if (1LL*a*q<=1LL*b*p) {ans=n;}
	}
	printf("%d",ans);
	return 0;
}