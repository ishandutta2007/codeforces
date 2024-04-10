#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;

int n, k;

int ask(int x) {
	printf("? %d\n", x + 1);
	fflush(stdout);
	int y;
	scanf("%d", &y);
	return y;
}

int main() {
	scanf("%d%d", &n, &k);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 	
	int sq = min(240, (int)sqrt(n));	
	uniform_int_distribution<ll>(max(1, sq / 2), sq)(rng);
	
	int x = 0, lst = 0;
	while (true) {
		x = (x + rng()) % n;
		lst = ask(x);
		if (lst <= k) continue;
		break;
	}
	
	int lst2 = 0;
	while (true) {
		lst2 = ask((x - 1 + n) % n);
		if (lst2 >= lst) {
			x = (x - 1 + n) % n;
			lst = lst2;
		}
		else break;
	}
	
	printf("! %d\n", (x - 1 + n) % n + 1);
	
	return 0;
}