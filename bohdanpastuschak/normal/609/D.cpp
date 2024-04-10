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
const int INF = 1e9 + 47;
const LL LINF = INF *(LL) INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 18;
int n, m, k, s;
int a[N];
int b[N];
PII c[N];
PII dol[N];
PII eur[N];
int p1, p2;
LL pref1[N];
LL pref2[N];
PII mna[N];
PII mnb[N];

bool ok(int day)
{
	FOR(i, 0, p1 + 1)
	{
		if (i + p2 < k)
			continue;
			
		LL dolariv = i > 0 ? pref1[i - 1] : 0;
		LL euro = k >= i ? pref2[k - i - 1] : 0;
		LL treba = dolariv * mna[day].X + euro * mnb[day].X;
		if (treba <= s)
			return 1;
	}
	
	return 0;
}

void go(int day)
{
	FOR(i, 0, p1 + 1)
	{
		if (i + p2 < k)
			continue;
			
		LL dolariv = i > 0 ? pref1[i - 1] : 0;
		LL euro = k >= i ? pref2[k - i - 1] : 0;
		LL treba = dolariv * mna[day].X + euro * mnb[day].X;
		
		if (treba > s)
			continue;
		
		cout << day + 1 << endl;
		vector<PII> ans;
		
		FOR(j, 0, i)		
			ans.PB({dol[j].Y, mna[day].Y});
		FOR(j, 0, k - i)
			ans.PB({eur[j].Y, mnb[day].Y});
	
		assert(SZ(ans) >= k);
		ans.resize(k);
		for(auto j: ans)
			cout << j.X << ' ' << j.Y << endl;
			
		return;
	}
	
	assert(0);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> m >> k >> s;
	FOR(i, 0, n)
	{
		cin >> a[i];
		if (i == 0 || mna[i - 1].X > a[i])
			mna[i] = {a[i], i + 1};
		else
			mna[i] = mna[i - 1];
	}
	
	FOR(i, 0, n)
	{
		cin >> b[i];
		if (i == 0 || mnb[i - 1].X > b[i])
			mnb[i] = {b[i], i + 1};
		else
			mnb[i] = mnb[i - 1];
	}
	
	FOR(i, 0, m)
	{
		cin >> c[i].X >> c[i].Y;
		if (c[i].X == 1)
			dol[p1++] = {c[i].Y, i + 1};
		else
			eur[p2++] = {c[i].Y, i + 1};
	}
	
	sort(dol, dol + p1);
	sort(eur, eur + p2);
	
	FOR(i, 0, p1)
		pref1[i] = dol[i].X + (i > 0 ? pref1[i - 1] : 0);
	FOR(i, 0, p2)
		pref2[i] = eur[i].X + (i > 0 ? pref2[i - 1] : 0);
	
	int l = -1, r = n - 1;
	if (!ok(r))
	{
		cout << -1;
		return 0;
	}
	
	while(r - l > 1)
	{
		int med = (l + r) >> 1;
		if (ok(med))
			r = med;
		else
			l = med;
	}
	
	go(r);
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}