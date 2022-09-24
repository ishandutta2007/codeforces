#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;

int main()
{
	long long l, R;
	cin >> R >> l;
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		long long x, y, r;
		cin >> x >> y >> r;
		long long dist = x * x + y * y;
		if (dist >= (r + R - l) * (r + R - l) && dist <= (R - r) * (R - r)) {
			++ans;
		} 
	}
	cout << ans << endl;
	return 0;
}