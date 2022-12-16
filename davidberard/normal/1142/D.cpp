#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int bshift[11][11];
int cshift[11][11];

int nxt[11*11*11][10];

int dp[2][11*11*11];

void setup() {
    for(int i=0; i<11; ++i) {
        for(int j=0; j<11; ++j) {
            for(int k=0; k<i; ++k) {
                bshift[i][j] += 11-k+j;
                cshift[i][j] += k+j;
            }
            bshift[i][j] %= 11;
            cshift[i][j] %= 11;
        }
    }
}
void build() {
    int e3 = 11*11*11;
    for(int i=0; i<e3; ++i) {
        int a = i/11/11;
        int b = (i/11)%11;
        int c = i%11;
        int bb = bshift[b][(a+10)%11];
        int cc = cshift[c][(a+1)%11];
        for(int j=0; j<a; ++j) {
            int by = (bb + j)%11;
            int cy = (cc + a-j-1)%11;
            int ay = (by+c+a+1)%11;
            nxt[i][j] = cy+11*(by+11*ay);
        }
        for(int j=a; j<10; ++j) {
            nxt[i][j] = -1;
        }
    }
}

char s[100100];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    setup();
    build();
    cin >> s;
    int n = strlen(s);
    ll ans = 0;
    for(int i=n-1; i>=0; --i) {
        int me = i&1;
        int old = me^1;
        for(int j=0; j<11*11*11; ++j) {
            if(nxt[j][s[i]-'0'] == -1) dp[me][j] = 0;
            else dp[me][j] = dp[old][nxt[j][s[i]-'0']]+1;
        }
        //cerr << " at " << i << " add " << dp[me][1210] << " .. " << nxt[1210][s[i]-'0'] << endl;
        if(s[i] != '0') {
            ans += dp[me][1210];
        }
    }
    cout << ans << endl;
    return 0;
}