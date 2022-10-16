#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, d;
	cin >> t;
	while(t--) {
		cin >> d;
		if(d*d < 4*d) {
			cout << "N" << endl;
			continue;
		}
		double a = (d+sqrt(1.0*(d*d-4*d)))/2.0;
		printf("Y %.10f %.10f\n", a, d-a);
	}
}