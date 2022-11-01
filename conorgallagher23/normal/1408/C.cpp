#include<bits/stdc++.h>
#define LL long long
#define db double
using namespace std;
const int N=1e5+5;
int n,len,a[N];
bool check(db mid){
	db res=mid,spd=1,nl=0,nr=len;
	for(int i=1;i<=n;i++)
		if(res*spd<a[i]-nl)nl+=res*spd,res=0;
		else res-=(a[i]-nl)/spd,nl=a[i],spd++;
	nl+=res*spd;
	res=mid;spd=1;
	for(int i=n;i;i--)
		if(res*spd<nr-a[i])nr-=res*spd,res=0;
		else res-=(nr-a[i])/spd,nr=a[i],spd++;
	nr-=res*spd;
	return nl>=nr;
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&len);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		db l=0,r=len;
		for(int t=1;t<=200;t++){
			db mid=(l+r)/2.0;
			if(check(mid))r=mid;else l=mid;
		}
		printf("%.10lf\n",l);
	}
	return 0;
}