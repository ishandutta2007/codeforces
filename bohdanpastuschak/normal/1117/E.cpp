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

int n;
string t;

string ask(string s)
{
	cout << "? " << s << endl;
	fflush(stdout);
	cin >> s;
	return s;
}

VI h1[26];
VI h2[26];

vector<pair<VI, VI> > asker(string s)
{
	FOR(i, 0, 26)
	{
		h1[i].clear();
		h2[i].clear();
	}
		
	string ans = ask(s);
	FOR(i, 0, n)
		h1[s[i] - 'a'].PB(i);
	FOR(i, 0, n)
		h2[ans[i] - 'a'].PB(i);
	vector<pair<VI, VI> > ret;
	FOR(i, 0, 26)
		if (SZ(h1[i]))
			ret.PB(MP(h1[i], h2[i]));
	return ret;
}

//string zgeneruj(int sz)
//{
//	string res;
//	char curr = 'a';
//	FOR(i, 0, sz)
//	{
//		res += curr;
//		++curr;
//		if(curr > 'z')
//			curr = 'a';
//	}
//	return res;
//}		

const int N = 10000 + 7;
string pyt[3];
vector<pair<VI, VI> > vec[3];
vector<VI> peretyny[N];
char cnt[N][N];
int to[N];
int rev[N];

void print(VI& x)
{
	for(auto i: x)
		cout << i << " ";
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> t;
	n = SZ(t);
	FOR(i, 0, n)
	{
		pyt[0].PB((char)('a' + i / 26 / 26));
		pyt[1].PB((char)('a' + (i % (26 * 26)) / 26));
		pyt[2].PB((char)('a' + i % 26));
	}
	
	FOR(i, 0, 3)
	{
		vec[i] = asker(pyt[i]);
	//		for(auto x: vec[i])
	//		{
	//			print(x.X);
	//			print(x.Y);
	//			cout << endl;
	//		}
	}

	FOR(i, 0, 3)
	{
		FOR(j, 0, SZ(vec[i]))
		{
			auto v = vec[i][j].X;
			for(auto k: v)
				for(auto z: vec[i][j].Y)
				{
					//cout << "jdu " << k << ' ' << z << endl;
					cnt[k][z]++;
				}
		}
	}
	
	FILL(to, -1);
	FILL(rev, -1);
	
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
			if (cnt[i][j] == 3)
			{
				assert(to[i] == -1);
				to[i] = j;
			}
		
		assert(to[i] != -1);
		assert(rev[to[i]] == -1);
		rev[to[i]] = i;
	}
	
//	FOR(i, 0, n)
//	{
//		cout << rev[i] << endl;
//		//assert(rev[i] != -1);
//	}
//	
	string ANS(n, '0');
	FOR(i, 0, n)
		ANS[rev[i]] = t[i];
	cout << "! " << ANS << endl;
	fflush(stdout);
//	string fst = zgeneruj(n);
//	auto zara = asker(fst);
//	
//	for(auto i: zara)
//	{
//		VI bulo = i.X;
//		string tut = zgeneruj(SZ(bulo));
//		FOR(i, 0, SZ(bulo))
//			fst[bulo[i]] = tut[i];
//	}
//	
//	auto zara2 = asker(fst);
	
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}