#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
char a[100005], b[100005];
int n, m;
int last[30];
int lewo[100005][30], prawo[100005][30], d[100005][2];
int main()
{
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);

	scanf("%s %s", a + 1, b + 1);
	n = strlen(a + 1);
	m = strlen(b + 1);
	fill(last, last + 26, 0);
	for(int i = 1; n + 1 >= i; ++i)
	{
		for(int j = 0; 26 > j; ++j)
			lewo[i][j] = last[j];
		if(i >= 1 and i <= n)
			last[a[i] - 'a'] = i;
	}
	fill(last, last + 26, n + 1);
	for(int i = n + 1; i >= 0; --i)
	{
		for(int j = 0; 26 > j; ++j)
			prawo[i][j] = last[j];
		if(i >= 1 and i <= n)
			last[a[i] - 'a'] = i;
	}
	d[m + 1][1] = n + 1;
	d[0][0] = 0;
	for(int i = 1; m >= i; ++i)
		d[i][0] = prawo[d[i - 1][0]][b[i] - 'a'];
	for(int i = m; i >= 1; --i)
		d[i][1] = lewo[d[i + 1][1]][b[i] - 'a'];
	int pocz = 0, k = 0, ans = 1000000;
	int kon = 1;
	//for(int i = 0; m + 1 >= i; ++i)
	//	cout << d[i][1] << " " << i << endl;
	for(int i = 0; m >= i; ++i)
		{
			while((kon <= m and d[i][0] >= d[kon][1]) or (i >= kon))
				kon++;
			int len = kon - i;
			if(len < ans and d[kon][1] > d[i][0])
				{
					ans = len;
					pocz = i;
					k = kon;
				}
		}
	if(ans == m + 1)
		cout << "-";
	else
		{
			for(int i = 1; pocz >= i; ++i)
				cout << b[i];
			for(int i = k; m >= i; ++i)
				cout << b[i];
		}
	
	
}