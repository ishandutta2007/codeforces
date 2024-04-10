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
const int nax = 1000005;
int c[nax], t[nax], d[nax];
int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 1; n >= i; ++i)
	{
		scanf("%d", &t[i]);
		if(t[i] <= m)
			c[t[i]]++;
	}
	for(int i = 1; m >= i; ++i)
		for(int j = i; m >= j; j += i)
			d[j] += c[i];
	int naj = 0, id = 1;
	for(int i = 1; m >= i; ++i)
	{
		if(d[i] > naj)
		{
			naj = d[i];
			id = i;
		}
	}
	printf("%d %d\n", id, naj);
	for(int i = 1; n >= i; ++i)
		if(id % t[i] == 0)
			printf("%d ", i);
		
	return 0;
}