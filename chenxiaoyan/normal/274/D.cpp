/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
const int N_TIMES_M=100000;
int n,m;
int now;
vector<int> nei[2*N_TIMES_M+1];
int ideg[2*N_TIMES_M+1];
vector<int> topo;
void toposort(){
	queue<int> q;
	for(int i=1;i<=now;i++)if(!ideg[i])q.push(i);
	while(q.size()){
		int x=q.front();
		q.pop();
		topo.pb(x);
		for(int i=0;i<nei[x].size();i++){
			int y=nei[x][i];
			if(!--ideg[y])q.push(y);
		}
	}
}
int main(){
	cin>>n>>m;
	vector<vector<pair<int,int> > > a(n+1,vector<pair<int,int> >(m+1));
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j].X,a[i][j].Y=j;
	now=m;
	for(int i=1;i<=n;i++){
		sort(a[i].begin()+1,a[i].end());
//		for(int j=1;j<=m;j++)printf("(%d,%d) ",a[i][j].X,a[i][j].Y);puts("");
		vector<pair<int,int> > rg;
		for(int j=1,je;j<=m;j=je+1){
			je=j;while(je+1<=m&&a[i][je+1].X==a[i][j].X)je++;
			rg.pb(mp(j,je));
		}
//		for(int j=0;j<rg.size();j++)printf("[%d,%d] ",rg[j].X,rg[j].Y);puts("");
		for(int j=0;j+1<rg.size();j++){
			int l1=rg[j].X,r1=rg[j].Y,l2=rg[j+1].X,r2=rg[j+1].Y;
			if(a[i][l1].X==-1)continue;
			now++;
			for(int k=l1;k<=r1;k++)nei[a[i][k].Y].pb(now),ideg[now]++;
			for(int k=l2;k<=r2;k++)nei[now].pb(a[i][k].Y),ideg[a[i][k].Y]++;
		}
	}
	toposort();
	if(topo.size()<now)puts("-1");
	else for(int i=0;i<topo.size();i++)if(topo[i]<=m)cout<<topo[i]<<" ";
	return 0;
}
/*1
2 2
1 2
2 1
*/