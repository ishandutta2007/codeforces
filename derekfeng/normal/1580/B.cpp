#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[105][105][105],C[105][105];
int n,m,k,P;
int main(){
	cin>>n>>m>>k>>P;
	for(int i=0;i<105;C[i][0]=1,i++)for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
	for(int i=n+1;i;i--){
		f[i][0][0]=1;
		vector<int>v[105];
		for(int j=0;j<=n;j++)
			for(int l=0;l<=j;l++)
				if(f[i+1][j][l])v[j].push_back(l);
		for(int j=0;j<=n;j++)if(!v[j].empty())
			for(int l=0;j+l<=n;l++)if(!v[l].empty())
				for(auto x:v[j])for(auto y:v[l])
					(f[i][j+l+1][x+y+(i==m)]+=(ll)C[j+l][j]*f[i+1][j][x]%P*f[i+1][l][y]%P)%=P;
	}
	printf("%d",f[1][n][k]);
}