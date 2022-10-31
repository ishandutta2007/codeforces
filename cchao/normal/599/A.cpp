#include <bits/stdc++.h>
using namespace std;
int d[3][3]={{}};
int main() {
	cin >> d[0][1] >> d[0][2] >> d[1][2];
	d[1][0] = d[0][1];
	d[2][0] = d[0][2];
	d[2][1] = d[1][2];
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			for(int k = 0; k < 3; ++k)
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
	printf("%d\n", d[0][1] + d[1][2] + d[2][0]);
	return 0;
}