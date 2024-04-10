/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int hsc=1000000007;
const int N=1000,M=1000;
int n,m;
bool vis[N+2][M+2],a[N+1][M+1];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)vis[i][j]=true,a[i][j]=true;
		vis[i][x+1]=true;a[i][x+1]=false;
	}
	for(int j=1;j<=m;j++){
		int x;
		cin>>x;
		for(int i=1;i<=x;i++){
			if(vis[i][j]&&!a[i][j])return puts("0"),0;
			vis[i][j]=true;a[i][j]=true;
		}
		if(vis[x+1][j]&&a[x+1][j])return puts("0"),0;
		vis[x+1][j]=true;a[x+1][j]=false;
	}
	int ans=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(!vis[i][j])(ans<<=1)%=hsc;
	cout<<ans;
	return 0;
}