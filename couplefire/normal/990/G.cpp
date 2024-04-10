#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

map<int, int> nums;
int n;
int arr[MAXN];
int siz[MAXN];
long long ans[MAXN] = {0};
vector<int> adj[MAXN];

void getSize(int v, int p){
    siz[v] = 1;
    for(auto u : adj[v]){
        if(u == p) continue;
        getSize(u, v);
        siz[v] += siz[u];
    }
}

void dfs2(int v, int p, int cur, map<int, int>& mp){
    if(cur == 1){
        mp[1] += siz[v];
        return;
    }
    cur = __gcd(cur, arr[v]);
    mp[cur]++;
    for(auto u : adj[v]){
        if(u==p) continue;
        dfs2(u, v, cur, mp);
    }
}

void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : adj[v]){
        if(u != p && siz[u] > mx){
            mx = siz[u];
            bigChild = u;
        }
    }
    for(auto u : adj[v]){
        if(u != p && u != bigChild) dfs(u, v, 0);
    }
    if(bigChild != -1) dfs(bigChild, v, 1);
    map<int, int> mp;
    for(auto u : adj[v]){
        if(u != p && u != bigChild){
            map<int, int> tmp;
            dfs2(u, v, arr[v], tmp);
            // cout << u+1 << " " << arr[v] << ":" << endl; 
            for(auto x : tmp){
                // cout << x.first << " " << x.second << endl;
                ans[x.first] += x.second;
                for(auto y:mp){
                    ans[__gcd(x.first, y.first)] += 1ll*x.second*y.second;
                }
            }
            // cout << endl;
            for(auto x : tmp){
                mp[x.first] += x.second;
            }
        }
    }
    for(auto x : nums){
        pair<int, int> p;
        p.first = __gcd(x.first, arr[v]);
        p.second = x.second;
        ans[p.first] += p.second;
        for(auto y : mp){
            ans[__gcd(y.first, p.first)] += 1ll*p.second*y.second;
        }
    }
    ans[arr[v]]++;
    if(keep){
        for(auto x: nums){
            mp[__gcd(x.first, arr[v])] += x.second;
        }
        nums = mp;
        nums[arr[v]]++;
        // cout << v+1 << ":" << endl;
        // for(auto x : nums){
        //     cout << x.first << " " << x.second << endl;
        // }
        // cout << endl;
    }
    else nums.clear();
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++) cin >> arr[i];
    for(int i = 0; i<n-1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    getSize(0, -1);
    dfs(0, -1, 1);
    // cout << endl;
    for(int i = 1; i<=200000; i++){
        if(ans[i] != 0){
            cout << i << " " << ans[i] << endl;
        }
    }
}