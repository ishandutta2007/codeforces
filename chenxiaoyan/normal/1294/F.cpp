/*   ///




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define X first
#define Y second
const int inf=0x3f3f3f3f;
const int N=200000;
int n;
vector<int> nei[N+1],son[N+1];
pair<int,int> dp[N+1];
vector<pair<int,int> > Mx[N+1],mX[N+1];
pair<int,int> operator+(pair<int,int> x,int y){return mp(x.X+y,x.Y);}
void dfs(int x=1,int fa=0){
	dp[x]=mp(0,x);
	for(int i=0;i<nei[x].size();i++)if(nei[x][i]!=fa)son[x].pb(nei[x][i]),dfs(nei[x][i],x);
	Mx[x].resize(son[x].size()+1,mp(-inf,0));
	for(int i=1;i<=son[x].size();i++)Mx[x][i]=max(Mx[x][i-1],dp[son[x][i-1]]+1);
	mX[x].resize(son[x].size()+2,mp(-inf,0));
	for(int i=son[x].size();i;i--)mX[x][i]=max(mX[x][i+1],dp[son[x][i-1]]+1);
	dp[x]=max(dp[x],Mx[x][son[x].size()]);
//	printf("dp[%d]=(%d,%d)\n",x,dp[x].X,dp[x].Y);
}
pair<int,pair<int,pair<int,int> > > ans(0,mp(0,mp(0,0)));
void dfs0(int x=1,int fa=0){
	dp[x]=mp(0,x);
	Mx[x].resize(son[x].size()+1,mp(-inf,0));
	for(int i=1;i<=son[x].size();i++)Mx[x][i]=max(Mx[x][i-1],dp[son[x][i-1]]+1);
	mX[x].resize(son[x].size()+2,mp(-inf,0));
	for(int i=son[x].size();i;i--)mX[x][i]=max(mX[x][i+1],dp[son[x][i-1]]+1);
	dp[x]=max(dp[x],Mx[x][son[x].size()]);
	if(son[x].size()>=3){
		vector<pair<int,int> > v;
		for(int i=0;i<son[x].size();i++)v.pb(dp[son[x][i]]);
		sort(v.begin(),v.end(),greater<pair<int,int> >());
		ans=max(ans,mp(v[0].X+v[1].X+v[2].X+3,mp(v[0].Y,mp(v[1].Y,v[2].Y))));
	}
	for(int i=0;i<son[x].size();i++){
		int y=son[x][i];
		if(y==fa)continue;
		pair<int,int> cpy_x=dp[x],cpy_y=dp[y];
		dp[x]=max(mp(0,x),max(Mx[x][i],mX[x][i+2]));
		son[y].pb(x);
		dfs0(y,x);
		dp[y]=cpy_y;
		dp[x]=cpy_x;
		son[y].ppb();
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		nei[x].pb(y);nei[y].pb(x);
	}
	int mx=-inf;
	for(int i=1;i<=n;i++)mx=max(mx,int(nei[i].size()));
	if(mx==2){
		int a;
		vector<int> v;
		for(int i=1;i<=n;i++)
			if(nei[i].size()==2)a=i;
			else v.pb(i);
		return printf("%d\n%d %d %d",n-1,a,v[0],v[1]),0;
	}
	dfs();
	dfs0();
	printf("%d\n%d %d %d",ans.X,ans.Y.X,ans.Y.Y.X,ans.Y.Y.Y);
	return 0;
}
/*1
8
1 2
2 3
3 4
4 5
4 6
3 7
3 8
*/