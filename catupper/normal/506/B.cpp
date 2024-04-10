#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define plus __plus
vector<int> edge[108000];
vector<int> redge[108000];

vector<int> nodes;
int group[108000];
bool come[108000];
bool plus[108000];
int cnt[108000];
int u[108000];
int n, m, x, y, res;

int r(int x){
	if(u[x] == x)return x;
	return u[x] = r(u[x]);
}

void unite(int a, int b){
	a = r(a);
	b = r(b);
	u[a] = b;
}


void dfs(int x){
	if(come[x])return;
	come[x] = true;
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i];
		dfs(to);
	}
	nodes.push_back(x);
}

void rdfs(int x){
	come[x] = true;
	for(int i = 0;i < redge[x].size();i++){
		int to = redge[x][i];
		if(come[to])continue;
		unite(to, x);
		rdfs(to);
	}
}

int main(){
	cin >> n >> m;
	res = 0;
	for(int i = 0;i < m;i++){
		cin >> x >> y;x--,y--;
		edge[x].push_back(y);
		redge[y].push_back(x);
	}
	for(int i = 0;i < 108000;i++)u[i] = i;
	for(int i = 0;i < n;i++){
		dfs(i);
	}                    
	fill(come, come + 108000, false);
	for(int i = n - 1;i >= 0;i--){
		if(!come[nodes[i]])rdfs(nodes[i]);
	}
	for(int i = 0;i < n;i++){
		group[i] = r(i);
		cnt[r(i)]++;
	}
	for(int i = 0;i < 108000;i++)u[i] = i;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < edge[i].size();j++){
			if(r(edge[i][j]) != r(i))res++;
			unite(edge[i][j], i);
		}
	}
	for(int i = 0;i < n;i++){
		if(cnt[group[i]] > 1){
			plus[r(i)] = true;
		}
	}
	for(int i = 0;i < n;i++)res += plus[i];
	cout << res << endl;
	
	return 0;
}