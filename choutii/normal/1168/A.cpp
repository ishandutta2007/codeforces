#include<bits/stdc++.h>

using namespace std; 

const int MaxN = 300010;

int n, m, a[MaxN];
 
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int l = -1, r = m - 1, ans = 0;
	while (l <= r) {
		int mid = l + r >> 1, mx = 0, p = 1;
		for (int i = 1; i <= n; i++)
			if (a[i] + mid < m) {
				if (mx > a[i] + mid)
					p = 0;
				mx = max(mx, a[i]);
			} else 
				if (mx > a[i] + mid - m)
					 mx = max(mx, a[i]); 
		if (p)
			ans = mid, r = mid - 1;
		else
			l = mid + 1;
	} 
	
	printf("%d\n", ans);
	return 0;
}