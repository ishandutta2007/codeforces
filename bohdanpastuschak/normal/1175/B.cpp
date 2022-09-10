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
const LL INF = 1LL << 32;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void bad()
{
	cout << "OVERFLOW!!!" << endl;
	exit(0);
}

const int N = 1 << 18;
pair<string, int> s[N];
int kin[N];

LL solve(int l, int r)
{
	if (l > r)
		return 0;
		
	LL tut = 0;	
	lol:	
	while(l <= r && s[l].X == "add")
		tut++, l++;
	
	if (l > r)
		return tut;
		
	tut += solve(l + 1, kin[l] - 1) * s[l].Y;
	if (tut >= INF)
		bad();
	
	l = kin[l] + 1;
	goto lol;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	int l;
	cin >> l;
	FOR(it, 0, l)
	{
		string x;
		cin >> x;
		int y = 0;
		if (x == "for")
			cin >> y;
		
		s[it] = MP(x, y);
	}

	stack<int> st;
	FOR(i, 0, l)
		if (s[i].X == "for")
			st.push(i);
		else if (s[i].X == "end")
		{
			int id = st.top();
			st.pop();
			kin[id] = i;
		}
		
	LL ans = 0;
	FOR(i, 0, l)
	{
		if (s[i].X == "add")
			++ans;
		else
		{
			LL kek = solve(i + 1, kin[i] - 1) * s[i].Y;
			i = kin[i];
			ans += kek;
			
			if (ans >= INF)
				bad();
		}		
	}
	

	if (ans >= INF)
		bad();

		
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}