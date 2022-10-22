#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> nei[301],ans;
set<int> con[301];
queue<int> q;
void init(int v,int p){
	if(v!=1)nei[v].erase(find(nei[v].begin(),nei[v].end(),p));
	for(int i=0;i<nei[v].size();i++){
		int u=nei[v][i];
		init(u,v);
		for(set<int>::iterator itr=con[u].begin();itr!=con[u].end();itr++)
			con[v].insert(*itr);
	}
	if(nei[v].empty())con[v].insert(v);
}
void dfs(int v){
	bool taken[301]={};
	if(v==q.front())q.pop();
	ans.push_back(v);
	while(q.size()){
		int i,u;
		for(i=0;i<nei[v].size();i++)if(!taken[i]){
			u=nei[v][i];
			if(con[u].find(q.front())!=con[u].end())break;
		}
		if(i<nei[v].size()){
			dfs(u);
			taken[i]=true;ans.push_back(v);
		}
		else break;
	}
}
int/********/ main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		nei[a].push_back(b);nei[b].push_back(a);
	}
	int x;
	while(cin>>x)q.push(x);
	init(1,0);dfs(1);
	if(ans.size()<(n<<1)-1)cout<<-1;
	else for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
	return 0;
}
/*1
3
1 2
2 3
3
*/
/*2
6
1 2
1 3
2 4
4 5
4 6
5 6 3
*/
/*3
6
1 2
1 3
2 4
4 5
4 6
5 3 6
*/