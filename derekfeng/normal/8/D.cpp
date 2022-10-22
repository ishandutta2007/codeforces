#include<bits/stdc++.h>
using namespace std;
typedef double db;
const db eps=(1e-10);
struct P{db x,y;}a[3];
db t1,t2,r[3],d1,d2;
db Dis(P a,P b){
	db dx=a.x-b.x;
	db dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}
bool check(db R){
	r[0]=R;
	r[1]=d1+t1-R;
	r[2]=d2+t2-Dis(a[2],a[1])-R;
	if(r[1]<0||r[2]<0)return 0;
	vector<P>vec;
	for(int i=0;i<3;i++)vec.push_back(a[i]);
	for(int i=0;i<3;i++)for(int j=i+1;j<3;j++){
		db D=Dis(a[i],a[j]);
		db mn=min(r[i],r[j]),mx=max(r[i],r[j]);
		if(D>r[i]+r[j]+eps)return 0;
		if(D+mn<mx-eps)continue;
		db t=(r[i]*r[i]-r[j]*r[j]+D*D)/D*0.5;
		db z=atan2(a[j].y-a[i].y,a[j].x-a[i].x);
		P s=(P){a[i].x+t*cos(z),a[i].y+t*sin(z)};
		db G=r[i]*r[i]-t*t;if(G<0)G=0;
		db g=sqrt(G);
		db w=atan2(a[j].x-a[i].x,a[i].y-a[j].y);
		vec.push_back((P){s.x+g*cos(w),s.y+g*sin(w)});
		vec.push_back((P){s.x-g*cos(w),s.y+g*sin(w)});
	}
	for(auto x:vec){
		bool ok=1;
		for(int i=0;i<3;i++)
			ok&=Dis(x,a[i])<r[i]+eps;
		if(ok)return 1;
	}
	return 0;
}
int main(){
	scanf("%lf%lf",&t2,&t1);
	for(int i=0;i<3;i++)scanf("%lf%lf",&a[i].x,&a[i].y);
	d1=Dis(a[0],a[1]),d2=Dis(a[0],a[2])+Dis(a[2],a[1]);
	if(d2<d1+eps+t1){
		printf("%.8lf",min(d1+t1,d2+t2));
		return 0;
	}
	db ld=0,rd=400;
	for(int t=0;t<100;t++){
		db md=(ld+rd)*0.5;
		if(check(md))ld=md;
		else rd=md;
	}
	printf("%.8lf",rd);
}