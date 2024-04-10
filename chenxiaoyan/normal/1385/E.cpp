#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int N=200000;
int n,m;
vector<pair<int,int> > nei[N+1];
int ideg[N+1];
vector<int> topo;
int id[N+1];
void toposort(){// 
	topo.clear();
	queue<int> q;
	for(int i=1;i<=n;i++)if(!ideg[i])q.push(i);
	while(q.size()){
		int x=q.front();
		q.pop();
		topo.pb(x);
		for(int i=0;i<nei[x].size();i++){
			int y=nei[x][i].X,z=nei[x][i].Y;
			if(z)/**/if(!--ideg[y])q.push(y);
		}
	}
}
void mian(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)ideg[i]=0,nei[i].clear();
	while(m--){
		int x,y,z;
		scanf("%d%d%d",&z,&x,&y);
		if(z)nei[x].pb(mp(y,z)),ideg[y]++;
		else nei[x].pb(mp(y,z)),nei[y].pb(mp(x,z));
	}
	toposort();
	if(topo.size()!=n)return puts("NO"),void();// 
	puts("YES");
	for(int i=0;i<n;i++)id[topo[i]]=i;
	for(int i=1;i<=n;i++)for(int j=0;j<nei[i].size();j++){
		int x=nei[i][j].X,y=nei[i][j].Y;
		if(y)printf("%d %d\n",i,x);
		else if(id[i]<id[x])printf("%d %d\n",i,x);// 
	}
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}