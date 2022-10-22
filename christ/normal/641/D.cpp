#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define double ld
const int MN = 3e5+3, MOD = 1e9+7;
const double EPS = 1e-15;
int main() {
	int n;
	scanf ("%d",&n);
	vector<double> mn(n+1), mx(n+1), a(n+1), b(n+1);
	for (int i = 1; i <= n; i++) scanf ("%Lf",&mx[i]);
	for (int i = 1; i <= n; i++) scanf ("%Lf",&mn[i]);
	double asum = 0, bsum = 0;
	for (int i = 1; i <= n; i++) {
		double bb = asum-bsum-mx[i]-mn[i], c = mx[i]-asum*mx[i]-asum*mn[i];
		double ree = bb*bb-4*c;
		if (ree < 0) ree += EPS;
		a[i] = (-bb+sqrtl(ree))/2;
		b[i] = (mx[i]-a[i]*bsum)/(asum+a[i]);
		asum += a[i];
		bsum += b[i];
	}
	for (int i = 1; i <= n; i++) printf ("%.8Lf ",a[i]);
	printf ("\n");
	for (int i = 1; i <= n; i++) printf ("%.8Lf ",b[i]);
	printf ("\n"); 
    return 0;
}