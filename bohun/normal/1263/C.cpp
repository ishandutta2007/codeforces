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

int T;
int n;
map <int, int> mapa;
 
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		mapa.clear();
		mapa[0] = 1;
		int N = 1;
		while(N <= n) {
			mapa[n / N] = 1;
			N = (n / (n / N)) + 1;
		}
		printf("%d\n", ss(mapa));
		for(auto it : mapa)
			printf("%d ", it.fi);
		printf("\n");
		
	}

	
	
	
	
	return 0;
}