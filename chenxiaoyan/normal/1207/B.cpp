/*








 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
const int N=50,M=50;
int n,m;
int a[N+1][M+1],b[N+1][M+1];
vector<pair<int,int> > ans;
bool eq(){
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(a[i][j]!=b[i][j])return false;
	return true;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	for(int i=1;i<n;i++)for(int j=1;j<m;j++)
		if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1])
			ans.pb(mp(i,j)),b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
	if(eq()){
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++)cout<<ans[i].X<<" "<<ans[i].Y<<"\n";
	}
	else puts("-1");
	return 0;
}