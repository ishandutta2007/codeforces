#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

inline int fnwf(int x) {
    return x & (x + 1);
}

inline int fnwh(int x) {
    return x | (x + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int *a, *t, *x;
    a = new int[n]; t = new int[n]; x = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> t[i] >> x[i];
    }
    int* csx = new int[n];
    memcpy(csx, x, sizeof(int) * n);
    sort(csx, csx + n);
    int dfy = unique(csx, csx + n) - csx;

    int* csx_i = new int[n];
    for (int i = 0; i < n; i++) {
        csx_i[i] = lower_bound(csx, csx + dfy, x[i]) - csx;
    }

    vector<int>* cst = new vector<int>[dfy];
    for (int i = 0; i < n; i++) {
        cst[csx_i[i]].push_back(t[i]);
    }
    for (int i = 0; i < dfy; i++) {
        sort(cst[i].begin(), cst[i].end());
        cst[i].resize(distance(cst[i].begin(), unique(cst[i].begin(), cst[i].end())));
    }
    int* cst_i = new int[n];
    for (int i = 0; i < n; i++) {
        cst_i[i] = distance(cst[csx_i[i]].begin(), lower_bound(cst[csx_i[i]].begin(), cst[csx_i[i]].end(), t[i]));
    }

    int** fnw = new int*[dfy];
    for (int i = 0; i < dfy; i++) {
        fnw[i] = new int[cst[i].size()];
        for (int j = 0; j < (int)cst[i].size(); j++)
            fnw[i][j] = 0;
    }
    
    for (int i = 0; i < n; i++) {
        int val = -2, j;
        switch (a[i]) {
            case 1:
                val = 1;
            case 2:
                if (val == -2)
                    val = -1;
                j = cst_i[i];
                while (j < (int)cst[csx_i[i]].size()) {
                    fnw[csx_i[i]][j] += val;
                    j = fnwh(j);
                }
                break;
            case 3:
                j = cst_i[i];
                val = 0;
                while (j >= 0) {
                    val += fnw[csx_i[i]][j];
                    j = fnwf(j) - 1;
                }
                cout << val << endl;
                break;
            default: break;
        }
    }
    return 0;
}