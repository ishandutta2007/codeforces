#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    vector<vector<int>> arr(n);
    vector<array<int, 2>> ans(n);
    vector<bool> used(n, 0);
    for(int i = 0; i<n*k; i++){
        int c; cin >> c; --c;
        arr[c].push_back(i);
    }
    for(int l = 0; l<n; l+=k-1){
        int r = min(n-1, l+k-2);
        int cnt = r-l+1;
        while(cnt--){
            array<int, 2> best = {-1, -1};
            for(int i = l; i<=r; i++)
                if(!used[i])
                    best = max(best, {arr[i][arr[i].size()-2], i});
            ans[best[1]] = {best[0], arr[best[1]].back()};
            used[best[1]] = 1;
            for(int i = l; i<=r; i++)
                if(!used[i]) arr[i].pop_back();
        }
    }
    for(int i = 0; i<n; i++)
        cout << ans[i][0]+1 << " " << ans[i][1]+1 << '\n';
}