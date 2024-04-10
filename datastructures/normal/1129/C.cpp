#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
using namespace std;
int n,a[3005],f[3005],g[3005][3005];
int lcp[3005][3005],qwq[3005],ans;
int check(int l,int r){
	if (r-l+1<1||r-l+1>4)return 0;
	if (r-l+1!=4)return 1;
	if ((a[l]+a[l+1]==0)&&(a[l+2]+a[l+3]==2))return 0;
	if ((a[l]+a[l+2]==0)&&(a[l+1]+a[l+3]==2))return 0;
	if ((a[l]+a[l+1]+a[l+2]==3)&&(a[l+3]==0))return 0;
	if (a[l]+a[l+1]+a[l+2]+a[l+3]==4)return 0;
	return 1;
}
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)cin>>a[i];
	for (int i=n;i>=1;i--)
		for (int j=n;j>=1;j--)
			if (a[i]==a[j])lcp[i][j]=1+lcp[i+1][j+1];
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)qwq[i]=max(qwq[i],lcp[i][j]);
	for (int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		f[i-1]=1;
		for (int j=i;j<=n;j++){
			for (int k=j;k>=i&&k>=j-3;k--){
				if (check(k,j)==1)upd(f[j],f[k-1]);
			}
			g[i][j]=f[j];
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j>=1;j--)
			if (j+qwq[j]-1<i)upd(ans,g[j][i]);
		cout<<ans<<endl;
	}
	return 0;
}