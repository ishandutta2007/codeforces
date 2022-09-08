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

int k, a[222], f[max_n];
string s;
vector<pair<int, int> > v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s >> k;
    for (int i = 0; i < s.length(); ++i) {
        ++a[s[i]];
    }
    int ans = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        if (a[i] > 0) {
            ++ans;
            v.push_back(make_pair(a[i], i));
        }
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        if (k >= v[i].first) {
            --ans;
            k -= v[i].first;
            for (int j = 0; v[i].first > 0 && j < s.length(); ++j) {
                if (s[j] == v[i].second) {
                    f[j] = 1;
                    --v[i].first;
                }
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < s.length(); ++i) {
        if (f[i] == 0) {
            cout << s[i];
        }
    }
    cout << endl;
    return 0;
}