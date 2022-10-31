#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1003;
const int LOG = (int)11;
const int infint = (int)1e9 + 3;
const ll inf = (ll)1e12;
string A, B[MAXN];
int cost[MAXN], dp[MAXN][MAXN] , last[MAXN], n, mx, sza;
pair<int , int> radix[MAXN];
void build()
{
	memset(dp, -63, sizeof dp);
	for(auto &ch : A)
		ch -= '0';
	mx++;
	reverse(A.begin() , A.end());
	sza = A.size();
	while((int)A.size() < mx)
		A += (char)(0);
	
	for(int i = 0; i < n; i++)
	{
		last[i] = B[i].size();
		reverse(B[i].begin() , B[i].end());
		while((int)B[i].size() < mx)
			B[i] += '0';
		radix[i] = {B[i][0] , i};
	}
	sort(radix, radix + n);
	reverse(radix, radix + n);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> A >> n;
	mx = A.size();
	for(int i = 0; i < n; i++)
	{
		cin >> B[i];
		mx = max(mx , (int)B[i].size());
	}
	for(int i = 0; i < 10; i++)
		cin >> cost[i];
	
	build();
	dp[0][0] = 0;
	for(int i = 0; i < mx; i++)
	{
		//segments of valid digits
		int l , r;
		if(A[i] == '?' - '0')
			l = 0 , r = 9;
		else
			l = r = A[i];
		if(i == sza - 1 && A[i] == '?' - '0')
			l = 1;
		for(int k = l; k <= r; k++)
		{
			int pt = 0, add = 0;
			for(int j = 0; j < n; j++)
			{
				int ind = radix[j].second;
				int nxt = B[ind][i] - '0' + k;
				if(nxt >= 10)
					pt++;
				if(max(last[ind], sza) > i || nxt > 0)
					add += cost[nxt % 10];
			}
			for(int j = 0; j <= n; j++)
			{
				dp[i + 1][pt] = max(dp[i + 1][pt] , dp[i][j] + add);
				if(j == n)
					continue;
				int ind = radix[j].second;
				int nxt = B[ind][i] - '0' + k;
				if(nxt == 9)
					pt++;
				if(max(last[ind] , sza) > i || nxt > 0)
					add -= cost[nxt % 10];
				add += cost[(nxt + 1) % 10];
			}
		}
		reverse(radix, radix + n);
		for(int j = 0; j < n; j++)
		{
			int ind = radix[j].second;
			radix[j].first = n * B[ind][i] + j;
		}
		sort(radix, radix + n);
		reverse(radix, radix + n);
	}
	cout << dp[mx][0];
}