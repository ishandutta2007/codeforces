#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

void solve() {
    int k; scanf("%d", &k);
    printf("+------------------------+\n");
    FOR(i, 0, 4) {
        printf("|");
        int d = k > i ? 1 : 0;
        if (i != 2) {
            if (k >= 4) d += (k - 4) / 3;
            int r = (k - 4) % 3;
            if (i <= 1 && r > i) d++; else if (i > 2 && r >= i) d++;
            FOR(j, 0, 11) if (j < d) printf("O."); else printf("#.");
            if (!i) printf("|D|"); else printf("|.|");
        }
        else {
            if (d) printf("O.......................|"); else printf("#.......................|");
        }
        if (i == 0 || i == 3) printf(")\n"); else printf("\n");
    }
    printf("+------------------------+\n");
}

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}