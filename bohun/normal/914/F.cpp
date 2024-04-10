#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
char s[110000];
int q;
int l, r;
char t[110000];
bitset <110000> x[30], roz, jed;
int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	cin >> q;
	for(int i = 1; n >= i; ++i)
	{
		x[s[i] - 'a'][i] = 1;
	}
	jed.flip();
	while(q--)
	{
		int te;
		scanf("%d", &te);
		if(te == 1)
		{
			scanf("%d%s", &l, t + 1);
			int lit = s[l] - 'a';
			x[lit][l] = 0;
			x[t[1] - 'a'][l] = 1;
			s[l] = t[1];
		}
		else
		{
			scanf("%d%d%s", &l, &r, t + 1);
			int len = strlen(t + 1);
			roz = jed;
			for(int i = 1; len >= i; ++i)
			{
				roz &= (x[t[i] - 'a'] >> i);
			}
			printf("%d\n", max(0, (int)(roz >> (l - 1)).count() - (int)(roz >> (r - len + 1)).count()));
		}
	}
			
	return 0;
}