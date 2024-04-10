#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
int main() {
	ios::sync_with_stdio(false);
	long long xI, yI, xII, yII;
	cin >> xI >> yI >> xII >> yII;
	long long size = (xII - xI + 1) * (yII - yI + 1);
	if (size % 2 == 0) cout << size / 2 << endl;
	else cout << size / 2 + 1 << endl;
	return 0;
}