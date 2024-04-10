#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file
#else

#endif


const int MAXM = 1<<18;
//~ const int MAXM = 4;
const int MAXN = 1e6 + 10;

struct Plan{
    int l, r;
    LL q;
    LL c;
};

bool operator < (const Plan& p1, const Plan& p2) {
    return p1.c < p2.c;
}

struct Nodo{
    LL q;
    LL c;
};

Plan p[MAXM];
Nodo st[2*MAXM];

void update(int v, int x) {
    LL q = p[v].q;
    LL c = p[v].c;

    v += MAXM;
    while (v > 0) {
        st[v].q += x*q;
        st[v].c += x*q*c;
        v /= 2;
    }
}

LL ask(int v, LL k) {
    if (k == 0) return 0;
    if (v >= MAXM) return p[v-MAXM].c * min(k, p[v-MAXM].q);
    if (k >= st[2*v].q) return st[2*v].c + ask(2*v+1, k - st[2*v].q);
    return ask(2*v, k);
}

vector<int> ii[MAXN], ff[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Togliere nei problemi con query online

    int n, k, m;
    cin >> n >> k >> m;

    for (int i = 0; i < m; i++) {
        cin >> p[i].l >> p[i].r >> p[i].q >> p[i].c;
    }
    sort(p, p+m);
    for (int i = 0; i < m; i++) {
        ii[p[i].l].push_back(i);
        ff[p[i].r].push_back(i);
    }

    LL res = 0;
    for (int i = 1; i <= n; i++) {
        for (int v : ii[i]) update(v, 1);
        //~ cout << ask(1, k) << endl;
        res += ask(1, k);
        for (int v : ff[i]) update(v, -1);
    }
    cout << res << "\n";
}