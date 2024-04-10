#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1000];
int b[1000];

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a,a+n);

	for(int i = 0; i < (n+1)/2; ++i)
		b[i*2] = a[i];
	for(int i = 0; i < n/2; ++i)
		b[2*i+1] = a[(n+1)/2+i];
	for(int i = 1; i < n; ++i) {
		if(i&1) {
			if(b[i-1] > b[i]) {
				cout << "Impossible\n";
				return 0;
			}
		} else {
			if(b[i-1] < b[i]) {
				cout << "Impossible\n";
				return 0;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		cout << b[i] << " ";
	}
	cout << "\n";
}