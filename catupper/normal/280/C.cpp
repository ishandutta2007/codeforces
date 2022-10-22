#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int a, b, n;
vector<int> edge[105000];

void make_edge(int a, int b){
    edge[a].push_back(b);
    edge[b].push_back(a);
}

double dfs(int x, int last = -1, int d = 1){
    double res = 1.0 / d;
    for(int i = 0;i < edge[x].size();i++){
	if(edge[x][i] == last)continue;
	res += dfs(edge[x][i], x, d + 1);
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 0;i < n - 1;i++){
	cin >> a >> b;
	make_edge(a, b);
    }
    printf("%.9f\n", dfs(1));
    return 0;
}