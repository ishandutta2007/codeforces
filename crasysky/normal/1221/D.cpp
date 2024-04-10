#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000006;
int a[maxn], b[maxn];
long long f[maxn][3];
int main(){
	int T;
	cin >> T;
	while (T --){
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++ i)
			scanf("%d %d", &a[i], &b[i]);
		f[1][0] = 0, f[1][1] = b[1], f[1][2] = 2 * b[1];
		for (int i = 2; i <= n; ++ i)
			f[i][0] = f[i][1] = f[i][2] = 1LL << 60;
		for (int i = 1; i < n; ++ i)
			for (int j = 0; j <= 2; ++ j)
				for (int k = 0; k <= 2; ++ k)
					if (a[i] + j != a[i + 1] + k)
						f[i + 1][k] = min(f[i + 1][k], f[i][j] + k * b[i + 1]);
		long long ans = min(f[n][0], min(f[n][1], f[n][2]));
		cout << ans << endl;
	}
}