#include <bits/stdc++.h>
#define ll long long 
#define pb push_back
#define ld long double
#define ss(v) (int)v.size()
#define fi first
#define se second
using namespace std;
int n, m, k, d;
int t[500005];
int seg[(1 << 20) + 9];
void add(int x)
{
	x += (1 << 19);
	while(x)
	{
		seg[x]++;
		x /= 2;
	}
}
int sum(int node, int lewo ,int prawo, int x, int y)
{
	if(y < x)
		return 0;
	if(y >= prawo and lewo >= x)
		return seg[node];
	int mid = (lewo + prawo) / 2;
	int wynik = 0;
	if(mid >= x)
		wynik += sum(2 * node, lewo, mid, x, y);
	if(y > mid)
		wynik += sum(2 * node + 1, mid + 1, prawo, x, y);
	return wynik;
}
int dp[500005];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> d;
	for(int i = 0; n > i; ++i)
	{
		cin >> t[i];
	}
	sort(t, t + n);
	add(0);
	int left = 0;
	for(int i = 0; n > i; ++i)
	{
		while(left < n and t[i] - t[left] > d)
			left++;
		int lewo = left;
		int prawo = i - k + 1;
		int ile = sum(1, 0, (1 << 19) - 1, lewo, prawo);
		if(ile)
			dp[i + 1] = 1;
		if(ile)
			add(i + 1);
	}
	cout << (dp[n] ? "YES" : "NO");
			
	
	
	
	return 0;
}