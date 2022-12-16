#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const int NMAX = 100100;
const int PMAX = 17;
const int INF = 0x3f3f3f3f;
ll n;
int p;
char a[PMAX][PMAX];
char forb[PMAX][PMAX][1<<PMAX];
//char forbb[1<<PMAX];
char forbb[1<<PMAX];
int dp[1<<PMAX];
char s[NMAX];
int loc[PMAX];
int cnt[PMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> p;
    cin >> (s+1);
    for(int i=1;i<=n;++i) {
        s[i] -= 'a';
        cnt[s[i]]++;
    }
    for(int i=0;i<p;++i) {
        for(int j=0;j<p;++j) {
            cin >> a[i][j];
            a[i][j] -= '0';
        }
    }
    map<int, int> ord;
    for(int i=1;i<=n;++i) {
        int bits = 0;
        for(auto it = ord.rbegin(); it != ord.rend(); ++it) {
            if(a[it->second][s[i]] == 0) {
                forb[min((char) it->second, s[i])][max((char) it->second,s[i])][bits]=1;
                forbb[bits] = 1;
            }
            bits |= (1<<(it->second));
            if(it->second == s[i]) break;
        }
        if(loc[s[i]]) {
            ord.erase(loc[s[i]]);
        }
        ord[i] = s[i];
        loc[s[i]] = i;
    }
    cerr << "!! " << endl;
    for(int i=0;i<p;++i) {
        for(int j=i;j<p;++j) {
            for(int b=0;b<(1<<p);++b) {
                if(!forb[i][j][b]) continue;
                for(int k=0;k<p;++k) {
                    if((b&(1<<k)) || k == i || j == k) continue;
                    forbb[b^(1<<k)] = 1;
                    forb[i][j][b^(1<<k)] = 1;// |= forb[i][j][b] |= forb[i][j][b^(1<<k)];
                }
            }
        }
    }
    cerr << "!!" << endl;
    /*
    for(int i=0;i<p;++i) {
        for(int j=i;j<p;++j) {
            int m = (1<<p)-1;
            m ^= ((1<<j)|(1<<i));
            for(int k=0;k<(1<<p);++k) {
                forbb[k] |= forb[i][j][k];
            }
        }
    } */
    int ans = 1;
    dp[0] = 1;
    for(int i=1;i<(1<<p);++i) {
        if(forbb[i]) continue;
        for(int j=0;j<p;++j) {
            if(((1<<j)&i) && dp[i^(1<<j)]) {
                dp[i] = dp[i^(1<<j)] + cnt[j];
                ans = max(ans, dp[i]);
                break;
            }
        }
    }
    cout << n-ans+1 << endl;
    return 0;
}