#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#define int long long

using namespace std;

long long GetMaxS(int n, int bf, int sdep = 1, long long avail = 1) {
    long long ret = 0;
    for (int dep = sdep; n; ++dep) {
        ret += dep * avail;
        n -= avail;
        avail = min(n, avail * bf);
    }    
    return ret;
}
vector<int> Solve(int n, int s) {
    int bf;
    for (bf = 2; bf < n; ++bf) {
        long long max_s = GetMaxS(n, bf);
        if (max_s <= s) break;
    }
    
    //cerr << "BRANCHING FACTOR: " << bf << endl;
    
    vector<int> parent(n, -1);
    int start = 0;

    int buff = 1;
    s -= 1;

    for (int dep = 2; buff < n; ++dep) {
        //cerr << "DEP: " << dep << endl;
        int choose = 1;
        while (GetMaxS(n - buff, bf, dep, choose) > s)
            ++choose;
        //cerr << "CHOOSE: " << choose << endl;
        assert(choose <= (buff - start) * bf);
        assert(choose + buff <= n);

        int n_start = buff;
        for (int i = 0; i < choose; ++i) {
            parent[buff++] = start + (i / bf);
        }
        start = n_start;
        s -= choose * dep;
    }
    return parent;
}

void Check(vector<int> parent, int n, int s) {
    assert((int)parent.size() == n);
    vector<int> sub(n, 1);
    for (int i = n - 1; i > 0; --i) {
        sub[parent[i]] += sub[i];
    }

    int total = 0;
    for (int i = 0; i < n; ++i)
        total += sub[i];
    assert(total == s);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, s; cin >> n >> s;
    if (s == 1LL * n * (n + 1) / 2) {
        cout << "Yes\n";
        for (int i = 1; i < n; ++i)
            cout << i << " ";
        cout << endl;
        return 0;
    }
    if (s < n + n - 1 || s > 1LL * n * (n + 1) / 2) {
        cout << "No\n";
        return 0;
    }

    auto parent = Solve(n, s);
    Check(parent, n, s);

    cout << "Yes\n";
    for (int i = 1; i < n; ++i)
        cout << parent[i] + 1 << " ";
    cout << endl;

    return 0;
}