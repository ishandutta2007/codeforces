#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

double d(double x1, double y1, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
	IO_OP;
	
	double r, x1, y1, x2, y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	
	if(d(x1, y1, x2, y2) > r) {
		cout << fixed << setprecision(10) << x1 << " " << y1 << " " << r << endl;
		return 0;
	}
	if(d(x1, y1, x2, y2) < 1e-5) {
		cout << fixed << setprecision(10) << x1 << " " << y1+r/2 << " " << r/2 << endl;
		return 0;
	}
	double rr = (r + d(x1, y1, x2, y2)) / 2; 
	double xx = x2 + (x1 - x2) * (r + d(x1, y1, x2, y2))/2 / d(x1, y1, x2, y2);
	double yy = y2 + (y1 - y2) * (r + d(x1, y1, x2, y2))/2 / d(x1, y1, x2, y2);
	cout << fixed << setprecision(10) << xx << " " << yy << " " << rr << endl;

}