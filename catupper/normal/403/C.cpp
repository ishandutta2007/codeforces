#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool come[2100];
int stop[2100];
vector<int> edge[2100], redge[2100];
void dfs(vector<int> *edge, int x, int last = -1){
	if(come[x])return;
	come[x] = true;
	for(int i = 0;i < edge[x].size();i++){
		dfs(edge, edge[x][i], x);
	}
}

int main(){
	int n, a;
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			scanf("%d", &a);
			if(a)edge[i].push_back(j), redge[j].push_back(i);
		}
	}
	fill(come, come + n, false);
	dfs(edge, 0);
	for(int i = 0;i < n;i++){
		if(!come[i]){
			cout << "NO" << endl;
			return 0;
		}
	}	
	fill(come, come + n, false);
	dfs(redge, 0);
	for(int i = 0;i < n;i++){
		if(!come[i]){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}