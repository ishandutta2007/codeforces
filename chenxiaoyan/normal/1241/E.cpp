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
int n,m;
const int N=500000;
vector<pair<int,int> > nei[N+1];
int f[N+1][2];
bool vis[N+1][2];
bool cmp(pair<int,int> x,pair<int,int> y){return x.X-x.Y>y.X-y.Y;}
int dp(int x=1,bool c=false,int fa=0){
	if(vis[x][c])return f[x][c];
	vis[x][c]=true;
	vector<pair<int,int> > v;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i].X,len=nei[x][i].Y;
		if(y==fa)continue;
		v.pb(mp(dp(y,true,x)+len,dp(y,false,x)));
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++)
		if(i>=m-c||v[i].Y>v[i].X)f[x][c]+=v[i].Y;
		else f[x][c]+=v[i].X;
//	printf("f[%lld][%d]=%lld\n",x,c,f[x][c]); 
	return f[x][c];
}
void mian(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)nei[i].clear();
	for(int i=1;i<n;i++){
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		nei[x].pb(mp(y,z));nei[y].pb(mp(x,z));
	}
	for(int i=1;i<=n;i++)vis[i][0]=vis[i][1]=f[i][0]=f[i][1]=0;
	cout<<dp()<<"\n";
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
/*1
1
9 3
7 4 10
6 8 1
1 3 6
2 4 10
2 9 1
5 4 9
3 6 5
1 2 5
*/