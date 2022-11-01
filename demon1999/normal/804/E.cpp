#include <bits/stdc++.h>  
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll mod = ll(1e9) + 7;
  
const int ma = 2 * 256 * 1024;
  
int n;

void out(int a, int b) {
	cout << a << " " << b << "\n";
}

void solve(int a, int b, int c, int d) {
	out(a, b);
	out(c, d);
	out(b, d);
	out(a, c);
	out(a, d);
	out(b, c);
}

void solve(int a, int b, int c, int d, int e) {
	out(a, e);
	out(b, d);
	out(c, e);
	out(a, c);
	out(a, d);
	out(b, e);
	out(c, d);
	out(d, e);
	out(b, c);
	out(a, b);
}
void solve1(int a, int b, int c, int d) {
	out(a, d);
	out(b, c);
	out(a, c);
	out(b, d);
}

int main() {
    iostream::sync_with_stdio(0), cin.tie(0);
    //freopen("a.in", "r", stdin);
    cin >> n;
    if (n % 4 > 1) {
    	cout << "NO\n";
    	re 0;
    }
    cout << "YES\n";
    if (n % 4 == 0) {
    	for (int i = 0; i + 4 <= n; i+=4) {
    		solve(i + 1, i + 2, i + 3, i + 4);
    	}
    }
    if (n % 4 == 1) {
    	for (int i = 0; i + 4 < n; i+=4) {
    		solve(i + 1, i + 2, i + 3, i + 4, n);
    	}
    	n--;
    }
    for (int i = 0; i < n; i += 4) {
    	for (int j = i + 4; j < n; j += 2) {
    		solve1(i + 1, i + 2, j + 1, j + 2);
    		solve1(i + 3, i + 4, j + 1, j + 2);
    	}
    }
    re 0;
}