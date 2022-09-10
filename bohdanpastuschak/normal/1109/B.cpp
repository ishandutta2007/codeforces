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

void bad()
{
	cout << "Impossible";
	exit(0);
}

int n;
string s;
int cnt[26];

bool ok(string& t)
{
	FOR(i, 0, SZ(t) / 2)
		if (t[i] != t[SZ(t) - i - 1])
			return 0;
	return 1;
}

bool can3(string& t)
{
	FOR(i, 1, SZ(t))
		FOR(j, i + 1, SZ(t))
			//FOR(wa, j + 1, SZ(t) - 1)
			{
				vector<string> vec;
				string z;
				FOR(k, 0, i)
					z += t[k];
				vec.PB(z);
				z.clear();
				FOR(k, i, j)
					z += t[k];
				vec.PB(z);
				z.clear();
				FOR(k, j, SZ(t))
					z += t[k];
				vec.PB(z);
					z.clear();
				sort(ALL(vec));
				do
				{
					string tut;
					for(auto i: vec)
						tut += i;
					if (ok(tut) && tut != t)
					{
						cout << i  << ' ' << j << ' ' << tut << endl;
					
						return 1;
					}
				}while(next_permutation(ALL(vec)));
			}
	
	assert(0);
}

//aba

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> s;
	n = SZ(s);
	FOR(i, 0, n)
		cnt[s[i] - 'a']++;
	
	int odd = 0, all = 0;
	FOR(i, 0, 26)
		odd += cnt[i] & 1, all += cnt[i] > 0;
	
	if (odd > 1 || all == 1)
		bad();
	
	if (all == 2 && odd == 1)
	{
		int mn = n;
		FOR(i, 0, 26)
			if (cnt[i])
				mn = min(mn, cnt[i]);
		if (mn == 1)
			bad();
	}
	
	FOR(i, 1, n)
	{
		string t;
		FOR(j, i, n)
			t += s[j];
		FOR(j, 0, i)
			t += s[j];
		
		if (ok(t) && t != s)
		{
			cout << 1;
			return 0;
		}
	}
	
	cout << 2;	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}