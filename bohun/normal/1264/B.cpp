#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl

using namespace std;

const int mod = 1e9 + 7;
const int nax = 1e6 + 111;


int pt(int a, int b) {int c = 1; while(b) {if(b & 1) c = 1ll * c * a % mod; a = 1ll * a * a % mod; b /= 2;} return c;}

int fac[nax];
int rev[nax];

void elo() {
	fac[0] = rev[0] = 1;
	for(int i = 1; i < nax; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		rev[i] = pt(fac[i], mod - 2);
	}
}

int a, b, c, d;
int t[4];
int ans[nax];

bool good(int x) {
	return 0 <= x && x <= 3;
}

void go(int x, int y) {
	t[0] = a;
	t[1] = b;
	t[2] = c;
	t[3] = d;
	if(x < 0 || x > 3)
		return;
	if(y < 0 || y > 3)
		return;
	t[x]--;
	t[y]--;
	if(t[x] < 0 || t[y] < 0)
		return;
	ans[1] = x;
	ans[2] = y;
	for(int i = 2; i < a + b + c + d; ++i) {
		if(good(ans[i] - 1) && t[ans[i] - 1] > 0) {
			ans[i + 1] = ans[i] - 1;
			t[ans[i] - 1]--;
			continue;
		}
		else if(good(ans[i] + 1) && t[ans[i] + 1] > 0) {
			ans[i + 1] = ans[i] + 1;
			t[ans[i] + 1]--;
			continue;
		}
		return;
	}

	printf("YES\n");
	for(int i = 1; i <= a + b + c + d; ++i) {
		printf("%d ", ans[i]);
	}
	exit(0);
}



int main() {
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if(a + b + c + d == 1) {
		int e = -1;
		if(a)
			e = 0;
		if(b)
			e = 1;
		if(c)
			e = 2;
		if(d)
			e = 3;
		printf("YES\n");
		printf("%d", e);
		return 0;
	}
	for(int i = 0; i < 4; ++i) {
		go(i, i + 1);
		go(i, i - 1);
	}
	printf("NO\n");




	return 0;
}