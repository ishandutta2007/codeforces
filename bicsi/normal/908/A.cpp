#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    int cnt = 0;

    for (auto x : s) {
        if (x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u') {
            ++cnt;
        }
        if (x >= '0' && x <= '9')
            cnt += x % 2;
    }
    cout << cnt << endl;

    return 0;
}