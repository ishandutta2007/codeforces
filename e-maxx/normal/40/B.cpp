#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int n, m, x;
	cin >> n >> m >> x;

	for (int step=1; step<=x && n>=1 && m>=1; ++step) {
		int nn=n-2, mm=m-2;

		int bord = 0;
		for (int i=0; i<n; ++i) {
			for (int j=0; ; ) {
				bord += ! ((i+j) & 1);

				if (j == m-1)
					break;
				if (i==0 || i==n-1)
					j++;
				else
					j = m-1;
			}
		}

		if (step == x) {
			cout << bord;
			return 0;
		}

		n=nn, m=mm;
	}
	cout << 0;

}