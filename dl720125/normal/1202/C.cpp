#include <bits/stdc++.h>
using namespace std;
 
char s[200010];
int minx[200010], maxx[200010], miny[200010], maxy[200010];
 
int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%s", s);
		int n = strlen(s);
		int x = 0, y = 0;
		for (int i = 0; i < n; i++){
			if (s[i] == 'W') y++;
			else if (s[i] == 'S') y--;
			else if (s[i] == 'A') x--;
			else if (s[i] == 'D') x++;
			minx[i] = maxx[i] = x, miny[i] = maxy[i] = y;
		}
		for (int i = n - 2; i >= 0; i--){
			minx[i] = min(minx[i], minx[i + 1]);
			maxx[i] = max(maxx[i], maxx[i + 1]);
			miny[i] = min(miny[i], miny[i + 1]);
			maxy[i] = max(maxy[i], maxy[i + 1]);
		}
		long long delx = (max(maxx[0], 0) - min(minx[0], 0) + 1ll);
		long long dely = (max(maxy[0], 0) - min(miny[0], 0) + 1ll);
		long long ans = delx * dely;
		x = 0, y = 0;
		int max1 = 0, min1 = 0, max2 = 0, min2 = 0;
		for (int i = 0; i < n; i++){
			// A
			int a = min(min1, minx[i] - 1), b = max(max1, maxx[i] - 1);
			a = min(a, x - 1), b = max(b, x - 1);
			ans = min(ans, (b - a + 1ll) * dely);
			// D
			a = min(min1, minx[i] + 1), b = max(max1, maxx[i] + 1);
			a = min(a, x + 1), b = max(b, x + 1);
			ans = min(ans, (b - a + 1ll) * dely);
			// W
			a = min(min2, miny[i] + 1), b = max(max2, maxy[i] + 1);
			a = min(a, y + 1), b = max(b, y + 1);
			ans = min(ans, delx * (b - a + 1ll));
			// S
			a = min(min2, miny[i] - 1), b = max(max2, maxy[i] - 1);
			a = min(a, y - 1), b = max(b, y - 1);
			ans = min(ans, delx * (b - a + 1ll));
			if (s[i] == 'W') y++;
			else if (s[i] == 'S') y--;
			else if (s[i] == 'A') x--;
			else if (s[i] == 'D') x++;
			min1 = min(min1, x), max1 = max(max1, x);
			min2 = min(min2, y), max2 = max(max2, y);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}