#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef pair<int, int> P;

int n, u, v;
vector<int> edge[216000];
int ts[216000];
void init(int x){
	ts[x] = !edge[x].size();
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i];
		init(to);
		ts[x] += ts[to];
	}
}

P dfs(int x, int dep = 0){
	int ma = 0, mi = 1 << 30, tm = 0;
	if(edge[x].size() == 0){
		return P(1, 1);
	}
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i];
		P tmp = dfs(to, !dep);
		if(dep == 0){//bigger
			ma = max(ma, ts[x] - ts[to] + tmp.first);
			tm += tmp.second;
		}
		else{//smaller
			tm += tmp.first;
			mi = min(mi, tmp.second);
		}
	}
	if(dep == 0)mi = tm;
	else ma = tm - edge[x].size() + 1;
	
	return P(ma, mi);
	
}

int main(){
	cin >> n;
	for(int i = 0;i < n-1;i++){
		cin >> u >> v;
		edge[u].push_back(v);
	}
	init(1);
	P tmp = dfs(1);
	cout << tmp.first << " " << tmp.second << endl;
	return 0;
}