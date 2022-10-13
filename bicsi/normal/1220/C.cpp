#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    int n = s.size();
    char minn = 'z';
    for (int i = 0; i < n; ++i) {
        if (minn < s[i]) {
            cout << "Ann" << endl;
        } else {
            cout << "Mike" << endl;
        }
        minn = min(minn, s[i]);
    }

    return 0;
}