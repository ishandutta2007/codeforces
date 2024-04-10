#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 1000001;
const long long INF = 1LL * 1000000000 * 1000000000;

int N, M, S, MM, TM;
vector<pair<int, long long> > X[MAXN];
int L[MAXN], R[MAXN], Y[MAXN];
long long D[MAXN];
bool Z[MAXN];

void buildD(int t, int l, int r) {
    Y[t] = ++MM;
    if (l == r) {
        X[Y[t]].push_back(make_pair(l, 0));
        return ;
    }

    L[t] = ++TM;
    R[t] = ++TM;
    int mid = (l + r) / 2;
    buildD(L[t], l, mid);
    buildD(R[t], mid + 1, r);
    X[Y[t]].push_back(make_pair(Y[L[t]], 0));
    X[Y[t]].push_back(make_pair(Y[R[t]], 0));
}

void buildU(int t, int l, int r) {
    Y[t] = ++MM;
    if (l == r) {
        X[l].push_back(make_pair(Y[t], 0));
        return ;
    }

    L[t] = ++TM;
    R[t] = ++TM;
    int mid = (l + r) / 2;
    buildU(L[t], l, mid);
    buildU(R[t], mid + 1, r);
    X[Y[L[t]]].push_back(make_pair(Y[t], 0));
    X[Y[R[t]]].push_back(make_pair(Y[t], 0));
}

void insertD(int t, int a, int b, int l, int r, int v, int w) {
    if (l <= a && b <= r) {
        X[v].push_back(make_pair(Y[t], w));
        return ;
    }
    int mid = (a + b) / 2;
    if (l <= mid) insertD(L[t], a, mid, l, r, v, w);
    if (mid + 1 <= r) insertD(R[t], mid + 1, b, l, r, v, w);
}

void insertU(int t, int a, int b, int l, int r, int v, int w) {
    if (l <= a && b <= r) {
        X[Y[t]].push_back(make_pair(v, w));
        return ;
    }
    int mid = (a + b) / 2;
    if (l <= mid) insertU(L[t], a, mid, l, r, v, w);
    if (mid + 1 <= r) insertU(R[t], mid + 1, b, l, r, v, w);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> S;
    MM = N;
    buildD(++TM, 1, N);
    buildU(++TM, 1, N);

    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, c;
            cin >> a >> b >> c;
            X[a].push_back(make_pair(b, c));
        } else {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            if (t == 2) 
                insertD(1, 1, N, l, r, v, w); 
            else 
                insertU(N + N, 1, N, l, r, v, w);
        }
    }

    for (int i = 1; i <= MM; ++i) {
        D[i] = INF;
        Z[i] = false;
    }
    D[S] = 0;
    set<pair<long long, int> > C;
    C.insert(make_pair(0, S));
    while (!C.empty()) {
        long long W = C.begin()->first;
        int a = C.begin()->second;
        C.erase(C.begin());
        if (Z[a]) continue;
        Z[a] = true;
        for (int i = 0; i < X[a].size(); ++i) {
            if (D[X[a][i].first] > D[a] + X[a][i].second) {
                D[X[a][i].first] = D[a] + X[a][i].second;
                C.insert(make_pair(D[X[a][i].first], X[a][i].first));
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (D[i] != INF) cout << D[i] << " "; else cout << -1 << " ";
    }
    cout << endl;

    return 0;
}