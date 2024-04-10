#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        int n;
        cin >> n;
        string s;
        while (n>=2) {
            s += '1';
            n-=2;
        }
        if (n == 1) {
            s.back() = '7';
        }
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
    return 0;
}