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

const int max_n = 1011111, inf = 1111111111;

int n, k, z[max_n];
string s;
vector<pair<int, int> > v;

void get_z_function() {
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < s.length(); ++i) {
        z[i] = 0;
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < s.length() && s[i + z[i]] == s[z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> s;
    get_z_function();
    for (int len = 1; len * k <= n; ++len) {
        int poz = len, f = 0;
        for (int i = 1; i < k; ++i) {
            if (z[poz] < len) {
                f = 1;
                break;
            }
            poz += len;
        }
        if (f == 0) {
            v.push_back(make_pair(poz - 1, 0));
            v.push_back(make_pair(poz + min(len, z[poz]) - 1, 1));
            //cout << len << " - " << poz - 1 << " " << poz + min(len, z[poz]) - 1 << endl;
        }
    }
    sort(v.begin(), v.end());
    int poz = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        while (poz < v.size() && v[poz].first == i && v[poz].second == 0) {
            ++cnt;
            ++poz;
        }
        printf("%d", min(cnt, 1));
        while (poz < v.size() && v[poz].first == i && v[poz].second == 1) {
            --cnt;
            ++poz;
        }
    }
    return 0;
}