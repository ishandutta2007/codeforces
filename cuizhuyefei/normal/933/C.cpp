#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 500;
const double eps = 1e-7;
int n;
double x[N],y[N],r[N];
struct dot {
	double x,y;
	dot(double X=0, double Y=0) {x=X; y=Y;}
} s[N]; int len;
double Abs(double x) {return x>-eps ? x : -x;}
int f[N],a[N][N];
bool gg[N];
int find(int x) {
	if (f[x]==x) return x;
	f[x]=find(f[x]); return f[x];
}
int main() {
	read(n); rep(i,1,400) f[i]=i;
	rep(i,1,n) scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
	int ans=1;
	rep(i,1,n) rep(j,i+1,n) {
		double dis=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		if (dis<r[i]+r[j]+eps&&dis>Abs(r[i]-r[j])-eps) {
			double X=atan2(y[j]-y[i],x[j]-x[i]);
			double Y=acos((r[i]*r[i]+dis*dis-r[j]*r[j])/2/r[i]/dis);
			s[++len]=dot(x[i]+r[i]*cos(X+Y),y[i]+r[i]*sin(X+Y));
			s[++len]=dot(x[i]+r[i]*cos(X-Y),y[i]+r[i]*sin(X-Y));
		}
	}
	rep(i,1,len) rep(j,i+1,len) if (Abs(s[i].x-s[j].x)<eps&&Abs(s[i].y-s[j].y)<eps) gg[j]=1;
	int tot=0; rep(i,1,len) if (!gg[i]) s[++tot]=s[i]; len=tot;
	rep(i,1,n) {rep(j,1,len) {
		int t=Abs(r[i]-sqrt((x[i]-s[j].x)*(x[i]-s[j].x)+(y[i]-s[j].y)*(y[i]-s[j].y)))<eps;
		if (t) {ans++; a[i][j]=1;}
	}
	bool ff=0; rep(j,1,len) ff|=a[i][j];
	if (!ff) {s[++len]=dot(x[i],y[i]+r[i]); ans++; a[i][len]=1;}
	}
	rep(i,1,n) rep(j,1,len) rep(k,j+1,len) if (a[i][j]&&a[i][k]) f[find(j)]=find(k);
	
	ans-=len;
	rep(i,1,len) ans+=find(i)==i;
//	printf("%d\n",len);
	cout<<ans;
	return 0;
}