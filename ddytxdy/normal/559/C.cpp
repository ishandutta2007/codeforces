#include<bits/stdc++.h>
using namespace std;
const int N=2020,M=2e5+50,mod=1e9+7;
int h,w,n,J[M],I[M],f[N],ans;
struct node{int x,y,s;bool friend operator <(node a,node b){return a.x!=b.x?a.x<b.x:a.y<b.y;}}a[N];
int C(int n,int m){return 1ll*J[n]*I[m]%mod*I[n-m]%mod;}
int main(){
	scanf("%d%d%d",&h,&w,&n);J[0]=I[0]=I[1]=1;
	for(int i=2;i<=h+w;i++)I[i]=mod-1ll*mod/i*I[mod%i]%mod;
	for(int i=1;i<=h+w;i++)J[i]=1ll*J[i-1]*i%mod,I[i]=1ll*I[i-1]*I[i]%mod;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y),a[i].s=a[i].x+a[i].y;
	a[++n]=(node){h,w,h+w};sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=C(a[i].s-2,a[i].x-1);
		for(int j=1;j<i;j++){
			if(a[j].x<=a[i].x&&a[j].y<=a[i].y)
				f[i]=(f[i]-1ll*f[j]*C(a[i].s-a[j].s,a[i].x-a[j].x))%mod;
		}
	}
	printf("%d\n",(f[n]+mod)%mod);
	return 0;
}