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

const int MAX = 1 << 17;
int n, m;

struct shoe
{
	int price, size, id;
};

struct customer
{
	int money, size, id;
};

int cmp1(shoe x, shoe y)
{
	if (x.size != y.size)
		return x.size > y.size;
	return x.id < y.id;
}

int cmp2(customer x, customer y)
{
	if (x.size != y.size)
		return x.size > y.size;
	return x.id < y.id;
}

shoe s[MAX];
customer c[MAX];
LL dp[MAX][2][2];
map<int, int> mp;
int best[MAX][2][2];
pair<int, PII> go[MAX][2][2];

LL get(int pos, bool tut, bool tam)
{
	if (pos == m)
		return 0;
	
	if (dp[pos][tut][tam] != -1)
		return dp[pos][tut][tam];
	
	LL res = 0;
	if (pos + 1 < m)
	{
		if (c[pos + 1].size == c[pos].size)
		{
			res = get(pos + 1, tut, tam);
			go[pos][tut][tam] = MP(pos + 1, MP(tut, tam));
		}
		else
		{
			if (c[pos + 1].size < c[pos].size - 1)
			{
				res = get(pos + 1, mp.count(c[pos + 1].size), 1);
				go[pos][tut][tam] = MP(pos + 1, MP(mp.count(c[pos + 1].size), 1));
			}
			else
			{
				res = get(pos + 1, mp.count(c[pos + 1].size), tut);
				go[pos][tut][tam] = MP(pos + 1, MP(mp.count(c[pos + 1].size), tut));
			}
		}
		
		best[pos][tut][tam] = 0;
	}
	
	if (tut && c[pos].money >= mp[c[pos].size])
	{
		LL curr = mp[c[pos].size];
		pair<int, PII> tutka(-1, MP(-1, -1));
		
		if (pos + 1 < m)
		{
			if (c[pos + 1].size == c[pos].size)
			{
				curr += get(pos + 1, 0, tam);
				tutka = MP(pos + 1, MP(0, tam));
			}
			else
			{
				if (c[pos + 1].size < c[pos].size - 1)
				{
					curr += get(pos + 1, mp.count(c[pos + 1].size), 1);
					tutka = MP(pos + 1, MP(mp.count(c[pos + 1].size), 1));
				}
				else
				{
					curr += get(pos + 1, mp.count(c[pos + 1].size), 0);
					tutka = MP(pos + 1, MP(mp.count(c[pos + 1].size), 0));
				}
			}
		}
		
		if (res < curr)
			best[pos][tut][tam] = 1, go[pos][tut][tam] = tutka;
		
		res = max(res, curr);
	}
	
	if (tam && c[pos].money >= mp[c[pos].size + 1])
	{
		pair<int, PII> tutka(-1, MP(-1, -1));
		LL curr = mp[c[pos].size + 1];
		if (pos + 1 < m)
		{
			if (c[pos + 1].size == c[pos].size)
			{
				curr += get(pos + 1, tut, 0);
				tutka = MP(pos + 1, MP(tut, 0));
			}
			else
			{
				if (c[pos + 1].size < c[pos].size - 1)
				{
					curr += get(pos + 1, mp.count(c[pos + 1].size), 1);
					tutka = MP(pos + 1, MP(mp.count(c[pos + 1].size), 1));
				}
				else
				{
					curr += get(pos + 1, mp.count(c[pos + 1].size), tut);
					tutka = MP(pos + 1, MP(mp.count(c[pos + 1].size), tut));
				}
			}
		}
		
		if (res < curr)
			best[pos][tut][tam] = 2, go[pos][tut][tam] = tutka;
		
		res = max(res, curr);
	}
	
	return dp[pos][tut][tam] = res;
}

map<int, int> ID;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	FILL(dp, -1);
	FILL(best, -1);
	cin >> n;
	int x, y;
	FOR(i, 0, n)
	{
		cin >> x >> y;
		mp[y] = x;
		ID[y] = i + 1;
		s[i] = {x, y, i + 1};
	}
	
	cin >> m;
	FOR(i, 0, m)
	{
		cin >> x >> y;
		c[i] = {x, y, i + 1};
	}

	sort(s, s + n, cmp1);
	sort(c, c + m, cmp2);	
	
	FILL(go, -1);
	LL ans = 0;
	pair<int, PII> B;
	FOR(i, 0, m)
		FOR(j, 0, 2)
			FOR(k, 0, 2)
			{
				if (j && !mp.count(c[i].size))
					continue;
				if (k & !mp.count(c[i].size + 1))
					continue;
				LL curr = get(i, j, k);
				if (ans > curr)
					continue;
				
				ans = curr;
				B = MP(i, MP(j, k));
			}
	
	cout << ans << endl;
	vector<PII> res;
//	FOR(i, 0, m)
//		FOR(j, 0, 2)
//			FOR(k, 0, 2)
//				cout << i << ' ' << j << ' ' << k << ' ' << go[i][j][k].X << ' ' << go[i][j][k].Y.X << ' ' << go[i][j][k].Y.Y << endl;
//	return 0;
	while(best[B.X][B.Y.X][B.Y.Y] != -1)
	{
		//cout << B.X << ' ' << B.Y.X << ' ' << B.Y.Y << endl;
		if (best[B.X][B.Y.X][B.Y.Y] == 1)
			res.PB(MP(ID[c[B.X].size], c[B.X].id));
		
		if (best[B.X][B.Y.X][B.Y.Y] == 2)
			res.PB(MP(ID[c[B.X].size + 1], c[B.X].id));
		
		if (go[B.X][B.Y.X][B.Y.Y] == MP(-1, MP(-1, -1)))
			break;
		B = go[B.X][B.Y.X][B.Y.Y];
	}
	
	cout << SZ(res) << endl;
	for(auto i: res)
		cout << i.Y << ' ' << i.X << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}