#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
using namespace std;

int main()
{
	char s[10005];
	scanf("%s", s + 1);
	int q;
	cin >> q;
	for(int i = 1; q >= i; ++i)
	{
		int l, r, k;
		cin >> l >> r >> k;
		k %= (r - l + 1);
		vector <char> v;
		for(int j = l; r >= j; ++j)
			v.pb(s[j]);
		for(int j = l; r >= j; ++j)
		{
			int id = (j + k);
			if(id > r)
			{
				id %= (r + 1);
				id += l;
			}
			s[id] = v[j - l];
			//cout << l + (j + k) % (r - l + 2) << " " << endl;
		}
	}
	for(int i = 1; (int)strlen(s + 1) >= i; ++i)
		cout << s[i];
			
	
	
	return 0;
}