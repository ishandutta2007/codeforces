#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int N = 100100;
int nxt[N][26];
char s[N], t[N];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        int last[26];
        for (int i=0; i<26; ++i) {
            last[i] = -1;
        }
        cin >> (s+1) >> (t+1);
        int n = strlen(s+1), m = strlen(t+1);
        for (int i=n; i>=0; --i) {
            for (int j=0; j<26; ++j) {
                nxt[i][j] = last[j];
                //cerr << " NXT " << i << " " << j << " = " << last[j] << endl;
            }
            if (i > 0) {
                last[s[i]-'a'] = i;
            }
        }

        int ops = 1;
        int pos = 0;
        for (int i=1; i<=m; ++i) {
            int c = t[i]-'a';
            if (nxt[pos][c] == -1) {
                if (pos == 0) {
                    ops = -1;
                    break;
                }
                ++ops;
                pos = 0;
                --i;
                continue;
            }
            pos = nxt[pos][c];
        }
        cout << ops << "\n";
    }
    return 0;
}