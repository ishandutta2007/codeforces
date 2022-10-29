#include<bits/stdc++.h>
using namespace std;
typedef long double db;
const int N=2e5;
const db eps=1e-8;
bool check(db x){ return abs(x)<eps; }
int n,k;
struct P{
	db x,y; int id;
	P(db x=0,db y=0,int id=0):x(x),y(y),id(id){}
	db norm(){ return sqrtl(x*x+y*y); }
	P operator - (const P t) const{ return P(x-t.x,y-t.y); }
}p[N+5],tp,pk;
int sp;
db diss;
db dis(P x,P y){ return (x-y).norm(); }
db cross(P t1,P t2){ return t1.x*t2.y-t1.y*t2.x; }
bool chk(P a,P b){
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(!check(cross(p[i]-a,p[i]-b))){
			sp=i; cnt++;
		}
	return cnt==1;
}
void prep(){
	if(chk(p[1],p[2])) return;
	if(chk(p[1],p[3])) return;
	chk(p[2],p[3]);
}
bool cmp(P x,P y){ return check(x.x-y.x)?x.y<y.y:x.x<y.x; }
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%LF %LF",&p[i].x,&p[i].y);
		p[i].id=i;
	}
	prep();
	tp=p[sp]; pk=p[k];
	for(int i=sp;i<n;i++) p[i]=p[i+1];
	sort(p+1,p+n,cmp);
	diss=dis(p[1],p[n-1])+min(dis(tp,p[1]),dis(tp,p[n-1]));
	if(k==sp) printf("%.10LF\n",diss);
	else{
		db d1=dis(tp,p[1]),dn=dis(tp,p[n-1]),d1n=dis(p[1],p[n-1]);
		db ans=min(dis(tp,pk)+diss,d1n+min(dis(pk,p[n-1])+d1,dis(pk,p[1])+dn));
		for(int i=1;i<n-1;i++)
			if(p[i].id==k)
				ans=min(ans,d1n-dis(p[i],p[i+1])+d1+min(dis(tp,p[i+1]),dn));
		for(int i=2;i<n;i++)
			if(p[i].id==k)
				ans=min(ans,d1n-dis(p[i],p[i-1])+dn+min(dis(tp,p[i-1]),d1));
		for(int i=1;i<n-1;i++)
			ans=min(ans,d1n-dis(p[i],p[i+1])+min(dis(pk,p[1])+dis(p[i],tp),dis(pk,p[i])+d1)+min(dis(p[i+1],tp),dn));
		for(int i=2;i<n;i++)
			ans=min(ans,d1n-dis(p[i-1],p[i])+min(dis(pk,p[n-1])+dis(p[i],tp),dis(pk,p[i])+dn)+min(dis(p[i-1],tp),d1));
		if(p[1].id==k) ans=min(ans,d1n+dis(p[n-1],tp));
		if(p[n-1].id==k) ans=min(ans,d1n+dis(p[1],tp));
		printf("%.10LF\n",ans);
	}
	return 0;
}