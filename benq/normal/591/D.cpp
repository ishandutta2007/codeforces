#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;
double PI = 4*atan(1);

double quad (double a, double b, double c) {
	return (-b+sqrt(b*b-4*a*c))/(2*a);
}

int main() {
	double x1,y1,x2,y2,v,t,vx,vy,wx,wy;
	cin >> x1 >> y1 >> x2 >> y2 >> v >> t >> vx >> vy >> wx >> wy;
	
	x2 -= x1, y2 -= y1;
	cout << fixed << setprecision(10);
	double k = quad (v*v-vx*vx-vy*vy,2*vy*y2+2*vx*x2,-x2*x2-y2*y2);
	if (k <= t) cout << k;
	else {
		x2 -= t*vx, y2 -=t*vy;
		cout << (t+quad(v*v-wx*wx-wy*wy,2*t*v*v+2*y2*wy+2*wx*x2,t*t*v*v-x2*x2-y2*y2));
	}
	return 0;
}