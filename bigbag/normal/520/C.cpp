#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1000000007;
const char letters[] = {'A', 'T', 'G', 'C'};

int n, a[222];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < s.length(); ++i) {
        ++a[s[i]];
    }
    int mx = 0, cnt = 0;
    for (int i = 0; i < 4; ++i) {
        mx = max(mx, a[letters[i]]);
    }
    for (int i = 0; i < 4; ++i) {
        if (mx == a[letters[i]]) {
            ++cnt;
        }
    }
    long long ans = 1;
    for (int i = 0; i < s.length(); ++i) {
        ans *= cnt;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}