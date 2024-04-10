#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
const int N=2004,mod=1e9+7,M=2e5+4;
pair<int,int>a[N];
int h,w,n,f[N],jie[M],inv[M];
inline int ksm(int x,int r){
	int ret=1;
	for(int i=0;(1<<i)<=r;i++){
		if(r&(1<<i))ret=(ll)ret*x%mod;
		x=(ll)x*x%mod;
	}
	return ret;
}
inline int C(int n,int m){
	return (ll)jie[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){	
	jie[0]=jie[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=200000;i++)jie[i]=(ll)jie[i-1]*i%mod;
	inv[200000]=ksm(jie[200000],mod-2);
	for(int i=199999;i>=1;i--)inv[i]=(ll)inv[i+1]*(i+1)%mod;
	scanf("%d%d%d",&h,&w,&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1);
	a[n+1].x=h;a[n+1].y=w;
	for(int i=1;i<=n+1;i++){
		f[i]=C(a[i].x+a[i].y-2,a[i].x-1);//i
		for(int j=1;j<i;j++){
			if(a[j].y>a[i].y)continue;
			f[i]=(f[i]-(ll)f[j]*C(a[i].x+a[i].y-a[j].x-a[j].y,a[i].x-a[j].x)%mod+mod)%mod;
		} 
	}
	cout<<f[n+1];
	return (0-0);
}