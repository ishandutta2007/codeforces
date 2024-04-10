#include<iostream>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;

ull a, b, x, y;

int main(){
	cin >> a >> b;
	ull temp = a;
	for (int i = 0; i < 64; i++)
		if (b>>i&1)
			y |= 1ll<<i;
	if (y > a){
		cout << "-1\n";
		return 0;
	}
	a -= y;
	if (a & 1){
		cout << "-1\n";
		return 0;
	}

	a >>= 1;
	for (int i = 0; i < 64; i++)
		if (a>>i&1){
			if (y>>i&1){
				cout << "-1\n";
				return 0;
			}
			x |= 1ll<<i;
			y |= 1ll<<i;
		}

	if (x + y ^ temp){
		printf("-1\n");
		return 0;
	}

	cout << x << " " << y << "\n";
	return 0;
}