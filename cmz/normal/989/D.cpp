#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const double pi=acos(-1);
int n,l,w,ans,kk;
int a[maxn],q[maxn],h,t;
struct Vec{
	double x,y;
	Vec(){}
	Vec(double _x,double _y){
		x=_x; y=_y;
	}
	friend Vec operator + (Vec a,Vec b){
		return Vec(a.x+b.x,a.y+b.y);		
	}
	friend Vec operator - (Vec a,Vec b){
		return Vec(a.x-b.x,a.y-b.y);		
	}
	friend double operator * (Vec a,Vec b){
		return a.x*b.y-a.y*b.x;		
	}
	friend double operator ^ (Vec a,Vec b){
		return a.x*b.x-a.y*b.y;
	}
};
inline double cross(Vec a,Vec b,Vec c){return (b-a)*(c-a);}
inline bool segts(Vec a,Vec b,Vec c,Vec d){
	double h1=cross(a,b,c)*cross(a,b,d),h2=cross(c,d,a)*cross(c,d,b);
	if (h1<=0.0&&h2<=0.0) return 1; else return 0;
}
inline bool lints(Vec a,Vec b,Vec c,Vec d){ 
	double h1=cross(a,b,c)*cross(a,b,d);
	if (h1<=0.0) return 1; else return 0;
}
inline bool lintl(Vec a,Vec b,Vec c,Vec d){
	if ((b-a)*(d-c)==0.0) return 1;
	if (cross(a,b,d)==0.0) return 0; else return 1; 
}
inline Vec llcro(Vec a,Vec b,Vec c,Vec d){
	double s1=(d-a)*(c-a),s2=(c-b)*(d-b)+s1;
	b.x=a.x+(b.x-a.x)/s2*s1; b.y=a.y+(b.y-a.y)/s2*s1;
	return b;
}
inline double ppdis(Vec x,Vec y){ 
	double kk=(y.y-x.y)*(y.y-x.y)+(y.x-x.x)*(y.x-x.x);
	return sqrt(kk);
}
inline double pldis(Vec a,Vec b,Vec c){
	return fabs(cross(b,a,c)/ppdis(b,c));
} 
inline double angle(Vec a,Vec b,Vec c,Vec d){
	Vec c1=llcro(a,b,c,d);
	return asin(cross(c1,a,c)/ppdis(c1,a)/ppdis(c1,c))/pi*180.0;
}
bool check(int mid) {
	int now=a[mid]+l;
	double h=(double)((double)now-(double)kk)/2.0;
	if(h>fabs(((double)now*1.0+kk*1.0)/(2.0*w))) return 1; else return 0;
}
void solve(int l,int r) {
	if(l>r) return;
	int mid=(l+r)>>1;
	if(check(mid)) {
		ans=mid;
		solve(mid+1,r);
	} else solve(l,mid-1);
}
int main() {
	scanf("%d%d%d",&n,&l,&w);
	for(int i=1,x,v; i<=n; i++) {
		scanf("%d%d",&x,&v);
		if(v==1) q[++t]=x; else a[++h]=x;
	}
	sort(a+1,a+h+1,[](const int &x,const int &y){
		return x>y;
	});
	ll tot=0;
	for(int i=1; i<=t; i++) {
		ans=0; kk=q[i];
		solve(1,h); tot+=ans;
	}
	printf("%I64d\n",tot);
	return 0;
}