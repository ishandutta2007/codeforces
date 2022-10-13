#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    long long l, r, k;
    cin >> l >> r >> k;


    long long bb = 0, nbb = 1;

    bool no = 0;

    while(nbb / k == bb) {
        if(nbb >= l && nbb <= r) {
            cout << nbb << " ";
            no = 1;
        }

        bb = nbb;
        nbb = bb * k;
    }

    if(!no) cout << -1;

    return 0;
}