#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int k, n;
char s[2505][5005];
char sol[5005];
void out()
{
	for(int i = 1; n >= i; ++i)
		printf("%c", sol[i]);
	//printf("\n");
	exit(0);
}
int al[30];
bool spr()
{
	for(int j = 0; 26 > j; ++j)
			al[j] = 0;
	for(int i = 1; n >= i; ++i)
		al[sol[i] - 'a']++;
	bool jest = 0;
	for(int i = 0; 26 > i; ++i)
		jest |= al[i] >= 2;
		
	for(int i = 1; k >= i; ++i)
		{
			int p1 = -1, p2 = -1;
			for(int j = 1; n >= j; ++j)
				{
					if(sol[j] != s[i][j] and p1 == -1)
						p1 = j;
					else if(sol[j] != s[i][j] and p2 == -1)
						p2 = j;
					else if(sol[j] != s[i][j])
						return 0;
				}
			if(p1 == -1 and jest == 0)
				return 0;
			if(sol[p1] != s[i][p2] or sol[p2] != s[i][p1])
				return 0;
		}
	return 1;
}
int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	scanf("%d %d", &k ,&n);
	for(int i = 1; k >= i; ++i)
		scanf("%s", s[i] + 1);
	bool ok = 1;
	int poz = -1;
	for(int i = 2; k >= i; ++i)
		for(int j = 1; n >= j; ++j)
			{
				ok &= (s[1][j] == s[i][j]);
				if(s[1][j] != s[i][j])
					poz = i;
			}
	if(ok)
	{
		swap(s[1][1], s[1][2]);
		for(int j = 1; n >= j; ++j)
			printf("%c", s[1][j]);
		return 0;
	}
	vector < int > e;
	for(int i = 1; n >= i; ++i)
	{
		if(s[1][i] != s[poz][i])
		{
			e.pb(i);
		}
		sol[i] = s[1][i];
	}
	if(ss(e) > 4)
		{
			cout << -1;
			return 0;
		}
	for(int i = 0; ss(e) > i; ++i)
		for(int j = 0; ss(e) > j; ++j)
			{
				swap(sol[e[i]], sol[e[j]]);
				if(spr())
					out();
				swap(sol[e[i]], sol[e[j]]);
			}
	cout << -1;
	
	

}