#include <iostream>
#include <string.h>
#include <vector>
#include <memory.h>

using namespace std;

char s[1<<17];
int n, k;

vector<int> cur, nxt;
long long sum[26];

void solve() {
    cin >> s;
    cin >> k;
    n = strlen(s);
    for (int i = 0; i < n; i++) cur.push_back(i);

    if (k > 1LL * n * (n+1) / 2) {
        cout << "No such line." << endl;
        return;
    }

    int l = 0;
    while (true) {
        memset(sum, 0, sizeof sum);
        for (int i = 0; i < cur.size(); i++) if (cur[i] + l < n) sum[s[cur[i] + l] - 'a'] += n - l - cur[i];
/*
        for (int i = 0; i < 26; i++) cerr << sum[i] << ' ';
        cerr << endl;
*/
        for (int c = 0; c < 26; c++) {
            if (sum[c] < k) {
                k -= sum[c];
            } else {
//                cerr << (char)(c+'a') << endl;
                for (int i = 0; i < cur.size(); i++) if (cur[i] + l < n && s[cur[i] + l] - 'a' == c) nxt.push_back(cur[i]);
                if (nxt.size() >= k) {
//                    cerr << "start " << nxt[0] << endl;
                    for (int j = 0; j <= l; j++) printf("%c", s[nxt[0]+j]);
                    cout << endl;
                    return;
                } else {
                    k -= nxt.size();
                }

                nxt.swap(cur);
                nxt.clear();
                break;
            }
        }
        l++;
/*
        cerr << k << ' ' << l << endl;
        for (int i = 0; i < cur.size(); i++) cerr << cur[i] << ' ';
        cerr << endl << endl;
*/
    }
}

int main() {
    solve();
    return 0;
}