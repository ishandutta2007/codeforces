#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	double maxr = 0, tmp1, tmp2;
	cin >> n >> m;
	for(int i=0;i<n;i++) {
		cin >> tmp1 >> tmp2;
		maxr = max(maxr, tmp2 / tmp1);
	}
	cout << setprecision(9) << m / maxr << endl;
}