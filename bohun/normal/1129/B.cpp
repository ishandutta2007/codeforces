#include <bits/stdc++.h>
#define ll long long 
#define ld long double 
using namespace std;
int k;
int t[2005];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> k;
	t[1] = -1;
	int i = 2;
	k+=2000;
	while(k >= 1)
	{
		t[i] = min(k, (int)1e6);
		k -= min(k, (int)1e6);
		i++;
	}
	cout << 2000 <<endl;
	for(int i = 1; 2000 >= i; ++i)
		cout << t[i] << " ";
	return 0;
}