/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int N=5000;
int n,m,n1,n2,n3;
vector<int> nei[N+1];
int cnt0,cnt1;
int col[N+1];
vector<int> cc;
void dfs(int x,int now=1){
	cc.pb(x);
	col[x]=now;
	cnt0++;cnt1+=now==2;
	for(int i=0;i<nei[x].size();i++){
		int y=nei[x][i];
		if(!col[y])dfs(y,3-now);
		else if(col[y]==now)puts("NO"),exit(0);
	}
}
vector<pair<int,int> > v;
vector<vector<int> > ccs;
bool dp[N+1][N+1];
bool pa[N+1][N+1];
int main(){
	cin>>n>>m>>n1>>n2>>n3;
	while(m--){
		int x,y;
		cin>>x>>y;
		nei[x].pb(y);nei[y].pb(x);
	}
	for(int i=1;i<=n;i++)if(!col[i])cc.clear(),cnt0=cnt1=0,dfs(i),v.pb(mp(cnt1,cnt0)),ccs.pb(cc);
//	cout<<ccs.size()<<"\n";
//	for(int i=0;i<ccs.size();i++)printf("%d %d\n",v[i].X,v[i].Y);
	dp[0][0]=true;
	for(int i=0;i<ccs.size();i++)for(int j=0;j<=n;j++){
		if(j>=v[i].X&&dp[i][j-v[i].X])dp[i+1][j]=true;
		else if(j>=v[i].Y-v[i].X&&dp[i][j-(v[i].Y-v[i].X)])dp[i+1][j]=true,pa[i+1][j]=true;
//		cout<<i+1<<" "<<j<<" "<<dp[i+1][j]<<"\n";
	}
	if(!dp[ccs.size()][n2])return puts("NO"),0;
	puts("YES");
	for(int i=ccs.size();i;i--){
		if(!pa[i][n2])n2-=v[i-1].X;
		else{
			n2-=v[i-1].Y-v[i-1].X;
			for(int j=0;j<ccs[i-1].size();j++)col[ccs[i-1][j]]=3-col[ccs[i-1][j]];
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(col[i]==2)putchar('2');
		else if(cnt<n1)cnt++,putchar('1');
		else putchar('3');
	return 0;
}