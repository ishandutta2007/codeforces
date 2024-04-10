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
#include <time.h>
#include <queue>
#define int long long
using namespace std;
vector<vector<int> > data, money;
vector<int> xors;
vector<bool> used;
void dfs(int vertex, int x){
	used[vertex] = true;
	xors[vertex] = x;
	for (int i=0; i < data[vertex].size(); i++){
		int to = data[vertex][i];
		if (used[to]) continue;
		dfs(to, x^money[vertex][i]);
	}
}
int32_t main(){
	int n, m, ai, bi, ci;
	cin >> n >> m;
	for (int i=0; i < n; i++){
		xors.push_back(0);
		used.push_back(false);
		vector<int> h1, h2;
		data.push_back(h1);
		money.push_back(h2);
	}
	for (int i=0; i < m; i++){
        cin >> ai >> bi >> ci;
        data[ai-1].push_back(bi-1);
        data[bi-1].push_back(ai-1);
        money[ai-1].push_back(ci);
        money[bi-1].push_back(ci);
	}
	dfs(0, 0);
	int maxs[30];
	for (int i=0; i < 30; i++){
		maxs[i] = 0;
	}
	for (int i=0; i < n; i++){
		for (int j=0; j < data[i].size(); j++){
			int to = data[i][j];
			if (to < i) continue;
			int num = xors[i] ^ xors[to] ^ money[i][j];
			for (int k=29;k>=0; k--){
				int b_and = (1 << k) & num;
				if (maxs[k] == 0 && b_and != 0){
					maxs[k] = num;
					break;
				}
				num = min(num, num^maxs[k]);
			}
		}
	}
	int ans = xors[0] ^ xors[n-1];
	for (int i=29; i >= 0; i--){
		ans = min(ans, ans ^ maxs[i]);
	}
	cout << ans << endl;
	return 0;
}