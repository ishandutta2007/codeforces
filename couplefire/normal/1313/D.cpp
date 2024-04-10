#include <bits/stdc++.h>
using namespace std;

const int N = 100100;

inline int ckmax(int &a, int b){return a<b?a=b:a;}

struct node{vector<int> idx; int w;};

int n, m, k, pt = 1, dp[N<<1][256], mp[N], ans;
map<int, vector<int>> in, out;
vector<int> eve, curidx;
vector<node> arr;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i = 0; i<n; ++i){
        int l, r; cin >> l >> r; ++r;
        in[l].push_back(i);
        out[r].push_back(i);
        eve.push_back(l); eve.push_back(r);
    }
    sort(eve.begin(), eve.end());
    eve.erase(unique(eve.begin(), eve.end()), eve.end());
    for(auto t : eve){
        vector<int> a = in[t], b = out[t];
        for(auto x : b){
            arr.push_back({curidx, t-pt});
            curidx.erase(find(curidx.begin(), curidx.end(), x)); pt = t;
        }
        for(auto x : a){
            arr.push_back({curidx, t-pt});
            curidx.push_back(x); pt = t;
        }
    }
    for(int i = 0; i<(int)arr.size()-1; ++i){
        bool isIn = 0; int badidx;
        for(int j = 0; j<arr[i+1].idx.size(); ++j){
            mp[arr[i+1].idx[j]] = j;
            if(find(arr[i].idx.begin(), arr[i].idx.end(), arr[i+1].idx[j])==arr[i].idx.end())
                isIn = 1, badidx = j;
        }
        if(!isIn)
            for(int j = 0; j<arr[i].idx.size(); ++j)
                if(find(arr[i+1].idx.begin(), arr[i+1].idx.end(), arr[i].idx[j])==arr[i+1].idx.end())
                    badidx = j;
        for(int mask = 0; mask<(1<<arr[i].idx.size()); ++mask){
            int nmask = 0; if(!isIn && (mask&(1<<badidx))) nmask ^= 1<<mp[arr[i].idx[badidx]];
            for(int j = 0; j<arr[i].idx.size(); ++j)
                if(mask&(1<<j)) nmask ^= 1<<mp[arr[i].idx[j]];
            int cnt = __builtin_popcount(nmask);
            if(isIn)
                ckmax(dp[i+1][nmask], dp[i][mask]+(cnt&1)*arr[i+1].w),
                ckmax(dp[i+1][nmask^(1<<badidx)], dp[i][mask]+((cnt^1)&1)*arr[i+1].w);
            else
                ckmax(dp[i+1][nmask], dp[i][mask]+(cnt&1)*arr[i+1].w);
        }
    }
    for(int mask = 0; mask<(1<<arr.back().idx.size()); ++mask)
        ans = max(ans, dp[(int)arr.size()-1][mask]);
    cout << ans << '\n';
}