#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
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

int cnt[1050];
int main() {
    int N, i;
    scanf("%d", &N);
    for(i = 1; i <= 2*N-2; i++) {
        int t;
        scanf("%d", &t);
        cnt[t]++;
    }

    int ans = 0;
    for(i = 1; i <= N; i++) if(cnt[i] == 1) ans++;
    return !printf("%d\n", ans);
}