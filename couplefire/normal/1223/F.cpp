#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        int arr[n+1];
        set<pair<int, int>> pos[n+1];
        for(int i = 0; i<n; i++) cin >> arr[i+1];
        pair<int, int> dp[n+1];
        dp[0] = {0, 0};
        int maxchain = 0;
        int chain[n+1];
        chain[0] = -INF;
        for(int i = 1; i<=n; i++){
            dp[i] = {0, 0};
            chain[i] = -INF;
            pos[arr[i]].insert({chain[i], -i});
            if(i > 1 && arr[i-1] == arr[i]){
                dp[i] = {1+dp[i-2].first, i-1};
                if(chain[dp[i-2].second] == -INF) chain[i-1] = ++maxchain;
                else chain[i-1] = chain[dp[i-2].second];
                if(i == 2) continue;
                pos[arr[i-2]].erase({-INF, -i+2});
                pos[arr[i-2]].insert({chain[i-1], -i+2});
                continue;
            }
            if(dp[i-1].second == 0) continue;
            int cc = chain[dp[i-1].second];
            if((pos[arr[i]].lower_bound(make_pair(cc, -INF)) == pos[arr[i]].end())) continue;
            pair<int,int> lol = *(pos[arr[i]].lower_bound(make_pair(cc, -INF)));
            if(lol.first != cc) continue;
            // cout << lol.second << endl;
            dp[i] = {1+dp[-lol.second-1].first, -lol.second};
            if(chain[dp[-lol.second-1].second] == -INF) chain[-lol.second] = ++maxchain;
            else chain[-lol.second] = chain[dp[-lol.second-1].second];
            if(-lol.second == 1) continue;
            pos[arr[-lol.second-1]].erase({-INF, lol.second+1});
            pos[arr[-lol.second-1]].insert({chain[-lol.second], lol.second+1});
        }
        // if(n == 9) cout << dp[7].first << endl;
        long long ans = 0;
        for(int i = 1; i<=n; i++) ans += dp[i].first;
        cout << ans << endl;
        // for(int i = 1; i<=n; i++){
        //     cout << dp[i].first << " " << dp[i].second << endl;
        // }
        // cout << endl;
        // if(n == 6) cout << chain[1] << endl;
    }
    // int aaa[10] = {0};
    // int t = 102;
    // while(t--){
    //     int index = 9;
    //     int ocur[10] = {0};
    //     for(int i = 0; i<10; i++) ocur[aaa[i]]++;
    //     while(true){
    //         ocur[aaa[index]]--;
    //         aaa[index]++;
    //         ocur[aaa[index]]++;
    //         bool k = true;
    //         for(int i = 0; i<aaa[index]; i++) k &= (ocur[i]>0);
    //         if(k) break;
    //         else{
    //             ocur[aaa[index]]--;
    //             aaa[index] = 1;
    //             index--;
    //         }
    //     }
    // }
    // for(int i = 0; i<10; i++) cout << aaa[i];
    // cout << endl;
}