#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#define int long long
using namespace std;
vector<vector<int> > data, ed;
int n, m, ai, bi;
vector<int> colours, answer;
vector<bool> used;
int dfs(int vertex, int edge){
	used[vertex] = true;
	int vn = 0;
	for (int i=0; i < data[vertex].size(); i++){
		int to = data[vertex][i];
		if (used[to]) continue;
		vn += dfs(to, ed[vertex][i]);
	}
	if (colours[vertex] == 1) vn++;
	if (vn % 2 == 0){
		return 0;
	}
	else{
		answer.push_back(edge);
		return 1;
	}
}
int32_t main(){
	cin >> n >> m;
	int z = 0;
	for (int i=0; i < n; i++){
		cin >> ai;
		used.push_back(false);
		colours.push_back(ai);
		if (ai == 1) z++;
		vector<int> help, h;
		data.push_back(help);
		ed.push_back(h);
	}
	for (int i=0; i < m; i++){
		cin >> ai >> bi;
		data[ai-1].push_back(bi-1);
		data[bi-1].push_back(ai-1);
		ed[ai-1].push_back(i);
		ed[bi-1].push_back(i);
	}
	if (z % 2 != 0){
		for (int i=0; i < n; i++){
			if (colours[i] == -1){
				z++;
				colours[i] = 1;
				break;
			}
		}
		if (z % 2 != 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	dfs(0, -1);
	cout << answer.size() << endl;
	for (int i=0; i < answer.size(); i++){
		cout << answer[i] + 1 << " ";
	}
    return 0;
}