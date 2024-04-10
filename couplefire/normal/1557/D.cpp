#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, m, dp[N], prv[N];
vector<int> events, trans[N];
map<int, vector<int>> in, out;
map<int, int> cnt;
set<int> cur;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i<m; ++i){
        int id, l, r; cin >> id >> l >> r;
        events.push_back(l); events.push_back(r+1);
        in[l].push_back(id);
        out[r+1].push_back(id);
    }
    sort(events.begin(), events.end());
    events.erase(unique(events.begin(), events.end()), events.end());
    for(auto x : events){
        for(auto y : out[x]){
            --cnt[y]; if(cnt[y]) continue;
            cur.erase(y);
            auto it = cur.lower_bound(y);
            if(it != cur.end() && it != cur.begin())
                trans[*it].push_back(*prev(it));
        }
        for(auto y : in[x]){
            ++cnt[y]; if(cnt[y]>1) continue;
            cur.insert(y);
            auto it = cur.lower_bound(y);
            if(next(it) != cur.end())
                trans[*next(it)].push_back(*it);
            if(it != cur.begin())
                trans[*it].push_back(*prev(it));
        }
    }
    for(int i = 1; i<=n; ++i){
        dp[i] = i-1; prv[i] = 0;
        for(auto id : trans[i])
            if(dp[id]+i-id-1 < dp[i])
                dp[i] = dp[id]+i-id-1, prv[i] = id;
    }
    int minval = N, id = 0;
    for(int i = 1; i<=n; ++i)
        if(dp[i]+n-i<minval)
            minval = dp[i]+n-i, id = i;
    vector<int> ans;
    for(int i = id+1; i<=n; ++i)
        ans.push_back(i);
    while(id){
        for(int i = id-1; i>prv[id]; --i)
            ans.push_back(i);
        id = prv[id];
    }
    cout << ans.size() << '\n';
    for(auto x : ans)
        cout << x << ' ';
}