/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m;
int main(){
	cin>>n>>m;
	vector<vector<int> > a(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
	int ans=0;
	for(int j=1;j<=m;j++){
		vector<int> v(n,n);
		for(int i=1;i<=n;i++)if(a[i][j]%m==j%m&&a[i][j]<=n*m)v[(i-(a[i][j]/m+1-(j==m))+n)%n]--;
		int mn=inf;
		for(int i=0;i<n;i++)mn=min(mn,v[i]+i);
		ans+=mn;
	}
	cout<<ans;
	return 0;
}