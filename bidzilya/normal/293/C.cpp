#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <windows.h>
using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, int> pii;

ll n, del[111111];
int cnt, dels;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin >> n;
	if (n%3==0)
	{
		n /= 3;
		for (ll i=2; i*i<=n; i++)
			if (!(n%i))
				del[dels++] = i;
		for (int ix = 0; ix < dels && del[ix]*del[ix]*del[ix] <= n; ix++)
			for (int iy = ix; iy < dels && del[ix]*del[iy]*del[iy] <= n; iy++)
			{
				ll x = del[ix], y = del[iy];
				if (!(n%(x*y)))
				{
					ll z = n/(x*y);
					if (x+y-z > 0 && !((x+y-z)%2))
					{
						ll a = (x+y-z) >> 1;
						ll b = x-a;
						ll c = z-b;
						if (a==b)
						{
							if (b==c)
								cnt += 1;
							else
								cnt += 3;
						}else
						{
							if (b==c)
								cnt += 3;
							else
								cnt += 6;
						}
					}
				}
			}
	}
	cout << cnt << endl;
	return 0;
}