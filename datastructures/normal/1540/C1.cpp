#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
using namespace std;
int n,c[105],b[105],val[105],f[105][10005];
int q,x;
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
int dp(int x){
	memset(f,0,sizeof(f));
	f[0][0]=1;
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=10000;j++){
			if (j<val[i]+i*x)f[i][j]=0;
			else{
				for (int k=0;k<=c[i];k++)
					if (k<=j)upd(f[i][j],f[i-1][j-k]);
			}
			if (i==n)upd(ans,f[i][j]);
		}
	return ans;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>c[i];
	for (int i=1;i<n;i++)cin>>b[i];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			val[i]+=b[j]*(i-j);
	cin>>q;
	while(q--){
		scanf("%d",&x);
		printf("%d\n",dp(x));
	}
	return 0;
}