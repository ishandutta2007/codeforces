#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   
    int zeros = 0;
    vector<int> left(1000000, 0), right(1000000, 0); 

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string str; cin >> str;

        int cnt = 0, min_cnt = 0;
        for (int i = 0; i < (int)str.size(); ++i) {
            char c = str[i];
            if (c == '(') cnt += 1;
            else cnt -= 1;
            min_cnt = min(min_cnt, cnt);
        }

        if (cnt == 0 && min_cnt == 0) {
            zeros += 1;
        }
        if (cnt > 0 && min_cnt == 0) {
            left[cnt] += 1;
        }
        if (cnt < 0 && min_cnt == cnt) {
            right[-cnt] += 1;
        }
    }

    int ans = zeros / 2;
    for (int i = 1; i < 1000000; ++i) {
        ans += min(left[i], right[i]);
    }
    cout << ans << endl;

    return 0;
}