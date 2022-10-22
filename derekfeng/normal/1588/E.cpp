#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
const db pi=acos(-1);
const db eps=1e-6;
typedef pair<db,db> pii;
struct P{db x,y;}a[3003];
db dist(const P&A,const P&B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
int n,ans;
db R;
vector<pii>range[3003];
void trans(vector<pii>&x,vector<pii>y){
	vector<pii>v;
	for(int i=0;i<x.size();i++)
		for(int j=0;j<y.size();j++)
			v.push_back({max(x[i].fi,y[j].fi),min(x[i].se,y[j].se)});
	sort(v.begin(),v.end());
	x.clear();
	for(int i=0,j;i<v.size();i=j){
		db L=v[i].fi,R=v[i].se;
		j=i+1;
		if(L<=R){
			for(;j<v.size();j++){
				if(v[j].fi>R)break;
				R=max(R,v[j].fi);
			}
			if(R-L>eps)x.push_back({L,R});
		}
	}
}
bool check(vector<pii>&x,db y){
	for(int i=0;i<x.size();i++)
		if(x[i].fi-eps<=y&&y<=x[i].se+eps)return 1;
	return 0;
}
int main(){
	scanf("%d%lf",&n,&R);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i].x,&a[i].y),range[i].push_back({0,2*pi});
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
		db D=dist(a[i],a[j]);
		if(D>R){
			db rd=asin(R/D),RAD=atan2((a[j].x-a[i].x),(a[j].y-a[i].y))+pi;
			db LD=RAD-rd,RD=RAD+rd;
			vector<pii>upd;
			if(0<=LD&&RD<=2*pi)upd.push_back({LD,RD});
			else if(LD<0)upd.push_back({LD+2*pi,2*pi}),upd.push_back({0,RD});
			else upd.push_back({LD,2*pi}),upd.push_back({0,RD-2*pi});
			trans(range[j],upd);
		}
	}
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		db ri=atan2((a[i].x-a[j].x),(a[i].y-a[j].y))+pi;
		db rj=atan2((a[j].x-a[i].x),(a[j].y-a[i].y))+pi;
		if(check(range[i],ri)&&check(range[j],rj))ans++;
	}
	printf("%d",ans);
}