#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=100005;
const double pi=acos(-1.0);
double x,y;
double a[maxn],b[maxn];
int n;
inline double cross(double a1,double b1,double a2,double b2){
	return a1*b2-a2*b1;
}
inline double dot(double a1,double b1,double a2,double b2){
	return a1*a2+b1*b2;
}
int main(){
	read(n);scanf("%lf%lf",&x,&y);
	rep(i,1,n){
		scanf("%lf%lf",&a[i],&b[i]);
	}double maxi=0,mini=1e20;
	rep(i,1,n)maxi=max(maxi,sqrt(sqr(x-a[i])+sqr(y-b[i]))),mini=min(mini,sqrt(sqr(x-a[i])+sqr(y-b[i])));
	a[n+1]=a[1];b[n+1]=b[1];
	rep(i,1,n){
		if(dot(a[i+1]-a[i],b[i+1]-b[i],x-a[i],y-b[i])<0)continue;
		if(dot(a[i]-a[i+1],b[i]-b[i+1],x-a[i+1],y-b[i+1])<0)continue;
		mini=min(mini,fabs(cross(a[i]-x,b[i]-y,a[i+1]-x,b[i+1]-y))/sqrt(sqr(a[i+1]-a[i])+sqr(b[i+1]-b[i])));
	}
	printf("%.20f\n",(sqr(maxi)-sqr(mini))*pi);
	return 0;
}