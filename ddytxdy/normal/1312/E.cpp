#include<bits/stdc++.h>
using namespace std;
const int N=520;
int n,a[N],id[N][N],f[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&id[i][i]);
	for(int i=n;i;i--)
		for(int j=i+1;j<=n;j++)
			for(int k=i;k<j;k++)
				if(id[i][k]&&id[i][k]==id[k+1][j])id[i][j]=id[i][k]+1;
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)
		if(id[j][i])f[i]=max(f[i],f[j-1]+i-j);
	cout<<n-f[n];
}