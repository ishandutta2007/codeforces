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

const int max_n = 111111, inf = 1111111111;

int a[222], cnt[33][max_n];
long long sum[max_n];
string s;
map<pair<char, long long>, int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 26; ++i) {
        cin >> a[i];
    }
    cin >> s;
    s = "#" + s;
    for (int i = 1; i < s.length(); ++i) {
        sum[i] = sum[i - 1] + a[s[i] - 'a'];
        for (int j = 0; j < 26; ++j) {
            cnt[j][i] = cnt[j][i - 1];
            if (s[i] - 'a' == j) {
                ++cnt[j][i];
            }
        }
    }
    long long ans = 0;
    for (int l = 2; l < s.length(); ++l) {
        ++q[make_pair(s[l], sum[l - 1])];
    }
    for (int l = 1; l + 1 < s.length(); ++l) {
        ans += q[make_pair(s[l], sum[l])];
        --q[make_pair(s[l + 1], sum[l])];
    }
    cout << ans << endl;
    return 0;
}