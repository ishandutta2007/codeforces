#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010*2;
const int maxw = 1e9;

vector<int> tmp;

int n, c;
int L[maxn], R[maxn], fa[maxn];
int qo[maxn], qx[maxn], qy[maxn];

vector<int> T[maxn<<2];
vector<int> vres;

int getroot(int x) {
    if (x == fa[x]) return x;
    return fa[x] = getroot(fa[x]);
}

void upd(int L, int R, int x, int l, int r, int rt) {
    if (L > R) return;
    if (L <= l && r <= R) {
        T[rt].push_back(x);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m) upd(L, R, x, l, m, rt<<1);
    if (R > m) upd(L, R, x, m+1, r, rt<<1|1);
}


void qry(int p, int l, int r, int rt) {
    vres.insert(vres.end(), T[rt].begin(), T[rt].end());
    T[rt].clear();
    if (l == r) return;
    int m = (l + r) >> 1;
    if (p <= m) qry(p, l, m, rt<<1);
    else qry(p, m+1, r, rt<<1|1);
}

// x  y  x
void Union(int x, int y) {
    int ry = getroot(y);
    fa[ry] = x;
    L[x] = min(L[x], L[ry]);
    R[x] = max(R[x], R[ry]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &qo[i], &qx[i], &qy[i]);
        if (qo[i] == 1) {
            tmp.push_back(qx[i]), tmp.push_back(qy[i]);
        }
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 1; i <= n; i++) {
        if (qo[i] == 1) {
            qx[i] = int (lower_bound(tmp.begin(), tmp.end(), qx[i]) - tmp.begin() + 1);
            qy[i] = int (lower_bound(tmp.begin(), tmp.end(), qy[i]) - tmp.begin() + 1);
            ++ c;
            L[c] = qx[i], R[c] = qy[i];
            fa[c] = c;
        }
    }
    int _c = 0;
    for (int i = 1; i <= n; i++) {
        if (qo[i] == 1) {
            ++ _c;
            vres.clear();
            int l = qx[i], r = qy[i];
            qry(l, 1, 2*n, 1), qry(r, 1, 2*n, 1);
            for (int i = 0; i < vres.size(); i++) Union(_c, vres[i]);
            upd(L[_c]+1, R[_c]-1, _c, 1, 2*n, 1);
        } else {
            int rx = getroot(qx[i]), ry = getroot(qy[i]);
            if (L[rx] >= L[ry] && R[rx] <= R[ry]) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}