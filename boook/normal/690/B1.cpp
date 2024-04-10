#include <bits/stdc++.h>
using namespace std;

#define maxn 55

char s[maxn][maxn], ans[maxn][maxn];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		scanf("%s" ,s[i] + 1);	
	}
	
	int l = 100, r = 0;
	int u = 100, d = 0;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(s[i][j] == '4') {
				l = min(l, i);
				r = max(r, i);
				u = min(u, j);
				d = max(d, j);	
			}
		}
	}
	
//	cout << l << ' ' << r << ' ' << u << ' ' << d << endl;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			ans[i][j] = '0';
		}
	}
	for(int i = l; i <= r; i++) {
		for(int j = u; j <= d; j++) {
			ans[i][j] = '4';
		}	
	}
	for(int i = l; i <= r; i++) {
		ans[i][u - 1] = '2';
		ans[i][d + 1] = '2';
	}
	for(int i = u; i <= d; i++) {
		ans[l - 1][i] = '2';
		ans[r + 1][i] = '2';	
	}
	ans[l - 1][u - 1] = ans[l - 1][d + 1] = ans[r + 1][u - 1] = ans[r + 1][d + 1] = '1';
	
	int flag = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(s[i][j] != ans[i][j]) {
				flag = 0;	
			}
		}
	}
	
	puts(flag ? "Yes" : "No");
	return 0;
}