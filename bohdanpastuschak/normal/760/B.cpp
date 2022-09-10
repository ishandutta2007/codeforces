#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	long long n, m, k;
	cin >> n >> m >> k;
	long long ans;
	if (n == 1) ans = m;
	else
	{
		if (n == 2)
			ans = (m + 1) / 2;
		else
		{			
		    if (n == 3)
		    {
		        if (k == 2)
		        {
		             if (m == 3) ans = 1;
		             if (m== 4) ans = 2;
		             if (m== 5) ans = 2;
		             if (m == 6) ans = 2;
		             if (m == 7) ans = 3;
		             if (m == 8) ans = 3;
		             if (m == 9) ans = 3;
		             if (m > 9) ans = (m+2)/3;
		        }
		        else 
		        {
		            if (m == 3) ans = 1;
		            if (m == 4) ans = 2;
		            if (m== 5) ans = 2;
		            if (m == 6) ans = 3;
		            if (m == 7) ans = 3;
		            if (m == 8) ans = 3;
		            if (m == 9) ans = 4;
		            if (m > 9) ans = m/3 + 1;
		        }
		    }
		    else{
			for (int x = 1; x <= m + 10; ++x)
			{
				long long t = 0;

				if (x < k)
					t += (x*(x + 1))/2 + k - x;
				else
					t += (k*x - (k*(k - 1)) / 2);

				if (x > n - k)
				{
					t += (x*(n - k) - ((n - k)*(n - k + 1)) / 2);
				}
				else
				{
					t += ((x*(x - 1)) / 2 + (n - k - x + 1));
				}
				
				if (t <= m)
				{
					ans = x;
				}
				/*

				if (x > n - k)
				{
					t += x*(n - k + 1) - ((n - k)*(n - k + 1)) / 2;
				}
				else
				{
					t += ((x*(x + 1)) / 2 + n - k - x + 1);
				}
				*/
				else break;
			}
		}
	}
	}

	cout << ans;
	return 0;
}