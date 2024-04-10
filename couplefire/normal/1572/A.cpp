#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

template<int SZ> struct TopoSort {
	int N, in[SZ];
	vector<int> res, adj[SZ];
	void ae(int x, int y) { adj[x].push_back(y), in[y] ++; }
	bool sort(int _N) {
		N = _N; queue<int> todo;
		for(int i=0;i<N;i++) if (!in[i]) todo.push(i);
		while (todo.size()) {
			int x = todo.front(); todo.pop(); res.push_back(x);
			for(auto i:adj[x]) if (!(--in[i])) todo.push(i);
		}
		return res.size() == N;
	}
};


void solve(){
    int n; cin >> n;
    vector<vector<int>> adj(n), radj(n);
    vector<int> in(n, 0), res;
    for(int i = 0; i<n; ++i){
        int k; cin >> k;
        for(int j = 0; j<k; ++j){
            int a; cin >> a; --a;
            adj[a].push_back(i);
            radj[i].push_back(a);
            ++in[i];
        }
    }
    queue<int> todo;
    for(int i = 0; i<n; ++i)
        if(!in[i]) todo.push(i);
    while (todo.size()) {
        int x = todo.front(); todo.pop(); res.push_back(x);
        for(auto i:adj[x]) if (!(--in[i])) todo.push(i);
    }
    if((int)res.size()!=n){
        cout << -1 << '\n';
        return;
    }
    vector<int> dp(n);
    int ans = 0;
    for(int _ = 0; _<n; ++_){
        int i = res[_];
        int best = -1;
        for(auto x : radj[i])
            best = max(best, dp[x]);
        int mx = -1;
        for(auto x : radj[i])
            if(dp[x]==best) mx = max(mx, x);
        if(mx==-1) dp[i] = 1;
        else if(i>mx) dp[i] = best;
        else dp[i] = best+1;
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
}