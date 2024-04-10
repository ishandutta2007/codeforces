#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<int, int> memo;
int n;

int ask(int i) {
        if (i <= 0 || i > n)
                return (int) 1e9;
        if (!memo.count(i)) {
                cout << "? " << i << endl;
                cin >> memo[i];
        }
        return memo[i];
}

signed main() {
        cin >> n;
        int l = 1, r = n;
        while (l < r) {
                assert(ask(l - 1) > ask(l) && ask(r) < ask(r + 1));
                /// > ? ? ? ? ? ? ? < undeva trb sa fie o tranzitie de la > la < deci undeva avem un minim local
                int m = (l + r) / 2;
                if (ask(m) < ask(m + 1))
                        r = m;
                else
                        l = m + 1;
        }
        cout << "! " << l << endl;
}