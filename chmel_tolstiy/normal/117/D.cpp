#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <ctime>
#include <cassert>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;

long long n, q, M;

pll F(long long n, long long r, long long v) {
    ll sum = 0;
    ll cnt = 0;

    if (!n || !v || !r || r < 0 || v < 0) return make_pair(sum, cnt);
    
    if (r >= n) {
        n = min(n, v);
        sum = (n%M)*((n-1)%M)/2 % M;
        cnt = n%M;
    } else {
        pll pe, po;
        pe = F((n+1)/2, r, (v+1)/2);
        po = F(n/2, r-(n+1)/2, v/2);
        sum = (pe.first*2+po.first*2+po.second)%M;
        cnt = pe.second+po.second;
    }

    return make_pair(sum % M, cnt % M);
}

int G(ll n, ll l, ll r, ll u, ll v) {
        ll res = 0;
        pll p;

        p = F(n, r, v);
        res += p.first + p.second;
        p = F(n, r, u-1);
        res -= p.first + p.second;

        p = F(n, l-1, v);
        res -= p.first + p.second;
        p = F(n, l-1, u-1);
        res += p.first + p.second;

        res = (res % M + M)%M;
     return res;
}

void build(vector<int>&v) {
    if (v.size() <= 2) return;
    vector<int> o, e;
    for (int i = 0; i < v.size(); i++) {
        if (i&1) e.push_back(v[i]);
        else o.push_back(v[i]);
    }
    build(o);
    build(e);
    for (int i = 0; i < o.size(); i++) v[i] = o[i];
    for (int i = 0; i < e.size(); i++) v[i+o.size()] = e[i];
}

int brute(int n, int l, int r, int u, int v) {
    vector<int> a;
    for (int i = 0; i < n; i++) a.push_back(i+1);
    build(a);

    int res = 0;

    for (int i = l - 1; i <= r-1; i++) if (u <= a[i] && a[i] <= v) res = (res + a[i])%M;

    return res;
}

int main() {
    //freopen("d.in", "r", stdin);
    cin >> n >> q >> M;

    while (q--) {
        ll l, r, u, v;
        scanf("%I64d %I64d %I64d %I64d", &l, &r, &u, &v);
        int res = G(n, l, r, u, v);
        printf("%d\n", (int)res); 
        //assert(res == brute(n, l, r, u, v));
    }

    cerr << (double)(clock())/CLOCKS_PER_SEC << endl;
    return 0;
}