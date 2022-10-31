#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	char s[222] = {};
	scanf("%d%s", &n, s);
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		int x = 0, y = 0;
		for(int j = i; j < n; ++j) {
			switch(s[j]) {
				case 'U': y++; break; 
				case 'R': x++; break;
				case 'D': y--; break;
				case 'L': x--; break;
			}
			if(x == 0 and y == 0) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}