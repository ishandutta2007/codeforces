#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

const int mod = 1e9 + 7;
const int nax = 2e5 + 111;

int pt(int a, int b) {
	int c = 1;
	while(b) {
		if(b & 1)
			c = 1ll * c * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
	}
	return c;
}

char s[505];
int ile[10];
int p[2];

int main () {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s + 1);
		for(int i = 0; i < 10; ++i)
			ile[i] = 0;
		int n = strlen(s + 1);
		for(int i = 1; i <= n; ++i) {
			ile[s[i] - '0']++;
		}
		int sum = 0;
		p[0] = p[1] = 0;
		for(int i = 1; i < 10; ++i) {
			sum += i * ile[i];
			p[i % 2] += ile[i];
		}
		if(sum % 3 == 0 && ((ile[0] > 0 && p[0] > 0) || ile[0] > 1))
			printf("red\n");
		else
			printf("cyan\n");
	}



	return 0;
}