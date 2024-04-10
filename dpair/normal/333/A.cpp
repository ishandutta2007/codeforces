#include <bits/stdc++.h>
using namespace std;
long long n;
long long tmp = 1;
long long tot;

int main()
{
	cin >> n;
	while(tmp)
	{
		tmp *= 3;
//		tot ++;
		if(n % tmp)
		{
			printf("%lld", n / tmp + 1);
			return 0;
		}
	}
}