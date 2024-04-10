#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const int MAXV = 100;
const double pi = 4 * atan(1);

int n;
double coef, sdl[105], sx, sy;

int main()
{
	scanf("%d", &n);
	if(n <= 4) {
		printf("No solution\n"); return 0;
	}
	rep(i, n) sdl[i] = 500.0;
	coef = 2 * cos(2 * pi / n);
	rep(i, n) {
		sdl[i] -= coef * i; sdl[(i - 1 + n) % n] += i; sdl[(i + 1) % n] += i;
	}
	
	sx = sy = 0;
	rep(i, n) {
		printf("%.10lf %.10lf\n", sx, sy);
		sx += sdl[i] * cos(2 * pi / n * i);
		sy += sdl[i] * sin(2 * pi / n * i);
	}
	return 0;
}