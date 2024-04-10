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
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1 << 20;
int n, w;
LL t[N << 1];
int a[N];
PII b[N];

void add(int v, int tl, int tr, int l, int r, int val)
{
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] += val;
	else 
	{
		int tm = (tl + tr) / 2;
		add (v*2, tl, tm, l, min(r,tm), val);
		add (v*2+1, tm+1, tr, max(l,tm+1), r, val);
	}
}

LL get(int v, int tl, int tr, int pos)
{
	if (tl == tr)
		return t[v];
	
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		return t[v] + get(v * 2, tl, tm, pos);
	else
		return t[v] + get(v * 2 + 1, tm + 1, tr, pos);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);
	
	cin >> n >> w;
	FOR(iter, 0, n)
	{
		int len;
		cin >> len;
		FOR(i, 0, len)
		{
			cin >> a[i];
			b[i] = {a[i], i};
		}
		
		sort(b, b + len);
		reverse(b, b + len);
		set<int> poc;
		
		FOR(i, 0, len)
		{
			int pos = b[i].Y;
			int L = pos, R = pos + w - len;
		
			auto it = poc.lower_bound(pos);
			if (it != poc.end())
				R = min(R, *it - 1);
			
			if (it != poc.begin())
			{
				--it;
				L = max(L, *it + w - len + 1);
			}			
			
			poc.insert(pos);
			
			if (b[i].X >= 0)
				add(1, 0, w - 1, L, R, b[i].X);	
			else
			{
				if (len + len <= w)
					continue;
					
				int pochatok = w - len;
				int kinec = len - 1;
				
				L = max(L, pochatok);
				R = min(R, kinec);
				add(1, 0, w - 1, L, R, b[i].X);
			}
		}		
	}	
	
	FOR(i, 0, w)
		cout << get(1, 0, w - 1, i) << ' ';
	cout << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}