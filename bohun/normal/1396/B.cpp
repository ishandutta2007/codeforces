#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ss(x) (int) x.size()

using ll = long long;

using namespace std;

const int N = 1e5 + 10;

int T, n, a[N];

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++i) scanf ("%d", a + i);
		
		int kto = 1, last = 0;
		
		while (true) {
			int opt = 0;
			for (int i = 1; i <= n; ++i)
				if (a[i] > 0 && i != last && a[i] > a[opt])
					opt = i;
			
			if (!opt) break;
			
			kto ^= 1;
			
			a[opt]--;
			
			last = opt;
		}
		
		printf (kto == 0 ? "T\n" : "HL\n");
	}
	
	
	return 0;
}