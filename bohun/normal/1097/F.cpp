#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
bitset <7005> bit[100005], ha[7005];
int mob[100005];
bool good[100005];
vector <int> divi[7005];
int n, q;
int main()
{
	scanf("%d %d", &n, &q);
	for(int i = 1; 7000 >= i; ++i)
		mob[i] = 1;
	for(int i = 2; 7000 >= i; ++i)
	{
		if(!good[i])
		{
			for(int j = i; 7000 >= j; j += i)
			{
				good[j] = 1;
				if(j % ((ll)i * i) == 0)
					mob[j] = 0;
			}
		}
	}
	for(int i = 1; 7000 >= i; ++i)
		for(int j = i; 7000 >= j; j += i)
			divi[j].pb(i);
	for(int i = 1; 7000 >= i; ++i)
		for(int j = i; 7000 >= j; j += i)
			ha[i][j] = mob[j / i];
	while(q--)
	{
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);
		if(t == 1)
		{
			bit[a].reset();
			for(auto it: divi[b])
				bit[a][it] = 1;
			
		}
		if(t == 2)
		{
			int z;
			scanf("%d", &z);
			bit[a] = (bit[b] ^ bit[z]);
		}
		if(t == 3)
		{
			int z;
			scanf("%d", &z);
			bit[a] = (bit[b] & bit[z]);
		}
		if(t == 4)
		{
			printf("%d", (int)((bit[a] & ha[b]).count()) % 2);
		}
	}
		
	return 0;
}