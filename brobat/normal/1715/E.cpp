#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: stress-tested
 */
// #pragma once
#define ll long long

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int dp[100100][21];
const int INF = (int)1E18;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, kk;
    cin >> n >> m >> kk;
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        --x; --y;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= kk; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int k = 0; k <= kk; k++) {
        // first do Dijkstra on k flights done.
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < n; i++) {
            if(dp[i][k] < INF) {
                pq.push({-dp[i][k], i});
            }
        }
        while(!pq.empty()) {
            int curr = pq.top().second;
            int curr_dist = -pq.top().first;
            pq.pop();
            if(curr_dist > dp[curr][k]) continue;
            for(auto nx : adj[curr]) {
                if(curr_dist + nx.second < dp[nx.first][k]) {
                    dp[nx.first][k] = curr_dist + nx.second;
                    pq.push({-dp[nx.first][k], nx.first});
                }
            }
        }
        if(k == kk) break;
        LineContainer lc;
        for(int i = 0; i < n; i++) {
            lc.add(2*i, -dp[i][k] - i*i);
        }
        for(int i = 0; i < n; i++) {
            dp[i][k + 1] = -lc.query(i) + i*i;
        }
    }
    for(int i = 0; i < n; i++) {
        int ans = INF;
        for(int j = 0; j <= kk; j++) {
            ans = min(ans, dp[i][j]);
        }
        cout << ans << ' ';
    }
    
    return 0;
}