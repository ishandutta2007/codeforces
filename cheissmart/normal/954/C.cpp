#include <iostream>

using namespace std;

int abs(int a) {
	return a < 0 ? -a : a;
}

int main()
{
	int n, a[200087];
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	int y = -1;
	for(int i=0;i<n-1;i++) {
		if(abs(a[i]-a[i+1]) != 1) {
			if(y == -1) y = abs(a[i]-a[i+1]);
			if(abs(a[i]-a[i+1]) != y) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	if(y == 0) {
		cout << "NO" << endl;
		return 0;
	}
	for(int i=0;i<n-1 && y != -1;i++) {
		if(a[i] % y == 0 && a[i+1]-a[i] == 1) {
			cout << "NO" << endl;
			return 0;
		}
		if(a[i] % y == 1 && a[i+1]-a[i] == -1) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	if(y == -1)
		cout << 1 << " " << 1000000000 << endl;
	else 
		cout << 1000000000 << " " << y << endl;
}