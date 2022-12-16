#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

char t[1000];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        int first = 1e9, last = 1;
        cin >> (t+1);
        int n = 0;
        for (int i=1; t[i]; ++i) {
            n = i;
            if (t[i] == '1') {
                first = min(first, i);
                last = i;
            }
        }
        int rem = 0;
        for (int i=first; i<=last; ++i) {
            rem += (t[i] == '0');
        }
        cout << rem << "\n";

    }
    return 0;
}