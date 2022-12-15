#include <bits/stdc++.h>
 
using namespace std;
 
const int k_N = 1e6 + 3;
 
int n, m;
pair<int, bool> dp[k_N][1 << 3];
string s[3];
 
bool check(int mask, int new_mask){
    int cnt = 0;
    for(int i = 0; i < 2; ++i){
        cnt += (bool)(mask & (1 << i));
        cnt += (bool)(new_mask & (1 << i));
    }
 
    if(cnt % 2 == 0) return false;
    if(n == 2) return true;
 
    cnt = 0;
    for(int i = 1; i < 3; ++i){
        cnt += (bool)(mask & (1 << i));
        cnt += (bool)(new_mask & (1 << i));
    }
 
    return cnt & 1;
}
 
int solve(int pos, int mask){
    if(pos == m) return 0;
 
    auto &[ans, solved] = dp[pos][mask];
    if(solved) return ans;
 
    solved = true, ans = k_N;
 
    for(int new_mask = 0; new_mask < (1 << n); ++new_mask){
        if(pos == 0 || check(mask, new_mask)){
            int add = 0;
            for(int i = 0; i < n; ++i){
                int x = (bool)(new_mask & (1 << i));
                if(x != s[i][pos] - '0') add++;
            }
            ans = min(ans, solve(pos + 1, new_mask) + add);
        }
    }
 
    return ans;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> m;
 
    if(n >= 4){
        cout << "-1\n";
        return 0;
    }
    if(n == 1){
        cout << "0\n";
        return 0;
    }
 
    for(int i = 0; i < n; ++i)
        cin >> s[i];
 
    int ans = k_N;
    for(int i = 0; i < (1 << n); ++i)
        ans = min(ans, solve(0, i));
 
    cout << ans << "\n";
}