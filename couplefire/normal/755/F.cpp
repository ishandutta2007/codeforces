#include <bits/stdc++.h>
using namespace std;

int siz = 0;
bool visited[1000005] = {0};
int to[1000005];
vector<int> cycles;
int occ[1000005] = {0};
vector<pair<int, int>> occur;
int n, k;
bitset<1000005> dp;
void dfs(int v){
    if(visited[v]) return;
    siz++;
    visited[v] = 1;
    dfs(to[v]);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i<n; i++) cin >> to[i+1];
    for(int i = 1; i<=n; i++){
        if(visited[i]) continue;
        dfs(i);
        cycles.push_back(siz);
        siz = 0;
    }
    for(auto i : cycles){
        occ[i]++;
    }
    for(int i = 2; i<=n; i++) if(occ[i] > 0) occur.push_back({i,occ[i]});
    dp = 1;
    for(int i = 0; i<occur.size(); i++){
        for(int x = 0; (1<<x) <= occur[i].second; x++){
            dp |= (dp << (occur[i].first*(1<<x)));
            occur[i].second -= (1<<x);
        }
        dp |= (dp << (occur[i].first*occur[i].second));
    }
    if(dp[k]){
        cout << k << " ";
    }
    else cout << k+1 << " ";
    int ans = 0;
    for(auto i : cycles){
        int j = i;
        while(j > 1 && k > 0){
            ans += 2;
            j -= 2;
            k--;
        }
        if(!k){
            cout << ans << endl;
            exit(0);
        }
    }

    cout << min(n, ans+k) << endl;
    
}