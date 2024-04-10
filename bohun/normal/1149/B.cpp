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
const ll inf = 1e18, nax = 100005;

int n, q;
string s;
int nex[nax][30], last[30];
int dp[255][255][255];
vector <int> v[4];
int len[4];

void go(int x)
{
	int one, two;
	if(x == 1)
		one = 2, two = 3;
	if(x == 2)
		one = 1, two = 3;
	if(x == 3)
		one = 1, two = 2;
	
	for(int i = 0; len[one] >= i; ++i)
		for(int j = 0; len[two] >= j; ++j)
		{
			int best = n + 1;
			int A, B, C;
			if(x == 1)
			{
				A = len[1];
				B = i;
				C = j;
				if(A)
				best = min(best, nex[dp[A - 1][B][C]][v[1][A - 1]]);
				if(B)
				best = min(best, nex[dp[A][B - 1][C]][v[2][B - 1]]);
				if(C)
				best = min(best, nex[dp[A][B][C - 1]][v[3][C - 1]]);
				dp[A][B][C] = best;
			}
			if(x == 2)
			{
				A = i;
				B = len[2];
				C = j;
				if(A)
				best = min(best, nex[dp[A - 1][B][C]][v[1][A - 1]]);
				if(B)
				best = min(best, nex[dp[A][B - 1][C]][v[2][B - 1]]);
				if(C)
				best = min(best, nex[dp[A][B][C - 1]][v[3][C - 1]]);
				dp[A][B][C] = best;
			}
			if(x == 3)
			{
				A = i;
				B = j;
				C = len[3];
				if(A)
				best = min(best, nex[dp[A - 1][B][C]][v[1][A - 1]]);
				if(B)
				best = min(best, nex[dp[A][B - 1][C]][v[2][B - 1]]);
				if(C)
				best = min(best, nex[dp[A][B][C - 1]][v[3][C - 1]]);
				dp[A][B][C] = best;
			}
		}
}
	
	

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> q;
	cin >> s;
	s = 'a' + s;
	for(int i = 0; 30 > i; ++i)
		last[i] = n + 1;
	for(int i = n; i >= 0; --i)
	{
		for(int j = 0; 30 > j; ++j)
			nex[i][j] = last[j];
		last[s[i] - 'a'] = i;
	}
	for(int i = 0; 30 > i; ++i)
		nex[n + 1][i] = n + 1;
	
	for(int i = 0; 250 >= i; ++i)
		for(int j = 0; 250 >= j; ++j)
			for(int g = 0; 250 >= g; ++g)
				dp[i][j][g] = n + 1;
	dp[0][0][0] = 0;
	while(q--)
	{
		char C;
		cin >> C;
		int nr;
		cin >> nr;
		if(C == '-')
			len[nr]--, v[nr].pop_back();
		else
		{
			len[nr]++;
			cin >> C;
			v[nr].pb(C - 'a');
			go(nr);
		}
		if(dp[len[1]][len[2]][len[3]] <= n)
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}
	
	
	
	
	
		
		
		
	
    return 0;
}