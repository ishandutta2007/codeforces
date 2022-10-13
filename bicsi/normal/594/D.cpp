#include <bits/stdc++.h>

using namespace std;

vector<int> Facts[1000005];

int L[300000], R[300000], I[300000], Inv[1000005], V[300000], Last[1000005], Sol[300005];

const int MOD = 1e9 + 7;

void ciur() {
    Inv[1] = 1;
    for(int i=2; i<=1000000; i++) {
        if(Facts[i].empty()) {
            for(int j=i; j<=1000000; j+=i)
                Facts[j].push_back(i);
        }
        Inv[i] = -1LL * MOD / i * Inv[MOD % i] % MOD;
        if(Inv[i] < 0) Inv[i] += MOD;
    }
}

int T[1000000];

void init(int node, int b, int e) {
    T[node] = 1;
    if(b == e) return;
    int m = b + e >> 1;
    init(node*2, b, m);
    init(node*2+1, m+1, e);
}

void inm(int node, int b, int e, int poz, int val) {
    T[node] = 1LL * T[node] * val % MOD;

    if(b == e) return;
    int m = b + e >> 1;
    if(poz <= m) inm(node*2, b, m, poz, val);
    else inm(node*2+1, m+1, e, poz, val);
}

int query(int node, int b, int e, int l, int r) {
    if(r < b || l > e) return 1;
    if(b >= l && e <= r) return T[node];
    int m = b + e >> 1;
    return 1LL * query(node*2, b, m, l, r) * query(node*2+1, m+1, e, l, r) % MOD;
}

int main() {

    int n;

    ciur();

    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>V[i];

    int m;

    cin>>m;
    for(int i=1; i<=m; i++) {
        cin>>L[i]>>R[i];
        I[i] = i;
    }

    int mm = 256;
    sort(I+1, I+m+1, [](int a, int b) {
         return R[a] < R[b];
    });
    R[m+1] = n+2;

    init(1, 1, n);

    int r = 1;
    for(int i=1; i<=m; i++) {
        int ii = I[i];

        while(r <= R[ii]) {
            inm(1, 1, n, r, V[r]);
            for(auto x : Facts[V[r]]) {
                if(Last[x]) inm(1, 1, n, Last[x], 1LL * Inv[x-1] * x % MOD);
                inm(1, 1, n, r, 1LL * (x-1) * Inv[x] % MOD);
                Last[x] = r;
            }
            r++;
        }

        Sol[ii] = query(1, 1, n, L[ii], R[ii]);
    }

    for(int i=1; i<=m; i++)
        cout<<Sol[i]<<'\n';


    return 0;
}