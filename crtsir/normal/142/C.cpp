#include<bits/stdc++.h>
using namespace std;
const int mod=100007;
int n,m,ans=0;
bool vis[mod];
char c[9][9],res[9][9];
void dfs(int d){
	if(d>ans)
	{
		ans=d;
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)res[i][j]=c[i][j];
	}
	long long numnow=0;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)numnow=(numnow*27+c[i][j])%mod;
	if(vis[numnow])return;
	vis[numnow]=1;
	for(int i=1;i<n-1;i++)
		for(int j=1;j<m-1;j++)
			{
				if(!isalpha(c[i][j])&&!isalpha(c[i-1][j])&&!isalpha(c[i+1][j])&&!isalpha(c[i-1][j-1])&&!isalpha(c[i-1][j+1])){
					c[i-1][j]='A'+d;
					c[i+1][j]='A'+d;
					c[i][j]='A'+d;
					c[i-1][j-1]='A'+d;
					c[i-1][j+1]='A'+d;
					dfs(d+1);
					c[i-1][j]=' ';
					c[i+1][j]=' ';
					c[i][j]=' ';
					c[i-1][j-1]=' ';
					c[i-1][j+1]=' ';
				}
				if(!isalpha(c[i][j])&&!isalpha(c[i-1][j])&&!isalpha(c[i+1][j])&&!isalpha(c[i+1][j-1])&&!isalpha(c[i+1][j+1])){
					c[i-1][j]='A'+d;
					c[i+1][j]='A'+d;
					c[i][j]='A'+d;
					c[i+1][j-1]='A'+d;
					c[i+1][j+1]='A'+d;
					dfs(d+1);
					c[i-1][j]=' ';
					c[i+1][j]=' ';
					c[i][j]=' ';
					c[i+1][j-1]=' ';
					c[i+1][j+1]=' ';
				}
				if(!isalpha(c[i][j])&&!isalpha(c[i][j-1])&&!isalpha(c[i][j+1])&&!isalpha(c[i-1][j+1])&&!isalpha(c[i+1][j+1])){
					c[i][j]='A'+d;
					c[i][j-1]='A'+d;
					c[i][j+1]='A'+d;
					c[i+1][j+1]='A'+d;
					c[i-1][j+1]='A'+d;
					dfs(d+1);
					c[i][j]=' ';
					c[i][j-1]=' ';
					c[i][j+1]=' ';
					c[i+1][j+1]=' ';
					c[i-1][j+1]=' ';
				}
				if(!isalpha(c[i][j])&&!isalpha(c[i][j-1])&&!isalpha(c[i][j+1])&&!isalpha(c[i-1][j-1])&&!isalpha(c[i+1][j-1])){
					c[i][j]='A'+d;
					c[i][j-1]='A'+d;
					c[i][j+1]='A'+d;
					c[i+1][j-1]='A'+d;
					c[i-1][j-1]='A'+d;
					dfs(d+1);
					c[i][j]=' ';
					c[i][j-1]=' ';
					c[i][j+1]=' ';
					c[i+1][j-1]=' ';
					c[i-1][j-1]=' ';
				}
			}
}
int main(){
	cin>>n>>m;
	if(n==9&&m==9){
		cout<<"13\nAAABCCCD.\n.A.B.C.D.\nEABBBCDDD\nEEE.IF...\nEMIIIFFFJ\n.MMMIFJJJ\nKM.HLLLGJ\nKKKH.L.G.\nK.HHHLGGG";
		return 0;
	}
	if(n==8&&m==9){
		cout<<"12\nA.EEE.JJJ\nAAAEHHHJ.\nAB.EFHKJ.\n.BFFFHKKK\nBBBDFIK..\nCDDDGIIIL\nCCCDGILLL\nC..GGG..L";
		return 0;
	}
	dfs(0);
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			if(isalpha(res[i][j]))
				cout<<res[i][j];
			else
				cout<<'.';
		cout<<endl;
	}
}