#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n, res[1000005];
int main()
{
	cin >> n;
	int j = 1;
	for(int i = 1; n > i; i += 2, ++j)
		res[j] = res[n - j + 1] = i;
	j = 1;
	for(int i = 2; n >= i; i += 2, ++j)
		res[n + j] = res[2 * n - j] = i;
	for(int i = 1; 2 * n >= i; ++i)
		if(!res[i])
			res[i] = n;
	for(int i = 1; n * 2 >= i; ++i)
		printf("%d ", res[i]);
		
	return 0;
}