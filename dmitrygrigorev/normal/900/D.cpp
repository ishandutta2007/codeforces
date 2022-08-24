#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;
int Pow(int a, int b){
    int ans = 1;
    int st = a;
    for (int i=0; i < 40; i++){
        int ba = (1LL << i) & b;
        if (ba == 0){
            st *= st;
            st %= MOD;
            continue;
        }
        ans *= st;
        ans %= MOD;
        st*=st;
        st %= MOD;
    }
    return ans;
}
signed main(){
    //freopen("input.txt", "r", stdin);
    int x, y;
    cin >> x >> y;
    if (y % x != 0){
        cout << 0 << endl;
        return 0;
    }
    y /= x;
    vector<int> g;
    for (int i=1; i*i <= y; i++){
        if (y % i == 0){
            g.push_back(i);
            if (i*i != y) g.push_back(y/i);
        }
    }
    sort(g.begin(), g.end());
    int sz = g.size();
    vector<int> ans(sz);
    fill(ans.begin(), ans.end(), 0);
    for (int i=sz-1; i >= 0; i--){
        int Y = y / g[i];
        int res = Pow(2, Y-1);
        for (int j=i+1; j < sz; j++){
            if (g[j] % g[i] == 0) res -= ans[j];
        }
        res %= MOD;
        if (res < 0) res += MOD;
        ans[i] = res;
    }
    cout << ans[0] << endl;
    return 0;
}