#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
using namespace std;
int n,c[105],b[105],val[105],f[105][10005],sum[105][10005];
int tot,num[1005],d[1005];
int q,x;
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
int dp(int x){
	memset(f,0,sizeof(f));
	memset(sum,0,sizeof(sum));
	f[0][0]=1;
	for (int j=0;j<=10000;j++){
		if (j>0)sum[0][j]=sum[0][j-1];
		upd(sum[0][j],f[0][j]);
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=10000;j++){
			if (j<val[i]+i*x)f[i][j]=0;
			else{
				f[i][j]=sum[i-1][j];
				if (j>c[i])upd(f[i][j],mod-sum[i-1][j-c[i]-1]);
			}
			if (i==n)upd(ans,f[i][j]);
			if (j>0)sum[i][j]=sum[i][j-1];
			upd(sum[i][j],f[i][j]);
		}
	return ans;
}
int find(int x){
	for (int i=1;i<=tot;i++)
		if (num[i]>=x)return d[i];
	return 0;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>c[i];
	for (int i=1;i<n;i++)cin>>b[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			val[i]+=b[j]*(i-j);
	int mn=1000000000;
	for (int i=1;i<=n;i++)mn=min(mn,-val[i]/i-1);
	for (int i=mn;i<=mn+105;i++){
		++tot;
		num[tot]=i;
		d[tot]=dp(i);
	}
	++tot;
	num[tot]=1000000000;
	d[tot]=0;
	cin>>q;
	while(q--){
		scanf("%d",&x);
		printf("%d\n",find(x));
	}
}