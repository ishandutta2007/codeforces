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
#include <queue>
#include <ctime>
#define int long long
using namespace std;
int n, m;
vector<vector<int> > data;
vector<int> euler, where, depth, logs;
int table[900000][22];
void dfs(int vertex, int d){
    where[vertex] = euler.size();
    euler.push_back(vertex);
    depth[vertex] = d;
    for (int i=0; i < (int) data[vertex].size(); i++){
        int to = data[vertex][i];
        dfs(to, d + 1);
        euler.push_back(vertex);
    }
}
int Get(int f, int s){
	int first = where[f];
	int second = where[s];
	if (first > second) swap(first, second);
	int dist = second - first + 1;
	int first_cand = table[first][logs[dist]];
	int second_cand = table[second + 1 - (1 << logs[dist])][logs[dist]];
	int ans;
	if (depth[first_cand] < depth[second_cand]) ans = first_cand;
	else ans = second_cand;
	return abs(depth[f] - depth[ans]) + abs(depth[s] - depth[ans]);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i < n+1; i++){
        vector<int> help;
        data.push_back(help);
        where.push_back(-1);
        depth.push_back(-1);
    }
    int x;
    for (int i=0; i < n; i++){
        cin >> x;
        data[x-1].push_back(i+1);
    }
    dfs(0, 0);
    int sz = euler.size();
    for (int i=0; i < sz; i++){
        table[i][0] = euler[i];
    }
    int counter = 1;
    int start_log = 1;
    logs.push_back(0);
    for (int i=2; i <= 2e6; i*=2){
        for (int j=0; j + i <= sz; j++){
            int fv = table[j][counter - 1];
            int sv = table[j + i/2][counter-1];
            if (depth[fv] <= depth[sv]) table[j][counter] = fv;
            else table[j][counter] = sv;
        }
        for (int j=start_log; j <= i; j++){
            logs.push_back(counter - 1);
        }
        start_log = i + 1;
        counter += 1;
    }
    int d1[n+1], d2[n+1], ds[n+1];
    d1[0] = 0;
    d2[0] = 0;
    ds[0] = 0;
    int diameter = 0;
    for (int i=1; i <= n; i++){
		int new_vertex = i;
		int dia1 = Get(new_vertex, d1[i-1]);
		int dia2 = Get(new_vertex, d2[i-1]);
		if (diameter >= dia1 && diameter >= dia2){
			d1[i] = d1[i-1];
			d2[i] = d2[i-1];
		}
		else if (dia1 >= dia2){
			d1[i] = d1[i-1];
			d2[i] = new_vertex;
			diameter = dia1;
		}
		else{
			d1[i] = new_vertex;
			d2[i] = d2[i-1];
			diameter = dia2;
		}
		ds[i] = diameter;
    }
    vector<pair<int, int> > events;
    for (int i=0; i <= n; i++){
		int left = max((int) 0, i-1);
        int right = n+1;
        while (right - left > 1){
			int mid = (left + right) / 2;
            int ds1 = Get(i, d1[mid]);
            int ds2 = Get(i, d2[mid]);
            if (max(ds1, ds2) == ds[mid]) left = mid;
            else right = mid;
        }
        events.push_back(make_pair(i, 0));
        events.push_back(make_pair(right, 1));
    }
    sort(events.begin(), events.end());
    int u = 1;
    int op = 0;
    int event = 0;
    while (u <= n){
        while (event < events.size() && events[event].first <= u){
			if (events[event].second == 1) op--;
			else op++;
			event++;
        }
        cout << op << endl;
        u++;
    }
    return 0;
}