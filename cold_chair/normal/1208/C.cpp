#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 2005;

int n;

int a[N][N];

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d", &n);
	int x = 0, y = 0;
	fo(i, 1, n) {
		fo(j, 1, n) {
			a[i][j] = x + y;
			x += 4;
			if(x >= n * n) x = 0, y ++;
			pp("%d ", a[i][j]);
		}
		hh;
	}
}