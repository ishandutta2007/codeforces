#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	int aa, bb, cc, ans = 0;
	cin >> aa >> bb >> cc;
	const int d[] = {0,1,2,0,2,1,0};
	for(int s=0;s<=6;s++) {
		int a[3] = {aa, bb, cc}, x = 0;
		bool ok = true;
		for (int i = s; i < 7; i++)
			if (a[d[i]])
				--a[d[i]], ++x;
			else {
				ok = false;
				break;
			}
		if (ok) {
			int w = min(min(a[0]/3,a[1]/2),a[2]/2);
			x += w * 7;
			a[0] -= w * 3;
			a[1] -= w * 2;
			a[2] -= w * 2;
			for (int i = 0; i < 7; i++)
				if (a[d[i]])
					--a[d[i]], ++x;
				else 
					break;
		}
		ans = max(ans, x);
	}
	cout << ans << endl;
	
}