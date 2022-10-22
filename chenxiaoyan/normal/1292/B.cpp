/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define dis(x,y) (abs(v[x].X-v[y].X)+abs(v[x].Y-v[y].Y))
signed main(){
	int x0,y0,ax,ay,bx,by,xs,ys,t;
	cin>>x0>>y0>>ax>>ay>>bx>>by>>xs>>ys>>t;
	vector<pair<int,int> > v;
	v.pb(mp(x0,y0));
	while(true){
		v.pb(mp(ax*v.back().X+bx,ay*v.back().Y+by));
		if(v.back().X>3e16||v.back().Y>3e16)break;
	}
	int ans=0;
	for(int i=0;i<v.size();i++){
		vector<vector<vector<int> > > dp(v.size(),vector<vector<int> >(v.size(),vector<int>(2)));
		for(int j=0;j<v.size();j++)dp[j][j][0]=dp[j][j][1]=abs(v[i].X-xs)+abs(v[i].Y-ys)+dis(i,j);
		for(int j=v.size()-1;~j;j--)for(int k=j+1;k<v.size();k++){
			dp[j][k][0]=min(dp[j+1][k][0]+dis(j,j+1),dp[j+1][k][1]+dis(j,k));
			dp[j][k][1]=min(dp[j][k-1][0]+dis(j,k),dp[j][k-1][1]+dis(k-1,k));
		}
		for(int j=0;j<v.size();j++)for(int k=j;k<v.size();k++)if(min(dp[j][k][0],dp[j][k][1])<=t)ans=max(ans,k-j+1);
	}
	cout<<ans;
	return 0;
}