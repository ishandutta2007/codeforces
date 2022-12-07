#include<bits/stdc++.h>
using namespace std;
int main() {
	for(;;) {
		string tmp;
		cin >> tmp;
		if(tmp == "end") break;
		int c = 1;
		for(;;) {
			cout << '?' << ' ' << c << ' ' << c * 2 << endl;
			string x;
			cin >> x;
			if(x == "x") {
				break;
			}else {
				c *= 2;
			}
		}
		int l = 1, r = c;
		while(l != r) {
			int mid = (l + r) / 2;
			cout << '?' << ' ' << mid << ' ' << mid * 2 << endl;
			string x;
			cin >> x;
			if(x == "x") {
				r = mid;
			}else l = mid + 1;
		}
		cout << '?' << ' ' << (l * 2 - 2) << ' ' << l * 2 - 1 << endl;
		string x;
		cin >> x;
		if(x == "x") {
			printf("! %d\n", l * 2 - 1);
		}else printf("! %d\n", l * 2);

	}
}