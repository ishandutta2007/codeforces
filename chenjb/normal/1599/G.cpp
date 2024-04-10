#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<long long,long long>
using namespace std;
int n,k,l;
pii p[200020],now;
double dis(pii x,pii y){
	return sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se));
}
int check(){
	for (int i=1;i<4;i++)
	for (int j=i+1;j<4;j++)
	if ((p[i].se-p[0].se)*(p[j].fi-p[0].fi)==(p[i].fi-p[0].fi)*(p[j].se-p[0].se)) return true;
	return false;
}
int find(){
	int o;
	for (int i=1;i<4;i++)
	for (int j=i+1;j<4;j++)
	if ((p[i].se-p[0].se)*(p[j].fi-p[0].fi)==(p[i].fi-p[0].fi)*(p[j].se-p[0].se)) o=i;
	for (int i=1;i<n;i++) 
	if ((p[i].se-p[0].se)*(p[o].fi-p[0].fi)!=(p[i].fi-p[0].fi)*(p[o].se-p[0].se)) return i;
}
double calc(pii x,pii y,pii z){
	return min(dis(x,y),dis(x,z))+dis(y,z);
}
int main(){
	scanf("%d%d",&n,&k);
	double res=1e+12;
	//printf("%.6lf",res);
	k--;
	for (int i=0;i<n;i++) scanf("%lld%lld",&p[i].fi,&p[i].se);
	if (n==3){
		swap(p[0],p[k]);
		res=calc(p[0],p[1],p[2]);
	}
	else{
		if (!check()){
			swap(p[0],p[1]);
			if (k<2) k=k^1;
		}
		int tmp=find();
		swap(p[tmp],p[n-1]);
		if (k==tmp) k=n-1;
		else if (k==n-1) k=tmp;
		now=p[k];
		sort(p,p+n-1);
		l=n;
		for (int i=0;i<n;i++)
		if (p[i]==now){
			l=min(l,i);
			k=i;
		}
		if (k==n-1){
			res=calc(p[k],p[0],p[n-2]);
		}
		else{
			res=dis(p[k],p[n-1])+calc(p[n-1],p[0],p[n-2]);
			res=min(res,dis(p[k],p[0])+dis(p[0],p[n-1])+(k!=n-2)*(calc(p[n-1],p[k+1],p[n-2])));
			res=min(res,dis(p[k],p[n-2])+dis(p[n-2],p[n-1])+(l!=0)*(calc(p[n-1],p[l-1],p[0])));
			for (int i=0;i<l;i++){
				res=min(res,dis(p[k],p[n-2])+dis(p[n-2],p[i])+dis(p[i],p[n-1])+(i!=0)*(calc(p[n-1],p[0],p[i-1])));
				//res=min(res,dis(p[k],p[i])+dis(p[i],p[n-2])+dis(p[n-2],p[n-1])+(i!=0)*(calc(p[n-1],p[0],p[i-1])));
			}
			for (int i=k+1;i<n-1;i++){
				res=min(res,dis(p[k],p[0])+dis(p[0],p[i])+dis(p[i],p[n-1])+(i!=n-2)*(calc(p[n-1],p[i+1],p[n-2])));
				//res=min(res,dis(p[k],p[i])+dis(p[0],p[i])+dis(p[0],p[n-1])+(i!=n-2)*(calc(p[n-1],p[i+1],p[n-2])));
			}
		}
	}
	printf("%.6lf\n",res);
}