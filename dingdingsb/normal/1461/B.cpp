#include<bits/stdc++.h>
using namespace std;
int t,n,m;
char mp[510][510];
int sum[510][510];
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>mp[i]+1;
		memset(sum,0,sizeof sum);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				sum[i][j]=sum[i][j-1]+(mp[i][j]=='*');
		long long ans=0;
		for(int x=1;x<=n;x++)
			for(int y=1;y<=m;y++){
				//
				if(mp[x][y]!='*')continue;
				int now=1,xx=x,l=y,r=y;
				while(true){
					xx++,l--,r++;
					if(xx>n||l<1||r>m)break;
					if(sum[xx][r]-sum[xx][l-1]!=(r-l+1))break;
					now++;
				}ans+=now;
			}
		cout<<ans<<endl;
	}
	return 0;
}