#include <bits/stdc++.h>

using namespace std;

int rt[1 << 19];

int query(int b, int e, int n = 1, int l = 0, int r = 1 << 18) {
    if(e <= l or r <= b) {
        return 1 << 30;
    }
    if(b <= l and r <= e) {
        return rt[n];
    }
    return min(query(b, e, 2 * n, l, (l + r) / 2), query(b, e, 2 * n + 1, (l + r) / 2, r));
}

void build(const vector<int>& v, int n = 1, int l = 0, int r = 1 << 18) {
    if(l + 1 == r) {
        rt[n] = v[l];
        return;
    }
    build(v, 2 * n, l, (l + r) / 2);
    build(v, 2 * n + 1, (l + r) / 2, r);
    rt[n] = min(rt[2 * n], rt[2 * n + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> P(N), invP(N), A(M);
    for(int n = 0; n < N; ++n) {
        int x;
        cin >> x;
        --x;
        P[n] = x;
        invP[x] = n;
    }
    P.push_back(P[0]);
    for(int& a : A) {
        cin >> a;
        --a;
    }
    vector<int> last_occ(N, M);
    vector<vector<int>> G(18, vector<int>(M + 1, M));
    for(int m = M - 1; m >= 0; --m) {
        G[0][m] = last_occ[P[invP[A[m]] + 1]];
        last_occ[A[m]] = m;
    }
    for(int k = 1; k < 18; ++k) {
        for(int m = 0; m < M; ++m) {
            G[k][m] = G[k - 1][G[k - 1][m]];
        }
    }
    vector<int> GG(1 << 18);
    iota(GG.begin(), GG.end(), 0);
    for(int m = 0; m < M; ++m) {
        int x = N - 1, k = 0;
        while(x) {
            if(x & 1) {
                GG[m] = G[k][GG[m]];
            }
            ++k;
            x /= 2;
        }
    }
    
    build(GG);
    while(Q--) {
        int l, r;
        cin >> l >> r;
        int m = query(l - 1, r);
        if(m < r) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    cout << "\n";
    
    return 0;
}