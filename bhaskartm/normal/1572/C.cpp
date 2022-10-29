#include<bits/stdc++.h>
using namespace std;
int t,n,a[3003],f[3003][3003];
vector<int>p[3003];
void sol(){
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++){
		p[i].clear();
		for(int j=0;j<=n+1;j++)f[i][j]=0;
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[a[i]].push_back(i);
	for(int len=1;len<n;len++)
		for(int i=1,j=len+1;j<=n;i++,j++){
			f[i][j]=f[i+1][j];
			for(auto x:p[a[i]])if(i<x&&x<=j)
				f[i][j]=max(f[i][j],f[i+1][x-1]+f[x][j]+1);
		}
	printf("%d\n",n-1-f[1][n]);
}
int main(){for(scanf("%d",&t);t--;sol());}