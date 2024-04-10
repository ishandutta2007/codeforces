#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

struct po{
	double x, y;
	po(){}
	po(double _x, double _y) {
		x = _x, y = _y;
	}
	po operator+(const po t) const{
		return po(x+t.x, y+t.y);
	}
	po operator-(const po t) const{
		return po(x-t.x, y-t.y);
	}
	po operator*(const double t) const{
		return po(x*t, y*t);
	}
	double operator*(const po t) const{
		return x*t.y - y*t.x;
	}
	double len() {
		return sqrt(x*x+y*y);
	}
};

int main()
{
	IO_OP;

	int n;
	cin >> n;
	vector<po> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i].x >> v[i].y;
	v.PB(v[0]), v.PB(v[1]);
	double mn = DBL_MAX;
	for(int i=0;i<n;i++) {
		po p0 = v[i], p1 = v[i+1], p2 = v[i+2];
		mn = min(mn, abs((p1-p0)*(p2-p1)/((p2-p0).len())));
	}
	printf("%.10f\n", mn/2);
}