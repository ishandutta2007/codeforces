#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

char kth[256];
char grid[110][110];
char ans[110][110];
int r, c, k;
int need[110];

void solve() {
    cin >> r >> c >> k;
    int have = 0;
    for (int i=0; i<r; ++i) {
        cin >> grid[i];
        for (int j=0; j<c; ++j) {
            have += (grid[i][j] == 'R');
        }
    }
    for (int i=0; i<k; ++i) {
        need[i] = have/(k-i);
        //cerr << " !! " << need[i] << endl;
        have-=need[i];
    }
    need[k-1] ++;

    int cur = 0;
    int q = 0;
    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            if (grid[i][j] == 'R') {
                ans[i][j] = kth[q];
                if (++cur >= need[q]) {
                    //cerr << "!! switch " << " " << i << " " << j << ":" << cur << " " << need[q]<< endl;
                    ++q;
                    cur = 0;
                }
            } else {
                ans[i][j] = kth[q];
            }
        }
        ++ i;
        if (i >= r) continue;
        for (int j=c-1; j>=0; --j) {
            if (grid[i][j] == 'R') {
                ans[i][j] = kth[q];
                if (++cur >= need[q]) {
                    //cerr << "!! switch " << i << " " << j << endl;
                    ++q;
                    cur = 0;
                }
            } else {
                ans[i][j] = kth[q];
            }
        }
    }
    for (int i=0; i<r; ++i) {
        ans[i][c] = 0;
        cout << ans[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int i = 0;
    for (char c='0'; c<='9'; ++c) {
        kth[i++] = c;
    }
    for (char c='A'; c<='Z'; ++c) {
        kth[i++] = c;
    }
    for (char c='a'; c<='z'; ++c) {
        kth[i++] = c;
    }
    int TT;
    cin >> TT;
    while(TT--) {
        solve();
    }
    return 0;
}