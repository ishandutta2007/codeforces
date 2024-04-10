#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;
mt19937 rng(239);
const int len = 101;
const int MOD = 1e9 + 7;

template<class A, class B>
void sum(A &a, B b) {
    a += b;
    if (a < 0LL) a += MOD;
    if (a >= MOD) a -= MOD;
}

long long mult(long long a, long long b) {
    long long val = a * b - (long long) ((long double) a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}

const int N = 30;
int par[N];
int rnk[N];

void init() {
    for (int i = 0; i < N; i++) {
        par[i] = i;
        rnk[i] = 1;
    }
}

int get_par(int u) {
    int x = par[u];
    if (x == u) return x;
    else return get_par(par[x]);
}

void unite(int u, int v) {
    if (get_par(u) == get_par(v)) {
        return;
    }
    u = get_par(u);
    v = get_par(v);
    if (rnk[u] < rnk[v]) {
        par[u] = v;
        rnk[v] += rnk[u];
    } else {
        par[v] = u;
        rnk[u] += rnk[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        init();
        map<char, char> match;
        set<char> used;
        for (auto x: s) {
            int c = x - 'a';
            if (match.count(x)) continue;
            for (int i = 0; i < 26; i++) {
                char cur = (char) ('a' + i);
                if (used.count(cur)) continue;
                if (get_par(c) != get_par(i) && get_par(i) != c) {
                    unite(c, i);
                    match[x] = cur;
                    used.insert(cur);
                    break;
                }
            }
        }
        char unused = 'a';
        for (unused = 'a'; unused <= 'z'; unused++) {
            if (!used.contains(unused)) {
                break;
            }
        }

        for (auto x: s) {
            if (match.count(x))
                cout << match[x];
            else cout << unused;
        }
        cout << "\n";
    }
}