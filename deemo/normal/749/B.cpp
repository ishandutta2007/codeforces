#include<bits/stdc++.h>

using namespace std;

#define Point pair<int, int>
#define X first
#define Y second
#define F first
#define S second

Point get(Point a, Point b, Point c){
	Point ret(b.X-(c.X-a.X), b.Y-(c.Y-a.Y));
	return ret;
}

int main(){
	Point a, b, c;
	cin >> a.X >> a.Y;
	cin >> b.X >> b.Y;
	cin >> c.X >> c.Y;

	cout << 3 << "\n";
	auto z = get(a,b,c);
	cout << z.F << " " << z.S << "\n";

	z = get(a,c,b);
	cout << z.F << " " << z.S << "\n";

	z = get(b,c,a);
	cout << z.F << " " << z.S << "\n";
	return 0;
}