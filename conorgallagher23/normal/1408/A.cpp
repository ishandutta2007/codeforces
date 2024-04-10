#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
const int N=105;
int n,a[N][3],p[N][3][3];bool dp[N][3][3];
vector<int>Ans;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int k=0;k<3;k++)for(int i=1;i<=n;i++)scanf("%d",&a[i][k]);
		for(int i=1;i<=n;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)dp[i][j][k]=false;
		for(int i=0;i<3;i++)dp[1][i][i]=true;
		for(int i=2;i<=n;i++)for(int j=0;j<3;j++)for(int k=0;k<3;k++)
			if(dp[i-1][j][k]){
				for(int l=0;l<3;l++)if(a[i][l]!=a[i-1][j])dp[i][l][k]=true,p[i][l][k]=j;
			}
		bool fl=false;
		for(int i=0;i<3;i++){
			for(int j=0,c,now;j<3;j++)if(a[1][i]!=a[n][j]&&dp[n][i][j]){
				c=i;now=0;fl=true;Ans.clear();
				for(int k=n;k;k--)Ans.pb(c),c=p[k][c][j];
				reverse(Ans.begin(),Ans.end());
				for(auto x:Ans)printf("%d ",a[++now][x]);puts("");
				break;
			}
			if(fl)break;
		}
	}
	return 0;
}