#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> edge[108000], ans;
int n, a, b;
int x[108000], y[108000], val[108000];
int parent[108000];
void init(int x, int last = 0){
	parent[x] = last;
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i];
		if(to == last)continue;
		init(to, x);
	}
}

int main(){
	cin >> n;
	for(int i = 0;i < n - 1;i++){
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	edge[0].push_back(1);
	init(0);
	for(int i = 1;i <= n;i++)cin >> x[i];
	for(int i = 1;i <= n;i++)cin >> y[i];
	for(int i = 1;i <= n;i++)val[i] = (x[i] != y[i]);
	for(int i = 1;i <= n;i++){
		if(val[i] != val[parent[parent[i]]]){
			ans.push_back(i);
		}
	}	
	cout << ans.size() << endl;
	for(int i = 0;i < ans.size();i++){
		cout << ans[i] << endl;
	}
	return 0;
}