#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 5;

int n, m, t;

bool a[maxn][7];

bool solve(int x, int y){
	int ca = 0, cb = 0, cc = 0;
	for(int i=1;i<=n;i++){
		if(a[i][x] and a[i][y]) cc++;
		else if(a[i][x]) ca++;
		else if(a[i][y]) cb++;
		else return false;
	}
	if(ca > n / 2 or cb > n / 2) return false;
	return true;
}

int main() {
	int i, j;

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		for(i=1;i<=n;i++){
			for(j=1;j<=5;j++){
				int x;
				scanf("%d", &x);
				a[i][j] = x;
			}
		}

		bool flag = false;
		for(i=1;i<=5;i++){
			for(j=i+1;j<=5;j++){
				flag |= solve(i, j);
			}
		}
		printf(flag ? "YES\n" : "NO\n");
	}

	return 0;
}