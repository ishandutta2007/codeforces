#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, k;
int main()
{	
	scanf("%d %d", &n ,&k);
	if(n / 2 > k or (n == 1 and k >0))
	{
		cout << -1;
		return 0;
	}
	int r = k - (n / 2 - 1);
	if(n >= 2)
	cout << r << " " << 2 * r << " ";
	int j = 1;
	for(int i = 1; n / 2 - 1 >= i; ++i)
		{
			while(j == r or j + 1 == r or j == 2 * r or j + 1 == 2 * r)
				j += 2;
			cout << j << " " << j + 1 << " " ;
			j += 2;
		}
	if(n % 2)
		cout << 133334525;
		
	
}