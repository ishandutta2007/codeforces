#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define For(i, n) for(int i = 1; n >= i; ++i)
using namespace std;
const int nax = 10005, mod = 998244353;
const ll inf = 1e18;

int daj(int a, int b)
{
	cout << "? " << a << " " << b << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}		

int t[] = {4, 8, 15, 16, 23, 42};
int ee[10];
int per[6];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	for(int i = 1; 4 >= i; ++i)
		ee[i] = daj(i, i + 1);
	
	for(int i = 1; 6 >= i; ++i)
		per[i] = i;
	
	for(int i = 1; 1*2*3*4*5*6 >= i; ++i)
	{
		bool ok = 1;
		for(int j = 1; 4 >= j; ++j)
		{
			ok &= (t[per[j] - 1] * t[per[j + 1] - 1] == ee[j]);
		}
		if(ok)
		{
			cout << "! ";
			for(int j = 1; 6 >= j; ++j)
				cout << t[per[j] - 1] << " ";
			return 0;
		}
		next_permutation(per + 1, per + 7);
	}
	
		
	
		
		
		
	
    return 0;
}