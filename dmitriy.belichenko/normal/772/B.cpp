#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <iomanip>
using namespace std;

#define mp make_pair
#define sqr(x) (x) * (x)
#define ld long double
typedef double ll;

const ll INF = 1e9, EPS = 1e-7;
int main(){
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector <ld> x(n);
	vector <ld> y(n);
	int i = 0;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	ld ans = 1e9* 1.42;
	for(int i = 0; i < n; i++){
		ld b = (x[(i+2) % n]-x[i]);
		ld a = (y[i]-y[(i+2) % n]);
		ld c = x[i]*y[(i+2) % n]-x[(i+2) % n]*y[i];
		ans = min(ans,abs(a*x[(i+1) % n]+b*y[(i+1) % n]+c)/sqrt(a*a+b*b));
	}
	cout << setprecision(30) << ans/2;
	return 0;
}