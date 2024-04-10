#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
	int x, y, xx, yy;	cin >> x >> y >> xx >> yy;
	int tx = abs(x - xx);
	int ty = abs(y - yy);

	if (tx && ty && tx != ty){
		cout << -1 << endl;
		return	0;
	}
	if (tx && ty){
		cout << x << " " << yy << " " << xx << " " << y << "\n";
		return	0;
	}

	if (tx == 0){
		cout << x + ty << " " << yy << " " << x + ty << " " << y << "\n";
		return	0;
	}

	cout << x << " " << y + tx << " " << xx << " " << y + tx << "\n";
	return	0;
}