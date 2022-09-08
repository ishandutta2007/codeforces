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

const int max_n = 111, inf = 1111111111;

int n, ans, len[max_n];
string s;
vector<char> v[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        len[i] = s.length();
        for (int j = 0; j < s.length(); ++j) {
            v[i].push_back(s[j]);
        }
        sort(v[i].begin(), v[i].end());
        v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
    }
    for (char a = 'a'; a <= 'z'; ++a) {
        for (char b = a; b <= 'z'; ++b) {
            int res = 0;
            for (int i = 0; i < n; ++i) {
                if (v[i].size() == 1) {
                    if (v[i][0] == a || v[i][0] == b) {
                        res += len[i];
                    }
                }
                if (v[i].size() == 2) {
                    if (v[i][0] == a && v[i][1] == b) {
                        res += len[i];
                    }
                }
            }
            ans = max(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}