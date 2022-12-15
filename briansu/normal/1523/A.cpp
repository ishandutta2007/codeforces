#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXn = 1e4 + 5;
int nxt[MAXn], prv[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        for (int i = 0, lst = -1; i < n; i++) {
            if (s[i] == '1')
                lst = i;
            prv[i] = lst;
        }
        for (int i = n - 1, lst = -1; i >= 0; i--) {
            if (s[i] == '1')
                lst = i;
            nxt[i] = lst;
        }
        for (int i = 0; i < n; i++)
            if (s[i] == '0') {
                if (prv[i] != -1 && nxt[i] != -1) {
                    if (i - prv[i] != nxt[i] - i && min(i - prv[i], nxt[i] - i) <= m)
                        s[i] = '1';
                }
                else if (prv[i] != -1) {
                    if (i - prv[i] <= m)
                        s[i] = '1';
                }
                else if (nxt[i] != -1) {
                    if (nxt[i] - i <= m)
                        s[i] = '1';
                }
            }
        cout << s << "\n"; 
    }
    
}