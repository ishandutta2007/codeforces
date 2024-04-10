#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define MOD 1000000007
long long pow2[MAXN];
long long siz[MAXN];
long long prt[MAXN];
long long val[MAXN];
map<long long, vector<pair<long long, long long>>> edges;
long long n, m, k;
long long ans;

long long find_set(long long v) {
    if (v == prt[v])
        return v;
    return prt[v] = find_set(prt[v]);
}

void make_set(long long v) {
    prt[v] = v;
    siz[v] = 1;
}

long long union_sets(long long a, long long b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        prt[b] = a;
        siz[a] += siz[b];
        return -1;
    }
    return 0;
}

void precompute(){
    pow2[0] = 1;
    for(long long i = 1; i<MAXN; i++){
        pow2[i] = (2*pow2[i-1])%MOD;
    }
}

void solve(long long i){
    long long cur = n;
    for(auto j : edges[i]){
        cur += union_sets(j.first, j.second);
    }
    ans += pow2[cur];
    ans %= MOD;
    for(auto j : edges[i]){
        make_set(j.first);
        make_set(j.second);
    }
}

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    precompute();
    set<long long> num;
    for(long long i = 0; i<n; i++) cin >> val[i];
    for(long long i = 0; i<m; i++){
        long long a, b; cin >> a >> b;
        --a; --b;
        edges[val[a]^val[b]].push_back({a, b});
        num.insert(val[a]^val[b]);
    }
    ans = ((pow2[k]-num.size())*pow2[n])%MOD;
    for(long long i = 0; i<n; i++) make_set(i);
    for(auto i : num) solve(i);
    cout << (ans+MOD)%MOD << endl;
}