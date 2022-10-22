//Missed me!?

#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200 + 2;

int f(int y){
	return y * y/2 + (y & 1);
}

bool check(int n, int x){
	int mx = 0;
	if (n & 1)
		mx = f(n/2) * 4 + 1 + ((n/2/2) * 4);
	else
		mx = f(n/2 - 1) * 4;

	if (n & 1){
		if (mx < x)	return false;
		if (x % 4 < 2)	return true;
		return mx - x > 2 || ((mx - x == 2) && (n > 3));
	}
	return mx >= x && x % 4 == 0;
}

int main(){
	int x;	cin >> x;
	int i;
	for (i = 1; i <= 10 * x; i++)
		if (check(i, x))	break;
	cout << i << endl;
	return 0;
}