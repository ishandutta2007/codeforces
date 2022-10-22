#include<bits/stdc++.h>
using namespace std;
typedef double db;
template<class T> void chmin(T& x,T y){ y<x?x=y:T(); }
template<class T> void chmax(T& x,T y){ y>x?x=y:T(); }
const db EPS=1e-10,PI=acos(-1),PI_2=PI+PI;
const int N=5005;
struct K{ int t; db x,y; };
inline bool cmp(K x,K y){ return x.x<y.x; }
vector<K> a;
vector<db> dis,ang;
db normal(db x){
	while(x<0) x+=PI_2;
	while(x>=PI_2) x-=PI_2;
	return x;
}
int sn(db x){ return x<-EPS?-1:(x>EPS?1:0); }
bool check(K x,db r){
	static K f[N];
	int top=0;
	vector<db> mx({-1,-1});
	for(int i=0;i<a.size();++i){
		if(sn(dis[i])==0){
			if(a[i].t==1)
				chmax(mx[a[i].t],PI_2);
			continue;
		}
		if(sn(dis[i]-r-r)>=0) continue;
		db d=acos(dis[i]/(r+r));
		db l=normal(ang[i]-d),r=normal(ang[i]+d);
//		printf("[%d %lf %lf]",a[i].t,l,r);
		if(l>r){
			chmax(mx[a[i].t],r);
			f[++top]=(K){a[i].t,l,PI_2};
		}else
			f[++top]=(K){a[i].t,l,r};
	}
//	printf("(%lf %lf)",mx[0],mx[1]);
	sort(f+1,f+top+1,cmp);
	for(int i=1;i<=top;++i){
//		printf("<%d %lf %lf>",f[i].t,f[i].x,f[i].y);
		if(f[i].t==0){
			if(mx[0]+EPS<mx[1]&&mx[0]+EPS<f[i].x) return true;
		}else{
			if(mx[0]+EPS<f[i].x) return true;
		}
		chmax(mx[f[i].t],f[i].y);
	}
	return mx[0]+EPS<mx[1];
}
db solve(K x,db left){
	dis.resize(a.size()); ang.resize(a.size());
	for(int i=0;i<a.size();++i){
		K f=(K){0,a[i].x-x.x,a[i].y-x.y};
		dis[i]=sqrt(f.x*f.x+f.y*f.y);
		ang[i]=atan2(f.y,f.x);
	}
//	printf("%d",int(check(x,1.249993886)));
//	exit(0);
	if(!check(x,left)) return 0;
//	printf("[%d %lf %lf]",x.t,x.x,x.y);
//	printf("%d",int(check(x,1.2499938)));
//	exit(0);
	db right=5e8;
	while(fabs(right-left)/max(left,1.0)>1e-5){
		db mid=(left+right)/2;
		if(check(x,mid)) left=mid;
		else right=mid;
	}
	if(right==(db)5e8) puts("-1"),exit(0);
//	printf("<%lf>\n",left);
	return left;
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	a.resize(n+m);
	for(int i=0;i<n;++i) scanf("%lf%lf",&a[i].x,&a[i].y),a[i].t=1;
	for(int i=n;i<n+m;++i) scanf("%lf%lf",&a[i].x,&a[i].y),a[i].t=0;
	db ans=0;
	for(int i=0;i<a.size();++i)
		chmax(ans,solve(a[i],ans));
	printf("%.10lf\n",ans);
	return 0;
}