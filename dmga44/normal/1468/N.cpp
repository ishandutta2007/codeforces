#include <bits/stdc++.h>

#define int long long

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
    	int c1, c2, c3;
    	cin >> c1 >> c2 >> c3;

    	int a1, a2, a3, a4, a5;
    	cin >> a1 >> a2 >> a3 >> a4 >> a5;

    	c1 -= a1;
    	c2 -= a2;
    	c3 -= a3;

    	if(c1 < 0 || c2 < 0 || c3 < 0)
    	{
    		cout << "NO" << '\n';
    		continue;
    	}

    	int d1 = min(c1,a4);
    	int d2 = min(c2,a5);

    	c1 -= d1;
    	c2 -= d2;

    	a4 -= d1;
    	a5 -= d2;

    	c3 -= a4;
    	c3 -= a5;

    	if(c3 < 0)
    	{
    		cout << "NO" << '\n';
    		continue;
    	}

    	cout << "YES" << '\n';
    }

    return 0;
}