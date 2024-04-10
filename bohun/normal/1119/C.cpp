#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
int n, m;
int t[505][505];
int ile[505][505];
int w[505], col[505];
int main()
{
	scanf("%d %d", &n, &m);
	for(int g = 0; 2 > g; ++g)
	for(int i = 1; n >= i; ++i)
		for(int j = 1; m >= j; ++j)
		{
			int a;
			cin >> a;
			t[i][j] ^= a;
		}
	for(int i = 1; n >= i; ++i)
		for(int j = 1; m >= j; ++j)
			w[i] += t[i][j], col[j] += t[i][j];
	bool ok = 1;
	for(int i = 1; n >= i; ++i)
		if((w[i] & 1))
			ok = 0;
	for(int j = 1; m >= j; ++j)
		if((col[j] & 1))
			ok = 0;
	if(!ok)
		cout << "NO";
	else
		cout << "YES";
				
		
		
	
			
	return 0;
}