#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

long long dp2[MAXN];
long long dp2v[MAXN];
long long dp1[MAXN] ;
long long dp1v[MAXN];
int n;
vector<int> adj[MAXN];
int val[MAXN];

void dfs(int v, int p){
        for(auto u : adj[v]) if(u != p) dfs(u, v);
        dp1[v] = dp1v[v] = dp2[v] = dp2v[v] = 0;
        vector<int> children;
        for(auto u : adj[v]) if(u != p) children.push_back(u);
        if(children.size() == 0){
            dp2[v] = dp2v[v] = dp1[v] = dp1v[v] = val[v];
            return;
        }
        if(children.size() == 1){
            dp1v[v] = dp1v[children[0]]+val[v];
            dp1[v] = max(dp1v[v], dp1[children[0]]);
            dp2v[v] = max(dp1v[v], dp2v[children[0]]+val[v]);
            dp2[v] = max(dp2v[v], dp2[children[0]]);
            return;
        }
        vector<pair<long long, int>> max1v;
        vector<pair<long long, int>> max1;
        vector<pair<long long, int>> max2v;
        vector<pair<long long, int>> max2;
        for(auto u : children){
            max1v.push_back({dp1v[u], u});
            max1.push_back({dp1[u], u});
            max2v.push_back({dp2v[u], u});
            max2.push_back({dp2[u], u});
        }
        sort(max1v.rbegin(), max1v.rend());
        sort(max1.rbegin(), max1.rend());
        sort(max2v.rbegin(), max2v.rend());
        sort(max2.rbegin(), max2.rend());
        dp1v[v] = max1v[0].first+val[v];
        dp1[v] = dp1v[v];
        dp1[v] = max(dp1[v], max1[0].first);
        dp1[v] = max(dp1[v], max1v[0].first+max1v[1].first+val[v]);
        dp2v[v] = dp1v[v];
        dp2v[v] = max(dp2v[v], max1[0].first+val[v]);
        dp2v[v] = max(dp2v[v], max2v[0].first+val[v]);
        if(max1v[0].second == max1[0].second){
            dp2v[v] = max({dp2v[v], max1v[0].first+max1[1].first+val[v]});
            dp2v[v] = max({dp2v[v], max1v[1].first+max1[0].first+val[v]});
        }
        else dp2v[v] = max(dp2v[v], max1v[0].first+max1[0].first+val[v]);
        dp2[v] = dp2v[v];
        dp2[v] = max(dp2[v], max2[0].first);
        dp2[v] = max(dp2[v], max1[0].first+ max1[1].first);
        if(max2v[0].second == max1v[0].second){
            dp2[v] = max(dp2[v], max2v[0].first+max1v[1].first+val[v]);
            dp2[v] = max(dp2[v], max2v[1].first+max1v[0].first+val[v]);
        }
        else dp2[v] = max(dp2[v], max2v[0].first+max1v[0].first+val[v]);
        for(auto u : max1){
            int cur = 2;
            long long ans = u.first+val[v];
            int index = 0;
            while(cur > 0 && index < max1v.size()){
                if(max1v[index].second != u.second){
                    ans += max1v[index].first;
                    cur--;
                }
                index++;
            }
            dp2[v] = max(dp2[v], ans);
        }

    }

int main(){
    ios_base::sync_with_stdio(false);
        cin.tie(0);
        cin >> n;
        for(int i = 0; i<n; i++) cin >> val[i];
        for(int i = 0; i<n-1; i++){
            int a, b; cin >> a >> b;
            --a; --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0, -1);
        cout << max({dp2[0], dp2v[0], dp1[0], dp1v[0]}) << endl;
}