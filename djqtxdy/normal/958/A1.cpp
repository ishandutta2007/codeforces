#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n;
char a[N][N], b[N][N], t1[N][N], t2[N][N], t3[N][N], t4[N][N];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	memcpy(t1, a, sizeof(a));
	for (int _ = 0; _ < 2; _++) { //|
		memcpy(t2, t1, sizeof(t1));
		for (int _2 = 0; _2 < 2; _2++) { //-
			memcpy(t3, t2, sizeof(t2));
			for (int rr = 0; rr < 3; rr++) {
				bool flag = true;
				for (int i = 0; i < n && flag; i++)
					for (int j = 0; j < n && flag; j++)
						if (t3[i][j] != b[i][j])
							flag = false;
				if (flag) {
					puts("Yes");
					return 0;
				}
				memcpy(t4, t3, sizeof(t3));
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						t3[j][n - i - 1] = t4[i][j];
			}
			for (int j = 0; j < n; j++)
				for (int i = 0; i < n / 2; i++)
					swap(t2[i][j], t2[n - i - 1][j]);
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n / 2; j++)
				swap(t1[i][j], t1[i][n - j - 1]);
	}
	puts("No");
	return 0;
}
/*
 0123
0....
1....
2....
3....
*/