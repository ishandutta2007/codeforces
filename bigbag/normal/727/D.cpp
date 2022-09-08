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

const int max_n = 111111, sz = 15, inf = 1111111111;
const string names[] = {"S", "M", "L", "XL", "XXL", "XXXL"};

map<string, int> q;

int n, cnt[sz], num[max_n];
char a[sz];
vector<int> all[sz];
string s[max_n], ans[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 6; ++i) {
        q[names[i]] = i;
    }
    for (int i = 0; i < 5; ++i) {
        q[names[i] + "," + names[i + 1]] = 6 + i;
    }
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &cnt[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a);
        s[i] = a;
        num[i] = q[s[i]];
        all[num[i]].push_back(i);
    }
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < all[i].size(); ++j) {
            --cnt[i];
            ans[all[i][j]] = names[i];
        }
        if (cnt[i] < 0) {
            printf("NO\n");
            return 0;
        }
        int v = 6 + i;
        for (int j = 0; j < all[v].size() && j < cnt[i]; ++j) {
            ans[all[v][j]] = names[i];
        }
        for (int j = cnt[i]; j < all[v].size(); ++j) {
            all[i + 1].push_back(all[v][j]);
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; ++i) {
        printf("%s\n", ans[i].c_str());
    }
    return 0;
}