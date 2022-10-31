#include <iostream>

using namespace std;

int n,d,h;
int gc = 2;

void strain(int prev, int len) {
	if(len <= 0) return;
	cout << prev << " " << gc << "\n";
	strain(gc++,len-1);
}

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> d >> h;
	if(h > d || h < d/2.0 || (d < 2 && n > 2)) {
		cout << "-1\n";
		return 0;
	}
	strain(1,h);
	strain(1,d-h);
	while(gc <= n) {
		if(d == h) {
			cout << "2 " << gc << "\n";
		} else cout <<  "1 " << gc << "\n";
		++gc;
	}

	return 0;
}