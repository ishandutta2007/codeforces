#include <bits/stdc++.h>
using namespace std;
#define MAXN 1505

int n, m;
vector<int> arr[MAXN];
vector<int> brr[MAXN];
int prefix[MAXN][MAXN];
int cnt[MAXN];
vector<int> ans;

void check(){
    vector<pair<int, int>> ranges;
    ranges.push_back({0, n-1});
    vector<bool> visited(m, 0);
    for(int i = 0; i<m; i++) cnt[i] = prefix[n-1][i]-prefix[0][i];
    while(!ranges.empty()){
        bool found = false;
        for(int j = 0; j<m; j++){
            if(visited[j]) continue;
            bool work = (cnt[j]==0);
            if(!work) continue;
            visited[j] = 1;
            ans.push_back(j);
            // cout << j << endl;
            found = 1;
            vector<pair<int, int>> tmp;
            for(auto &x : ranges){
                int orig = tmp.size();
                for(int i = x.first; i<=x.second; ){
                    int id = i;
                    while(i <= x.second && brr[i][j] == brr[id][j]) ++i;
                    if(id != i-1) tmp.push_back({id, i-1});
                }
                if(!tmp.empty() && tmp.back() == x) continue;
                for(int k = 0; k<m; k++) cnt[k] -= prefix[x.second][k]-prefix[x.first][k];
                for(int i = orig; i<(int)tmp.size(); i++){
                    for(int k = 0; k<m; k++) cnt[k] += prefix[tmp[i].second][k]-prefix[tmp[i].first][k];
                }
            }
            ranges = tmp;
            break;
        }
        if(!found) break;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        arr[i].resize(m);
        for(int j = 0; j<m; j++) cin >> arr[i][j];
    }
    for(int i = 0; i<n; i++){
        brr[i].resize(m);
        for(int j = 0; j<m; j++) cin >> brr[i][j];
    }
    for(int j = 0; j<m; j++){
        for(int i = 1; i<n; i++) prefix[i][j] = prefix[i-1][j]+(brr[i][j]<brr[i-1][j]);
    }
    check();
    reverse(ans.begin(), ans.end());
    vector<int> bruh(n);
    for(int i = 0; i<n; i++) bruh[i] = i;
    for(auto x : ans){
        stable_sort(bruh.begin(), bruh.end(), [&](int a, int b){
            return arr[a][x] < arr[b][x];
        });
    }
    bool work = 1;
    for(int i = 0; i<n; i++){
        if(arr[bruh[i]] != brr[i]){
            work = false;
            break;
        }
    }
    if(!work){
        cout << -1 << endl;
        exit(0);
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x+1 << " ";
    cout << endl;
}