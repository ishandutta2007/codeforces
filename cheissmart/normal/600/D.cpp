#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define double long double

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;
const double TT = acos(-1);

int main()
{
	double x1,y1,r1,x2,y2,r2,d,alpha,beta,a1,a2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	d = sqrt((x2 - x1) * (x2 - x1) +(y2 - y1) * (y2 - y1));
	cout << fixed << setprecision(10);
	if (d > r1 + r2) return cout << 0, 0;
	if (d <= abs(r2 - r1) && r1 >= r2) return cout << TT * r2 * r2, 0;
	if (d <= abs(r2 - r1) && r2 >= r1) return cout << TT * r1 * r1, 0;
	alpha = acos((r1 * r1 + d * d - r2 * r2)/(2 * r1 * d)) * 2;
	beta = acos((r2 * r2 + d * d - r1 * r1) / (2 * r2 * d)) * 2;
	a1 = 0.5 * beta * r2 * r2 - 0.5 * r2 * r2 * sin(beta);
	a2 = 0.5 * alpha * r1 * r1 - 0.5 * r1 * r1 * sin(alpha);
	cout << a1 + a2 << endl;;

}