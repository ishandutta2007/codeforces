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

const int MAX = 1 << 10;

void go(PII s, PII f, vector<PII>& a)
{	
	a.PB(s);
	//cout << s.X << " " << f.X << endl;
	while (s.X > f.X)
	{
		s.X--;
		a.PB(s);
	}
	
	while(s.X < f.X)
	{
		s.X++;
		a.PB(s);
	}
	
	while (s.Y > f.Y)
	{
		s.Y--;
		a.PB(s);
	}
	
	while(s.Y < f.Y)
	{
		s.Y++;
		a.PB(s);
	}


	a.PB(f);
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);
	
	vector<PII> a(3);
	FOR(i, 0, 3)
		cin >> a[i].X >> a[i].Y;
	
	vector<PII> ans1, ans2;
	sort(ALL(a));
	go(a[0], a[1], ans1);
	go(a[1], a[2], ans1);
	
	go(a[0], {a[1].X, a[2].Y}, ans2);
	go(a[1], {a[1].X, a[2].Y}, ans2);
	go(a[2], {a[1].X, a[2].Y}, ans2);								
	
	sort(ALL(ans1));
	ans1.resize(unique(ALL(ans1)) - ans1.begin());
	
	sort(ALL(ans2));
	ans2.resize(unique(ALL(ans2)) - ans2.begin());
		
	vector<PII> ans = ans1;
	if (SZ(ans2) < SZ(ans1))
		ans = ans2;
//	
//	if ((a[1].Y >= a[0].Y && a[2].Y <= a[0].Y) || (a[1].Y <= a[0].Y && a[2].Y >= a[0].Y))
//	{
//		go(a[0], a[1], ans);
//		go(a[1], a[2], ans);
//	}
//	else
//	{
//		if (a[1].Y >= a[0].Y)
//		{
//
//			if (a[1].Y <= a[2].Y)
//			{
//				go(a[0], a[1], ans);
//				go(a[1], a[2], ans);
//			}
//			else
//			{
//				go(a[0], {a[1].X, a[2].Y}, ans);
//				go(a[1], {a[1].X, a[2].Y}, ans);
//				go(a[2], {a[1].X, a[2].Y}, ans);								
//			}
//		}
//		else
//		{
//			if (a[1].Y >= a[2].Y)
//			{
//				go(a[0], a[1], ans);
//				go(a[1], a[2], ans);
//			}
//			else
//			{
//				go(a[0], {a[1].X, a[2].Y}, ans);
//				go(a[1], {a[1].X, a[2].Y}, ans);
//				go(a[2], {a[1].X, a[2].Y}, ans);					
//			}
//		}
//	}
//	
	sort(ALL(ans));
	ans.resize(unique(ALL(ans)) - ans.begin());
	cout << SZ(ans) << endl;
	for(auto i: ans)
		cout << i.X << ' ' << i.Y << endl;
	
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}