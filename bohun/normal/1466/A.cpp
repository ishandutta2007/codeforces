#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	
	
int n, a[105];	
	
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		vector<int> b;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				b.push_back(a[j] - a[i]);
		sort(b.begin(), b.end());
		b.erase(unique(b.begin(), b.end()), b.end());
		printf("%d\n", (int)b.size());
	}
	
	return 0;
}