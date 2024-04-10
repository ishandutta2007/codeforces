#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int R, x1, x2, y1, y2;
	cin >> R >> x1 >> y1 >> x2 >> y2;
	
	int xoff = x2-x1;
	int yoff = y2-y1;
	if(x1 == x2 && y1 == y2) {
		ld nx = (ld)R/2+(ld)x1;
		ld ny = y1;
		ld nr = (ld)R/2;
		cout << fixed << setprecision(10) << nx << " " << ny << " " << nr << endl;
		return 0;
	}
	ld dist = sqrt((ld) xoff*xoff+(ld) yoff*yoff);
	if(R <= dist) {
		cout << x1 << " " << y1 << " " << R << endl;
		return 0;
	}

	ld xdir = -xoff/dist;
	ld ydir = -yoff/dist;
	ld xop = (ld) x1+xdir*R;
	ld yop = (ld) y1+ydir*R;
	ld nr = sqrt((xop-x2)*(xop-x2)+(yop-y2)*(yop-y2))/2;
	ld nx = (xop+x2)/2;
	ld ny = (yop+y2)/2;
	cout << fixed << setprecision(10) << nx << " " << ny << " " << nr << endl;

	return 0;
}