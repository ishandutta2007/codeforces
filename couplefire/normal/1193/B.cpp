#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

int n, m, k;
vector<int> cld[MAXN];
pair<int, int> fruits[MAXN];
int siz[MAXN];

void getSiz(int v){
    siz[v] = 1;
    for(auto u : cld[v]){
        getSiz(u);
        siz[v] += siz[u];
    }
}

void dfs(int v, map<int, long long>& mp){
    int mx = -1, bigChild = -1;
    for(auto u : cld[v]){
        if(siz[u] > mx) mx = siz[u], bigChild = u;
    }
    if(bigChild != -1){
        dfs(bigChild, mp);
    }
    for(auto u : cld[v]){
        if(u != bigChild){
            map<int, long long> tmp;
            dfs(u, tmp);
            for(auto p : tmp) mp[p.first] += p.second;
        }
    }
    if(fruits[v].first != -1){
        int d = fruits[v].first, w = fruits[v].second;
        long long cur = 0;
        auto it = mp.lower_bound(d+1);
        while(it != mp.end()){
            long long ww = (*it).second;
            int dd = (*it).first;
            cur += ww;
            mp.erase(it);
            if(cur > w){
                mp[dd] = cur-w;
                break;
            }
            it = mp.lower_bound(d+1);
        }
        mp[d] += w;
    }
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i<n; i++){
        int p; cin >> p; --p;
        cld[p].push_back(i);
    }
    for(int i = 0; i<n; i++) fruits[i] = {-1, -1};
    for(int i = 0; i<m; i++){
        int v, d, w; cin >> v >> d >> w;
        --v;
        fruits[v] = {d, w};
    }
    getSiz(0);
    map<int, long long> mp;
    dfs(0, mp);
    long long ans = 0;
    for(auto p : mp) ans += p.second;
    cout << ans << endl;
}