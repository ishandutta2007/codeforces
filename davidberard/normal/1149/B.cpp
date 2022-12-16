#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int INF = 100050;

int n, q;
int dp[260][260][260];
int nxt[100100][26];
int lst[26];
char s[100100];
char t[260][4];
int p[4];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    cin >> (s+1);
    for(int i=0;i<26;++i) {
        lst[i] = INF;
    }
    for(int i=n; i>=0; --i) {
        for(int j=0; j<26; ++j) {
            nxt[i][j] = lst[j];
            //cerr << " nxt " << i << " " << j << " = " << nxt[i][j] << endl;
        }
        lst[s[i]-'a'] = i;
    }
    for(int j=0; j<26; ++j) {
        nxt[INF][j] = INF;
    }
    for(int i=0; i<260; ++i) {
    for(int j=0; j<260; ++j) {
    for(int k=0; k<260; ++k) {
        dp[i][j][k] = INF;
    }}}
    dp[0][0][0] = 0;
    for(int qq=0; qq<q; ++qq) {
        string a, c;
        int b;
        cin >> a >> b;
        if(a[0] == '+') {
            cin >> c;
            t[p[b]++][b] = c[0];
            int x = (b==1 ? p[1] : 0);
            int y = (b==2 ? p[2] : 0);
            int z = (b==3 ? p[3] : 0);
            for(int i=x; i<=p[1]; ++i) {
                for(int j=y; j<=p[2]; ++j) {
                    for(int k=z; k<=p[3]; ++k) {
                        dp[i][j][k] = INF;
                        if(i > 0) {
                            dp[i][j][k] = min(dp[i][j][k], nxt[dp[i-1][j][k]][t[i-1][1]-'a']);
                        }
                        if(j > 0) {
                            dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j-1][k]][t[j-1][2]-'a']);
                        }
                        if(k > 0) {
                            dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k-1]][t[k-1][3]-'a']);
                        }
                    }
                }
            }
            //cerr << " .. " << t[0][1] << endl;
            cout << (dp[p[1]][p[2]][p[3]] <= n ? "YES" : "NO") << "\n";
        } else {
            /*
            int x = (b==1 ? p[1] : 0);
            int y = (b==2 ? p[2] : 0);
            int z = (b==3 ? p[3] : 0);
            for(int i=x; i<=p[1]; ++i) {
                for(int j=y; j<=p[2]; ++j) {
                    for(int k=z; k<=p[3]; ++k) {
                        dp[i][j][k] = INF;
                    }
                }
            } */
            --p[b];
            cout << (dp[p[1]][p[2]][p[3]] <= n ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}