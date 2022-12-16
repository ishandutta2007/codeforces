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

int n;
string s;
int a[26];

const int NMAX = 1010;
const int INF = 0x3f3f3f3f;
const ll mod = 1000000007;

ll dp1[NMAX];
int dp3[NMAX];
int good[NMAX][NMAX];
int have[26];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> s;
    for(int i=0; i<26; ++i) {
        cin >> a[i];
    }
    int ans2 = 0;
    memset(dp1, 0, sizeof dp1);
    memset(dp3, INF, sizeof dp3);
    for(int i=0; i<n; ++i) {
        memset(have, 0, sizeof have);
        int len = 0;
        int minlen = NMAX;
        for(int j=i; j<n; ++j) {
            minlen = min(minlen, a[s[j]-'a']);
            if(++len <= minlen) {
                ++good[i][j];
                ans2 = max(ans2, j-i+1);
            } else {
                break;
            }
        }
    }

    dp1[0] = 1;
    dp3[0] = 0;
    for(int i=0; i<n; ++i) {
        for(int j=i; j>=0 && good[j][i]; --j) {
            dp1[i+1] = (dp1[i+1]+dp1[j])%mod;
            dp3[i+1] = min(dp3[i+1], dp3[j]+1);
        }
    }
    cout << dp1[n] << "\n" << ans2 << "\n" << dp3[n] << endl;

    return 0;
}