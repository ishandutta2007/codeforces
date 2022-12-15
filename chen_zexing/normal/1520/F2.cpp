#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

map<pair<int,int>, int> cache;

void dec(int pos, int L, int R) {
    cache[{L, R}]--;

    if (L != R) {
        int M = (L + R) / 2;
        if (pos <= M)
            dec(pos, L, M);
        else
            dec(pos, M + 1, R);
    }
}

int main() {
    int n, cases;
    cin >> n >> cases;
    forn(case_, cases) {
        int k;
        cin >> k;
        int L = 0, R = n - 1;
        while (L != R) {
            int M = (L + R) / 2;
            
            pair<int,int> range = make_pair(L, M);
            if (cache.count(range) == 0) {
                cout << "? " << range.first + 1 << " " << range.second + 1 << endl;
                cin >> cache[range];
                cache[range] = range.second - range.first + 1 - cache[range];
            }

            int value = cache[range];
            if (k <= value)
                R = M;
            else {
                k -= value;
                L = M + 1;
            }
        }

        cout << "! " << L + 1 << endl;
        dec(L, 0, n - 1);
    }
}