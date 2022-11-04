#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

int mas[3000];

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> mas[i];
	sort(mas, mas + n);
	int q = 0;
	int w = mas[n - 1];
	long long ans = 0;
	for(int i = n - 1; i >= 0; i--)
	{	
		if(q == k - 1)
		{
			ans += (long long)(w - 1) * 2;
			q = 0;
			if(i > 0)
				w = mas[i - 1];
		}
		else
			q++;
	}
	if(q > 0)
		ans += (long long)(w - 1) * 2;
	cout << ans;
	return 0;
}