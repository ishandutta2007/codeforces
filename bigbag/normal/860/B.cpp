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

const int max_n = 70777, max_m = 11, max_c = 50, inf = 1011111111;

int n, m = 9;
pair<int, int> ans[max_n];
vector<int> all[max_n];
vector<pair<int, int> > v;
char s[max_m];

int len(int x) {
    int res = 0;
    while (x) {
        ++res;
        x /= 10;
    }
}

void upd(int num, int x) {
    ans[num] = min(ans[num], make_pair(len(x), x));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        for (int j = 0; j < m; ++j) {
            int x = 1;
            for (int k = j; k < m; ++k) {
                x = x * 10 + s[k] - '0';
                all[i].push_back(x);
            }
        }
        sort(all[i].begin(), all[i].end());
        all[i].erase(unique(all[i].begin(), all[i].end()), all[i].end());
        for (int j = 0; j < all[i].size(); ++j) {
            v.push_back(make_pair(all[i][j], i));
            //cout << all[i][j] << " ";
        }
        //cout << endl;
        ans[i] = make_pair(inf, inf);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) {
        int cnt = 1;
        while (i + 1 < v.size() && v[i].first == v[i + 1].first) {
            ++cnt;
            ++i;
        }
        if (cnt == 1) {
            upd(v[i].second, v[i].first);
        }
    }
    for (int i = 0; i < n; ++i) {
        string s = "";
        int x = ans[i].second;
        while (x) {
            if (x > 9) {
                s += x % 10 + '0';
            }
            x /= 10;
        }
        reverse(s.begin(), s.end());
        printf("%s\n", s.c_str());
    }
    return 0;
}