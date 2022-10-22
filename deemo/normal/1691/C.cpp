#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int n, k;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te; cin >> te;
    while (te--) {
        cin >> n >> k >> s;
        int c1 = 0;
        for (char c: s)
            if (c == '1') c1++;

        if (c1 == 0 || n == 1)
            cout << "0\n";
        else {

            int fs = 0;
            while (s[fs] != '1') fs++;
            int sc = n-1;
            while (s[sc] != '1') sc--;
            if (fs == sc) {
                if (k >= n-1-fs)
                    cout << "1\n";
                else if (k >= fs)
                    cout << "10\n";
                else
                    cout << "11\n";
            } else {
                if (k >= n-1-sc) {
                    swap(s[n-1], s[sc]);
                    k -= n-1-sc;
                }
                if (k >= fs) {
                    swap(s[0], s[fs]);
                }
                int sm = 0;
                for (int i = 0; i + 1 < n; i++)
                    sm += atoi(s.substr(i, 2).c_str());
                cout << sm << "\n";
            }
        }
    }
    return 0;
}