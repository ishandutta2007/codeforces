#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct String {
    int n;
    string str;
    vector<int> cntb, dpa;

    String(string str) : 
        n(str.size()), str(str), cntb(n), dpa(n) { 
            build(); 
    }

    void build() {
        for (int i = 0; i < n; ++i) {
            if (str[i] == 'C') str[i] = 'B';
            if (str[i] == 'A') {
                dpa[i] = 1;
                if (i > 0) 
                    dpa[i] += dpa[i - 1];
            } else {
                cntb[i] = 1;
            }
            if (i > 0) 
                cntb[i] += cntb[i - 1];
        }
    }

    pair<int, int> Get(int l, int r) {
        int a = dpa[r];
        a = min(a, r - l + 1);
        int b = cntb[r];
        if (l > 0) b -= cntb[l - 1];
        return {b, a};
    }
};

bool OK(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == 0 && p2.first != 0) {
        p1.first += 2; p1.second -= 1;
        return (p1.first % 2) == (p2.first % 2) && p1.second >= p2.second;
    }

    if (p1.first > p2.first) return false;
    if (p1.second < p2.second) return false;

    if (p1.first == p2.first) {
        return p1.second >= p2.second 
            && (p1.second - p2.second) % 3 == 0;
    } else {
        p1.second -= p2.second;
        p1.second %= 3;
        if (p1.second)
            p1.first += 2;
        int delta = p2.first - p1.first;
        if (delta % 2) return false;
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s, t;
    cin >> s >> t;
    String big(s), small(t);


    int q; cin >> q;
    while (q--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        --a; --b; --c; --d;
        auto p1 = big.Get(a, b);
        auto p2 = small.Get(c, d);
//        cerr << p1.first << " " << p1.second << " - " << p2.first << " " << p2.second << endl;

        cout << OK(p1, p2);
    }

    return 0;
}