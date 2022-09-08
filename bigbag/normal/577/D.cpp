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

int n, p[max_n], used[max_n];
vector<int> q;
vector<vector<int> > v;
vector<pair<int, int> > ans;

bool cmp(const vector<int> &v1, const vector<int> &v2) {
    return v1.size() < v2.size();
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            q.clear();
            int a = i;
            while (used[a] == 0) {
                used[a] = 1;
                q.push_back(a);
                a = p[a];
            }
            v.push_back(q);
        }
    }
    if (v.size() == 0) {
        printf("NO\n");
        return 0;
    }
    sort(v.begin(), v.end(), cmp);
    if (v[0].size() > 2) {
        printf("NO\n");
        return 0;
    }
    if (v[0].size() == 1) {
        for (int i = 1; i <= n; ++i) {
            if (i != v[0][0]) {
                ans.push_back(make_pair(v[0][0], i));
            }
        }
    } else {
        ans.push_back(make_pair(v[0][0], v[0][1]));
        for (int i = 1; i < v.size(); ++i) {
            if (v[i].size() % 2) {
                printf("NO\n");
                return 0;
            }
            int poz = 0;
            for (int j = 0; j < v[0].size(); ++j) {
                for (int k = poz; k < v[i].size(); k += v[0].size()) {
                    ans.push_back(make_pair(v[0][j], v[i][k]));
                }
                ++poz;
            }
        }
    }
    printf("YES\n");
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}