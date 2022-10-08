#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define szz(x) (int)(x).size()
#define Fi first
#define Se second

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int IT_MAX = 1 << 17;

const int MX = 1000005;

int dp[2][55][2][105];
int in[20050];
int main() {
    int N, K, P, i, j, k, l;
    scanf("%d %d %d", &N, &K, &P);
    for(i = 1; i <= N; i++) scanf("%d", &in[i]);

    for(i = 0; i < 2; i++) for(j = 0; j <= K; j++) for(k = 0; k < 2; k++) for(l = 0; l < P; l++) dp[i][j][k][l] = -INF;
    dp[0][0][0][0] = 0;
    for(i = 1; i <= N; i++) {
        int t = i%2;
        for(j = 0; j <= K; j++) for(k = 0; k < 2; k++) for(l = 0; l < P; l++) dp[t][j][k][l] = -INF;
        for(j = 0; j <= K; j++) {
            for(k = 0; k < 2; k++) {
                for(l = 0; l < P; l++) {

                    if(k == 0) {
                        //dp[t][j][k][l] = max(dp[t][j][k][l], dp[1-t][j][k][l]);
                        if(j != K) dp[t][j+1][1][(l+in[i])%P] = max(dp[t][j+1][1][(l+in[i])%P], dp[1-t][j][k][l]);
                    }
                    else {
                       // dp[t][j][0][0] = max(dp[t][j][0][0], dp[1-t][j][k][l] + l);
                        dp[t][j][1][(l+in[i])%P] = max(dp[t][j][1][(l+in[i])%P], dp[1-t][j][k][l]);
                        if(j != K) dp[t][j+1][1][in[i]%P] = max(dp[t][j+1][1][in[i]%P], dp[1-t][j][k][l] + l);
                    }
                }
            }
        }
    }

    int mx = 0;
    for(i = 0; i <= K; i++) for(j = 0; j < 2; j++) for(k = 0; k < P; k++) if(dp[N%2][i][j][k] >= 0) mx = max(mx, dp[N%2][i][j][k] + k);
    return !printf("%d\n", mx);
}