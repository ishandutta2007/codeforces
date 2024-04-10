#include <bitset>
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

const int max_n = 1011111, inf = 1011111111;

int n, k, a[max_n], used[max_n];
vector<int> v, q;

bitset<max_n> knapsack(vector<int> v) {
    sort(v.begin(), v.end());
    bitset<max_n> res;
    res[0] = 1;
    for (int i = 0; i < v.size(); ++i) {
        int cnt = 1;
        while (i + 1 < v.size() && v[i] == v[i + 1]) {
            ++i;
            ++cnt;
        }
        for (int pw = 1; pw <= cnt; pw *= 2) {
            res |= res << (pw * v[i]);
            cnt -= pw;
        }
        res |= res << (cnt * v[i]);
    }
    return res;
}

int get_min(int k) {
    bitset<max_n> b = knapsack(v);
    if (b[k]) {
        return k;
    }
    return k + 1;
}

int get_max(int k) {
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
        while (k && v[i] >= 2) {
            --k;
            res += 2;
            v[i] -= 2;
        }
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 1 && k) {
            ++res;
            --v[i];
            --k;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            int len = 0, pos = i;
            while (used[pos] == 0) {
                used[pos] = 1;
                pos = a[pos];
                ++len;
            }
            v.push_back(len);
        }
    }
    printf("%d ", get_min(k));
    printf("%d\n", get_max(k));
    return 0;
}