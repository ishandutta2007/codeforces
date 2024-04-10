#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = INF * INF;

vector<string> s, ans;
string ST;

int n, m;
int zara = INF;

int dist(vector<string>& x)
{
	int res = 0;
	FOR(i, 0, n)
		FOR(j, 0, m)
			res += s[i][j] != x[i][j];
	return res;
}
  
void check(vector<string>& x)
{
	int tut = dist(x);
	if (tut > zara)
		return;
	zara = tut;
	ans = x;
	map<char, char> mp;
	mp[ST[0]] = 'A';
	mp[ST[1]] = 'C';
	mp[ST[2]] = 'G';
	mp[ST[3]] = 'T';
		
	FOR(i, 0, n)
		FOR(j, 0, m)
			ans[i][j] = mp[ans[i][j]];
}

void checkaj()
{
	vector<string> x1;
	
	//
	
	x1 = s;
	FOR(i, 0, n)
	{
		if (i & 1)
		{
			int cnt_a = 0, cnt_c = 0;
			for(int j = 0; j < m; j += 2)
			{
				cnt_a += s[i][j] == 'A';
				cnt_c += s[i][j] == 'C';
			}
			
			for(int j = 1; j < m; j += 2)
			{
				cnt_a += s[i][j] == 'C';
				cnt_c += s[i][j] == 'A';
			}
			
			if (cnt_a >= cnt_c)
			{
				FOR(j, 0, m)
					if (j & 1)
						x1[i][j] = 'C';
					else
						x1[i][j] = 'A';
			}
			else
			{
				FOR(j, 0, m)
					if (j & 1)
						x1[i][j] = 'A';
					else
						x1[i][j] = 'C';
			}
		}
		else
		{
			int cnt_t = 0, cnt_g = 0;
			for(int j = 0; j < m; j += 2)
			{
				cnt_t += s[i][j] == 'T';
				cnt_g += s[i][j] == 'G';
			}
			
			for(int j = 1; j < m; j += 2)
			{
				cnt_t += s[i][j] == 'G';
				cnt_g += s[i][j] == 'T';
			}
			
			if (cnt_t >= cnt_g)
			{
				FOR(j, 0, m)
					if (j & 1)
						x1[i][j] = 'G';
					else
						x1[i][j] = 'T';
			}
			else
			{
				FOR(j, 0, m)
					if (j & 1)
						x1[i][j] = 'T';
					else
						x1[i][j] = 'G';
			}
		}
	}
	
	check(x1);
	
	FOR(i, 0, n)
	{
		if (i % 2 == 0)
		{
			int cnt_a = 0, cnt_c = 0;
			for(int j = 0; j < m; j += 2)
			{
				cnt_a += s[i][j] == 'A';
				cnt_c += s[i][j] == 'C';
			}
			
			for(int j = 1; j < m; j += 2)
			{
				cnt_a += s[i][j] == 'C';
				cnt_c += s[i][j] == 'A';
			}
			
			if (cnt_a >= cnt_c)
			{
				FOR(j, 0, m)
					if (j & 1)
						x1[i][j] = 'C';
					else
						x1[i][j] = 'A';
			}
			else
			{
				FOR(j, 0, m)
					if (j & 1)
						x1[i][j] = 'A';
					else
						x1[i][j] = 'C';
			}
		}
		else
		{
			int cnt_t = 0, cnt_g = 0;
			for(int j = 0; j < m; j += 2)
			{
				cnt_t += s[i][j] == 'T';
				cnt_g += s[i][j] == 'G';
			}
			
			for(int j = 1; j < m; j += 2)
			{
				cnt_t += s[i][j] == 'G';
				cnt_g += s[i][j] == 'T';
			}
			
			if (cnt_t >= cnt_g)
			{
				FOR(j, 0, m)
					if (j & 1)
						x1[i][j] = 'G';
					else
						x1[i][j] = 'T';
			}
			else
			{
				FOR(j, 0, m)
					if (j & 1)
						x1[i][j] = 'T';
					else
						x1[i][j] = 'G';
			}
		}
	}

	check(x1);
//	return;
	//
	
	FOR(j, 0, m)
	{
		if (j & 1)
		{
			int cnt_a = 0, cnt_c = 0;
			for(int i = 0; i < n; i += 2)
			{
				cnt_a += s[i][j] == 'A';
				cnt_c += s[i][j] == 'C';
			}
			
			for(int i = 1; i < n; i += 2)
			{
				cnt_a += s[i][j] == 'C';
				cnt_c += s[i][j] == 'A';
			}
			
			if (cnt_a >= cnt_c)
			{
				FOR(i, 0, n)
					if (i & 1)
						x1[i][j] = 'C';
					else
						x1[i][j] = 'A';
			}
			else
			{
				FOR(i, 0, n)
					if (i & 1)
						x1[i][j] = 'A';
					else
						x1[i][j] = 'C';
			}
		}
		else
		{
			int cnt_t = 0, cnt_g = 0;
			for(int i = 0; i < n; i += 2)
			{
				cnt_t += s[i][j] == 'T';
				cnt_g += s[i][j] == 'G';
			}
			
			for(int i = 1; i < n; i += 2)
			{
				cnt_t += s[i][j] == 'G';
				cnt_g += s[i][j] == 'T';
			}
			
			if (cnt_t >= cnt_g)
			{
				FOR(i, 0, n)
					if (i & 1)
						x1[i][j] = 'G';
					else
						x1[i][j] = 'T';
			}
			else
			{
				FOR(i, 0, n)
					if (i & 1)
						x1[i][j] = 'T';
					else
						x1[i][j] = 'G';
			}
		}
	}
	
	check(x1);
	//return;
	
	FOR(j, 0, m)
	{
		if (j % 2 == 0)
		{
			int cnt_a = 0, cnt_c = 0;
			for(int i = 0; i < n; i += 2)
			{
				cnt_a += s[i][j] == 'A';
				cnt_c += s[i][j] == 'C';
			}
			
			for(int i = 1; i < n; i += 2)
			{
				cnt_a += s[i][j] == 'C';
				cnt_c += s[i][j] == 'A';
			}
			
			if (cnt_a >= cnt_c)
			{
				FOR(i, 0, n)
					if (i & 1)
						x1[i][j] = 'C';
					else
						x1[i][j] = 'A';
			}
			else
			{
				FOR(i, 0, n)
					if (i & 1)
						x1[i][j] = 'A';
					else
						x1[i][j] = 'C';
			}
		}
		else
		{
			int cnt_t = 0, cnt_g = 0;
			for(int i = 0; i < n; i += 2)
			{
				cnt_t += s[i][j] == 'T';
				cnt_g += s[i][j] == 'G';
			}
			
			for(int i = 1; i < n; i += 2)
			{
				cnt_t += s[i][j] == 'G';
				cnt_g += s[i][j] == 'T';
			}
			
			if (cnt_t >= cnt_g)
			{
				FOR(i, 0, n)
					if (i & 1)
						x1[i][j] = 'G';
					else
						x1[i][j] = 'T';
			}
			else
			{
				FOR(i, 0, n)
					if (i & 1)
						x1[i][j] = 'T';
					else
						x1[i][j] = 'G';
			}
		}
	}
	
	check(x1);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n >> m;
	s.resize(n);
	FOR(i, 0, n)
		cin >> s[i];
	
	auto SS = s;
	ST = "ACGT";

	do
	{
		FOR(i, 0, n)
		FOR(j, 0, m)
		{
			if (s[i][j] == 'A')
				s[i][j] = ST[0];
			else
			{
				if (s[i][j] == 'C')
					s[i][j] = ST[1];
				else
				{
					if (s[i][j] == 'G')
						s[i][j] = ST[2];
					else
						s[i][j] = ST[3];
				}
			}
		}
		
		checkaj();
		s = SS;
	}while(next_permutation(ALL(ST)));
	
	//debug(zara)
	FOR(i, 0, n)
		cout << ans[i] << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}