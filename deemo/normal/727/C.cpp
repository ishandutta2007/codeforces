#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 10;

int n, a[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cout << "? 1 2" << endl;
	int x, y, z;
	cin >> x;
	cout << "? 1 3" << endl;
	cin >> y;
	cout << "? 2 3" << endl;
	cin >> z;
	a[0] = ((x+y+z) - z-z)/2;
	a[1] = x - a[0];
	a[2] = y - a[0];
	for (int i = 3; i < n; i++){
		cout << "? 1 " << i+1 << endl;
		cin >> a[i];
		a[i] -= a[0];
	}
	cout << "! ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}