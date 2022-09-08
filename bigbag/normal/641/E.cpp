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

const int max_n = 1001111, inf = 1111111111;

int n, C, tp[max_n], t[max_n], x[max_n], ans[max_n];
int a[max_n], last[max_n];
vector<int> all, all2, v[max_n];

void proc() {
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    map<int, int> q;
    for (int i = 0; i < all.size(); ++i) {
        q[all[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        x[i] = q[x[i]];
        v[x[i]].push_back(i);
    }
    q.clear();


    sort(all2.begin(), all2.end());
    all2.erase(unique(all2.begin(), all2.end()), all2.end());
    for (int i = 0; i < all2.size(); ++i) {
        q[all2[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        t[i] = q[t[i]];
    }
    q.clear();
}

void update(int i, int x) {
    //cout << i <<  " " << x << endl;
    for (; i < n; i = (i | (i + 1))) {
        if (last[i] < C) {
            last[i] = C;
            a[i] = 0;
        }
        a[i] += x;
        //cout << i <<  " " << x << endl;
    }
}

int get(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        if (last[r] < C) {
            last[r] = C;
            a[r] = 0;
        }
        res += a[r];
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &tp[i], &t[i], &x[i]);
        if (tp[i] == 2) {
            tp[i] = -1;
        }
        all.push_back(x[i]);
        all2.push_back(t[i]);
    }
    proc();
    /*for (int i = 0; i < n; ++i) {
        cout << t[i] << " " << x[i] << endl;
    }*/
    for (int i = 0; i < all.size(); ++i) {
        ++C;
        for (int j = 0; j < v[i].size(); ++j) {
            int num = v[i][j];
            if (tp[num] <= 2) {
                update(t[num], tp[num]);
            } else {
                ans[num] = get(t[num]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (tp[i] == 3) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}