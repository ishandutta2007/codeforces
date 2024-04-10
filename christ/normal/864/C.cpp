#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 2e5+2, BASE = 31; const ll MOD = 1000000000000037LL;
#define all(x) (x).begin(),(x).end()
int main() {
	int a,b,f,k;
	scanf ("%d %d %d %d",&a,&b,&f,&k);
	int left = b, ret = 0;
	for (int trip = 1; trip <= k; trip++) {
		int dir = trip&1;
		if (dir) {
			left -= f;
			if (left < 0) return !printf ("-1\n");
			if ((trip != k && left - (a-f)*2 < 0) || (trip == k && left - (a-f) < 0)) left = b, ret ++;
			left -= (a-f);
		} else {
			left -= (a-f);
			if (left < 0) return !printf ("-1\n");
			if ((trip != k && left - f*2 < 0) || (trip == k && left - f < 0)) left = b, ret++;
			left -= f;
		}
	}
	printf ("%d\n",left<0?-1:ret);
	return 0;
}