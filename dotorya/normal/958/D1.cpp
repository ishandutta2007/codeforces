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

ll gcd(ll a, ll b) {
    return (a == 0)? b : gcd(b%a, a);
}

pll in[200050];
map <pll, int> Mx;
int main() {
    int N, i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        ll t1, t2, t3;
        scanf("\n(%lld+%lld)/%lld", &t1, &t2, &t3);

        //printf("%lld %lld %lld\n", t1, t2, t3);
        t1 += t2;
        ll g = gcd(t1, t3);
        t1 /= g, t3 /= g;
        in[i] = pll(t1, t3);
        Mx[in[i]]++;
    }
    for(i = 1; i <= N; i++) printf("%d ", Mx[in[i]]);
    return !printf("\n");
}