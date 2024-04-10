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
int a, b;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &a, &b);
		if(a < b)
			swap(a, b);
		int c = a - b;
		a -= 2 * c;
		b -= c;
		if(a < 0 || b < 0 || a % 3) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
		
		
					
	
	return 0;
}