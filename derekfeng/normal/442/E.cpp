#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef pair<db,int> pii;
#define fi first
#define se second
const db eps=1e-10,pi=acos(-1);
struct P{
	db x,y;
	P operator - (const P b){return P{x-b.x,y-b.y};}
	db len(){return sqrt(x*x+y*y);}
};
P a[1005];
db w,h;
int n,tot;
db ans;
pii mp[3100];
bool check(int x,db R){
	tot=0;
	for(int i=1;i<=n;i++)if(x!=i){
		db dist=(a[i]-a[x]).len();
		if(dist>=2*R||dist<eps)continue;
		db rd=acos(dist*0.5/R),RD=atan2((a[x].x-a[i].x),(a[x].y-a[i].y))+pi;
		db l=RD-rd,r=RD+rd;
		if(0<=l&&r<=2*pi)mp[++tot]={l,1},mp[++tot]={r+eps,-1};
		else if(l<0)mp[++tot]={l+2*pi,1},mp[++tot]={0,1},mp[++tot]={r+eps,-1};
		else mp[++tot]={l,1},mp[++tot]={0,1},mp[++tot]={r-2*pi+eps,-1};
	}
	if(a[x].x<R){
		db rd=acos(a[x].x/R);
		mp[++tot]={1.5*pi-rd,2},mp[++tot]={1.5*pi+rd+eps,-2};
	}
	if(w-a[x].x<R){
		db rd=acos((w-a[x].x)/R);
		mp[++tot]={0.5*pi-rd,2},mp[++tot]={0.5*pi+rd+eps,-2};
	}
	if(a[x].y<R){
		db rd=acos(a[x].y/R);
		mp[++tot]={pi-rd,2},mp[++tot]={pi+rd+eps,-2};
	}
	if(h-a[x].y<R){
		db rd=acos((h-a[x].y)/R);
		mp[++tot]={0,2},mp[++tot]={rd+eps,-2},mp[++tot]={2*pi-rd,2};
	}
	if(tot==0)return 1;
	sort(mp+1,mp+tot+1);
	if(fabs(mp[1].fi)>eps)return 1;
	int cur=0;
	for(int i=1;i<=tot;i++){
		cur+=mp[i].se;
		if(cur<2&&(i==tot||fabs(mp[i].fi-mp[i+1].fi)>eps))return 1;
	}
	return 0;
}
int main(){
	scanf("%lf%lf%d",&w,&h,&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	shuffle(a+1,a+n+1,default_random_engine{19260817});
	for(int i=1;i<=n;i++)if(check(i,ans)){
		db l=ans,r=2e6,md;
		while(l+1e-9<r){
			md=(l+r)*0.5;
			if(check(i,md))l=md;
			else r=md;
		}
		ans=(l+r)*0.5;
	}
	printf("%.10lf",ans);
}