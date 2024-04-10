#include <bits/stdc++.h>

using namespace std;

#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second



int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int x, y;
		cin >> x >> y;

		set<int> s;
		for (int i = 0; i < 1 << 4; ++i)
		{
			int a = x - 2, b = y - 2, c = a, d = b;
			if (i & 1) ++a; else ++d;
			if (i >> 1 & 1) ++b; else ++a;
			if (i >> 2 & 1) ++c; else ++b;
			if (i >> 3 & 1) ++d; else ++c;

			int g = __gcd(__gcd(a, b), __gcd(c, d));
			s.insert(g);
		}

		set<int> ans;
		for (auto i : s)
			for (int j = 1; j * j <= i; ++j)
				if (i % j == 0)
					ans.insert(j), ans.insert(i / j);
		
		cout << ans.size();
		for (auto i : ans)
			cout << " " << i;
		cout << endl;
	}

	return 0;
}