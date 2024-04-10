#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 200100;
const int MAXM = 1600100;
const int INF = 1000000000;

int n, m, NN, nn;
vector<int> x[MAXN];
int y[MAXM], ll[MAXM], rr[MAXM];
int l[MAXM], r[MAXM], k1[MAXM], k2[MAXM];
bool z[MAXM], level[MAXM];


int dfs(int a, bool LV) {
    z[a] = true;
    ll[a] = rr[a] = ++NN;
    level[a] = LV;
    for (int i = 0; i < x[a].size(); ++i) {
        if (!z[x[a][i]]) dfs(x[a][i], !LV);
        rr[a] = ++NN;
    }
    return 0;
}

int build(int a, int b) {
    int k = ++nn;
    if (a < b) {
        int mid = (a + b) >> 1;
        l[k] = nn + 1;
        build(a, mid);
        r[k] = nn + 1;
        build(mid+1, b);
    }
    return 0;
}

int insert1(int t, int a, int b, int c, int d, int v) {
    if (a <= c && d <= b) {
        k1[t] += v;
        return 0;
    }
    k1[l[t]] += k1[t];
    k1[r[t]] += k1[t];
    k1[t] = 0;
    int mid = (c + d) >> 1;
    if (a <= mid) insert1(l[t], a, b, c, mid, v);
    if (mid + 1 <= b) insert1(r[t], a, b, mid+1, d, v);
    return 0;
}

int insert2(int t, int a, int b, int c, int d, int v) {
    if (a <= c && d <= b) {
        k2[t] += v;
        return 0;
    }
    k2[l[t]] += k2[t];
    k2[r[t]] += k2[t];
    k2[t] = 0;
    int mid = (c + d) >> 1;
    if (a <= mid) insert2(l[t], a, b, c, mid, v);
    if (mid + 1 <= b) insert2(r[t], a, b, mid+1, d, v);
    return 0;
}

int query1(int t, int a, int c, int d) {
    if (c == d) {
        return k1[t];
    }
    k1[l[t]] += k1[t];
    k1[r[t]] += k1[t];
    k1[t] = 0;
    int mid = (c + d) >> 1;
    if (a <= mid) return query1(l[t], a, c, mid);
    if (mid+1 <= a) return query1(r[t], a, mid+1, d);
}

int query2(int t, int a, int c, int d) {
    if (c == d) {
        return k2[t];
    }
    k2[l[t]] += k2[t];
    k2[r[t]] += k2[t];
    k2[t] = 0;
    int mid = (c + d) >> 1;
    if (a <= mid) return query2(l[t], a, c, mid);
    if (mid+1 <= a) return query2(r[t], a, mid+1, d);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> y[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        x[a].push_back(b);
        x[b].push_back(a);
    }
    dfs(1, true);
    build(1, NN);
    
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            if (level[b]) 
                insert1(1, ll[b], rr[b], 1, NN, c);
            else
                insert2(1, ll[b], rr[b], 1, NN, c);
                
        } else {
            cin >> b;
            if (level[b])
                cout << y[b] + query1(1, ll[b], 1, NN) - query2(1, ll[b], 1, NN) << endl;
            else
                cout << y[b] + query2(1, ll[b], 1, NN) - query1(1, ll[b], 1, NN) << endl;
        }
    }
    
    
    return 0;
}