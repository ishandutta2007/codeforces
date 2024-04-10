//Kinda feels like deja vu
//I wanna get away from this place I do
//but I can't and I won't
//say I try, but I know that's a lie
//cause I don't and why I just dont know.. 

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long double ld;

int main(){
	int h, r;	cin >> r >> h;
	int ans = h/ r * 2;
	h %= r;
	ld x = sqrt(3)/2 * r;
	if (x + r <= r + h)
		cout << ans + 3 << endl;
	else if (r <= 2 * h)
		cout << ans + 2 << endl;
	else	
		cout << ans + 1 << endl;
	return 0;	
}