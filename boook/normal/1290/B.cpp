#include <bits/stdc++.h>
using namespace std;
#define maxn 200000 + 10

string s;
int t, c[maxn][30];

int main() {
    cin.tie(0), cout.sync_with_stdio(0);
    cin >> s >> t;
    for (int i = 0; i < s.size(); ++ i)
        c[i][s[i] - 'a'] ++;
    for (int i = 1; i < s.size(); ++ i) 
        for (int j = 0; j < 30; ++ j) c[i][j] += c[i - 1][j];

    while (t --) {
        int ql, qr;
        cin >> ql >> qr;
        ql --, qr --;
        if (qr - ql + 1 == 1) cout << "Yes" << endl;
        else {
            if (s[ql] != s[qr]) cout << "Yes" << endl;
            else {
                int kind = 0;
                for (int i = 0; i < 30; ++ i) {
                    int tmp = c[qr][i];
                    if (ql != 0) tmp -= c[ql - 1][i];
                    if (tmp != 0) kind ++;
                }
                if (kind >= 3) cout << "Yes" << endl;
                else cout << "No" << endl;
            }
        } 
    }
    return 0;
}