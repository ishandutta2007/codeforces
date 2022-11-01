#include <bits/stdc++.h>
 
using namespace std;
 
#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef double ld;
 
const ll mod = int(1e9) + 7, pq = 2, szz = 65536, ma = szz, szz1 = 8;
 
int get_int() {
	int k;
	scanf("%d", &k);
	re k;
}
 
ll n;
vector<ll> a, b;

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	//freopen(".out", "w", stdout);
    cin >> n;
    a.resize(n);
    b.resize(n);
	forn (i, n) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        b[i] = a[i];
        if (i + 1 < n) b[i] += a[i + 1];
    }
    forn (i, n) 
        cout << b[i] << " ";
	re 0;
}