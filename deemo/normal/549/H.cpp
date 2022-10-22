//Be Careful what you Wish for..

#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef long double ld;

ld a, b, c, d;

int main(){
	cin >> a >> b >> c >> d;
	ld beg = 0, end = 1e13;
	for (int i = 0; i < 200; i++){
		ld mid = (beg + end)/ 2;
		ld l1 = 1e20, r1 = -1e20;
		for (int i = -1; i <= 1; i += 2)
			for (int j = -1; j <= 1; j += 2){
				l1 = min(l1, (a + mid * i) * (d + mid * j));
				r1 = max(r1, (a + mid * i) * (d + mid * j));
			}
		ld l2 = 1e20, r2 = -1e20;
		for (int i = -1; i <= 1; i += 2)
			for (int j = -1; j <= 1; j += 2){
				l2 = min(l2, (b + mid * i) * (c + mid * j));
				r2 = max(r2, (b + mid * i) * (c + mid * j));
			}

		if (r2 < l1 || r1 < l2)
			beg = mid;
		else
			end = mid;
	}
	cout << fixed << setprecision(12);
	cout << beg << "\n";
	return	0;
}