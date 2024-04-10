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

const int max_n = 2222, inf = 1111111111;

int n, ans, a[max_n], b[max_n], res[max_n];
vector<pair<int, int> > v;

void add(int x, int y) {
    if (x == y) {
        return;
    }
    if (x > y) {
        swap(x, y);
    }
    swap(a[x], a[y]);
    ++x;
    ++y;
    ans += y - x;
    v.push_back(make_pair(x, y));
}

int myabs(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        res[b[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        int poz;
        for (int j = i; j < n; ++j) {
            if (a[j] == b[i]) {
                poz = j;
                break;
            }
        }
        for (int j = poz - 1; j > i; --j) {
            if (poz <= res[a[j]]) {
                add(poz, j);
                poz = j;
            }
        }
        add(poz, i);
    }
    printf("%d\n%d\n", ans, v.size());
    for (int i = 0; i < v.size(); ++i) {
        printf("%d %d\n", v[i].first, v[i].second);
    }
    return 0;
}