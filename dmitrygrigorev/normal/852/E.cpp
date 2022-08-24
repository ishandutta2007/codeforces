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
#include <deque>
#define int long long
using namespace std;
int n, ai, bi;
vector<vector<int> > data;
int dp[100000];
int MOD = 1000000007;
int answer;
int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
void create(int vertex, int last){
    bool can = false;
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to == last) continue;
        create(to, vertex);
        dp[vertex] *= dp[to];
        dp[vertex] %= MOD;
        can = true;
    }
    if (!can) return;
    dp[vertex] *= 2;
    dp[vertex] %= MOD;
}
void dfs(int vertex, int last){
    answer += dp[vertex];
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to == last) continue;
        int oldv = dp[vertex];
        int oldt = dp[to];
        int x, y;
        int cf = 1;
        if (data[vertex].size() == 1) cf *= 2;
        gcd(cf*oldt, MOD, x, y);
        dp[vertex] = dp[vertex] * x;
        dp[vertex] %= MOD;
        dp[to] *= dp[vertex];
        if (data[to].size() == 1) dp[to] *= 2;
        dp[to] %= MOD;
        dfs(to, vertex);
        dp[vertex] = oldv;
        dp[to] = oldt;
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=0; i < n; i++){
        vector<int> help;
        data.push_back(help);
        dp[i] = 1;
    }
    for (int i=0; i < n-1; i++){
        cin >> ai >> bi;
        data[ai-1].push_back(bi-1);
        data[bi-1].push_back(ai-1);
    }
    create(0, -1);
    answer = 0;
    dfs(0, -1);
    answer %= MOD;
    if (answer < 0) answer += MOD;
    cout << answer << endl;
    return 0;
}