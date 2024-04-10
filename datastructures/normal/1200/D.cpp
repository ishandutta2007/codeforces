#include <iostream>
#include <cstdio>
using namespace std;
char a[2005][2005];
int n,k,sumx[2005][2005],sumy[2005][2005],okx[2005][2005],oky[2005][2005];
int sx[2005][2005],sy[2005][2005];
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)scanf("%s",a[i]+1);
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++){
			sumx[i][j]=sumx[i][j-1]+(a[i][j]=='B');
		}
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++){
			sumy[i][j]=sumy[i][j-1]+(a[j][i]=='B');
		}
	int ans=0;
	for (int i=1;i<=n;i++){
		if (sumx[i][n]==0)ans++;
		if (sumy[i][n]==0)ans++;
	}
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++){
			if (sumx[i][min(j+k-1,n)]-sumx[i][j-1]==sumx[i][n]&&sumx[i][n]!=0)okx[i][j]=1;
			else okx[i][j]=0;
		}
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++){
			if (sumy[i][min(j+k-1,n)]-sumy[i][j-1]==sumy[i][n]&&sumy[i][n]!=0)oky[i][j]=1;
			else oky[i][j]=0;
		}
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++)
			sx[i][j]=sx[i][j-1]+oky[j][i];
	for (register int i=1;i<=n;i++)
		for (register int j=1;j<=n;j++)
			sy[i][j]=sy[i][j-1]+okx[j][i];
	int s=0;
	for (register int i=1;i<=n-k+1;i++)
		for (register int j=1;j<=n-k+1;j++){
			s=max(s,(sx[i][j+k-1]-sx[i][j-1])+(sy[j][i+k-1]-sy[j][i-1]));
		}
	cout<<ans+s<<endl;	
}