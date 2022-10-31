//this code was written by demon
#include <bits/stdc++.h>
//include "grader.h"

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define se second
#define fi first
#define gi get_int()
#define mp(a, b) make_pair(a, b)
#define sz(a) (int)a.size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int get_int() {
    int k;
    scanf("%d", &k);
    re k;
}

void my_assert(bool cc) {
    if (!cc) while(true);
}

int n, m, k, col[1000 * 1001], pr[1000001];


int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("kk.in", "r", stdin);
	//freopen(".out", "w", stdout);
	n = gi; k = gi;
	for (int i = 2; i <= 1000000; i++) {
		if (pr[i] == 0) {
			for (int j = i; j <= 1000000; j += i)
				if (pr[j] == 0) pr[j] = i;
		}
	}
	forn (i, n) {
		m = gi;
		while (m > 1) {
			int kk = 0, cc = pr[m];
			while (m % cc == 0) {
				kk++;
				m /= cc;
			}
			col[cc] = max(col[cc], kk);
		}
	}
	for (ll i = 2; i * i <= k; i++) {
		ll kk = 0;
		while (k % i == 0) {
			k /= i;
			kk++;
		}
		if (col[i] < kk) {
			printf("No");
			re 0;
		}
	}
	if (k > 1 && col[k] < 1) {
		printf("No");
		re 0;
	}
	printf("Yes");
    re 0;
}