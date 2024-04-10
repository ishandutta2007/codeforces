#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 50000;

bool notprime[50505];
int nxt[50505];

int main() {
	for(int i = 2; i <= MX; i++) {
		if(notprime[i]) continue;
		for(ll j = (ll)i * i; j <= MX; j += i) {
			notprime[j] = true;
		}
	}

	int t = MX + 1;
	for(int i = MX; i >= 1; i--) {
		if(!notprime[i]) t = i;
		nxt[i] = t;
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		int d; scanf("%d", &d);
		int a = nxt[d + 1];
		int b = nxt[a + d];
		printf("%d\n", a * b);
	}
	return 0;
}