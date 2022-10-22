#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;	

int T;
int n;

struct gao {
	int a, b, id;
	bool operator < (gao x) const {
		return a < x.a;
	}
};

gao a[200111]; 
			
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n - 1; ++i) {
			scanf("%d %d", &a[i].a, &a[i].b);
			a[i].id = i;
		}
		sort(a + 1, a + 2 * n);
		vector <int> x, y;
		ll sum1 = 0;
		ll sum2 = 0;
		for(int i = 1; i < 2 * n - 1; ++i) {
			if(i & 1) {
				sum1 += a[i].b;
				x.pb(a[i].id);
			}
			else {
				sum2 += a[i].b;
				y.pb(a[i].id);
			}
		}
		printf("YES\n");
		if(sum1 > sum2) {
			for(auto it : x) 
				printf("%d ", it);
			printf("%d ", a[2 * n - 1].id);
		}
		else {
			for(auto it : y)
				printf("%d ", it);
			printf("%d ", a[2 * n - 1].id);
		}
		printf("\n");
	}
		
	
	return 0;
}