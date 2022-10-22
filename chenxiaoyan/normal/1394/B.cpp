/*





D P 




 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define Y second
#define X first
#define pb push_back
#define ppb pop_back
const int N=200000;
int n,m,k;
vector<pair<int,int> > nei[N+1];
vector<int> buc[10];
bitset<N+1> bs[10][10];
bool ok[10][10][10][10];
bool fuck[10][10];
vector<int> now;
int ans=0;
void dfs(int x=1){
	if(x==k+1){
		for(int i=0;i<k;i++)if(fuck[i+1][now[i]])return;
		for(int i=0;i<k;i++)for(int j=i+1;j<k;j++)if(!ok[i+1][now[i]][j+1][now[j]])return;
		ans++;
		return;
	}
	for(int i=1;i<=x;i++){
		now.pb(i);
		dfs(x+1);
		now.ppb();
	}
}
int main(){
	cin>>n>>m>>k;
	while(m--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		nei[x].pb(mp(z,y));
	}
	for(int i=1;i<=n;i++)sort(nei[i].begin(),nei[i].end());
	for(int i=1;i<=n;i++)buc[nei[i].size()].pb(i);
	for(int i=1;i<=k;i++){
		for(int j=0;j<buc[i].size();j++)for(int o=1;o<=i;o++){
			if(bs[i][o][nei[buc[i][j]][o-1].Y])fuck[i][o]=true;
			bs[i][o].set(nei[buc[i][j]][o-1].Y);
		}
//		for(int o=1;o<=i;o++){for(int p=1;p<=n;p++)cout<<bs[i][o][p];cout<<" ";}puts("");
	}
	for(int i=1;i<=k;i++)for(int j=1;j<=i;j++)for(int o=i+1;o<=k;o++)for(int p=1;p<=o;p++)
		ok[i][j][o][p]=!fuck[i][j]&&!fuck[o][p]&&(bs[i][j]&bs[o][p]).none();
//	for(int i=1;i<=k;i++)for(int j=1;j<=i;j++)for(int o=i+1;o<=k;o++)for(int p=1;p<=o;p++)printf("ok[%d][%d][%d][%d]=%d\n",i,j,o,p,ok[i][j][o][p]);
	dfs();
	cout<<ans;
	return 0;
}