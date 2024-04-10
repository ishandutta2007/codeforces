#include <bits/stdc++.h>
using namespace std;

int query(int U, vector<int> &cand) {
    printf("1 %d", cand.size());
    printf(" %d", U);
    for (int x : cand) printf(" %d", x);
    puts("");
    fflush(stdout);
    int ret; scanf("%d", &ret);
    return ret;
}

int main() {
    int ncase; scanf("%d", &ncase);
    while (ncase--) {
        int n; scanf("%d", &n);
        int U = 1;
        vector<int> cand;
        for (int i = 1; i <= n; i++) if (i != U) cand.push_back(i);
        vector<int> left, right;
        int d = query(U, cand);
        while (cand.size() > 1) {
            int m = cand.size();
            int h = m / 2;
            left.clear(), right.clear();
            for (int j = 0; j < m; j++) {
                if (j < h) left.push_back(cand[j]);
                else right.push_back(cand[j]);
            }
            if (query(1, left) == d) {
                cand = left;
            } else {
                cand = right;
            }
        }
        U = cand.back();
        cand.clear();
        for (int i = 1; i <= n; i++) if (i != U) cand.push_back(i);
        printf("-1 %d\n", query(U, cand));
        fflush(stdout);
    }
    return 0;
}