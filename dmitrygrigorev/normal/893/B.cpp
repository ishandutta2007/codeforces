#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int> good;
    for (int i=1;i <= 15; i++){
        int now = ((1 << i) - 1) * (1 << (i-1));
        good.push_back(now);
    }
    int ans = 0;
    for (int i=0; i < 15; i++){
        if (n % good[i] == 0) ans = good[i];
    }
    cout << ans << endl;
    return 0;
}