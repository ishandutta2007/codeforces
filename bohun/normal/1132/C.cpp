#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;

int n;
int t[5005][2];
int sum[5005];
int pref[5005][2];
int res = 0;
int q;
int f(int a, int b, int c)
{
	if(a > b)
		return 0;
	return pref[b][c] - pref[a - 1][c];
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> q >> n;
	for(int i = 1; n >= i; ++i)
	{
		cin >> t[i][0] >> t[i][1];
		for(int j = t[i][0]; t[i][1] >= j; ++j)
			sum[j]++;
	}
	for(int i = 1; 5000 >= i; ++i)
		if(sum[i])
			res++;
	
	for(int i = 1; 5000 >= i; ++i)
	{
		if(sum[i] == 1)
			pref[i][0] += 1;
		pref[i][0] += pref[i-1][0];
		if(sum [i] == 2)
			pref[i][1] ++;
		pref[i][1] += pref[i-1][1];
	}
	int ans = 0;
	for(int i = 1; n >= i; ++i)
		{
			for(int j = 1; n >= j; ++j)
		{
			if(i == j)
				continue;
			int l = t[i][0];
			int r = t[i][1];
			int le = t[j][0];
			int rr = t[j][1];
			if(l > le)
			{
				swap(l, le);
				swap(r, rr);
			}
			if(r < le)
			{
				//if(i == 1 and j == 3)
				//	cout << sum[r] << " " << r << endl;
				ans = max(ans, res - (pref[r][0] - pref[l-1][0]) - (pref[rr][0] - pref[le - 1][0]));
			}
			else
			{
				//if(i == 1 and j == 3)
				//	cout << - f(l, le - 1, 0) - f(le, min(r, rr), 1) - f(min(r, rr) + 1, max(r, rr), 0) << endl;
				ans = max(ans, res - f(l, le - 1, 0) - f(le, min(r, rr), 1) - f(min(r, rr) + 1, max(r, rr), 0));
				//if(ans == 4)
				//	cout <<   f(l, le - 1, 0) << " " << f(le, min(r, rr), 1) << " " << f(min(r, rr) + 1, max(r, rr), 0) << " " << i << " " << j << endl;
			}
		}
	}
		cout << ans;
			
		

	return 0;
}