#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define forn(i, n) fore(i, 0, n)
#define all(a) (a).begin(), (a).end() 
#define sz(a) (int((a).size()))

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const int MOD = INF + 7;
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(-1.0);

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B>& p)
{
	return out << "(" << p.x << ", " << p.y << ")";
}

template<class A> ostream& operator <<(ostream& out, const vector<A>& p)
{
	out << "[";
	forn(i, sz(p))
	{
	 	if(i) out << ", ";
		out << p[i];
	}
	return out << "]";

}

const int N = 200043;
const int K = 5;
const int M = 120;

int nxt[M][M];
int n, k;
int a[N];
queue<int> pos[M];

int fact[10];

int rnk(vector<int> z)
{
	if(z.empty())
		return 0;
	int k = z[0];
	vector<int> z2;
	for(int i = 1; i < sz(z); i++)
		if(z[i] > k)
			z2.pb(z[i] - 1);
		else
			z2.pb(z[i]);
	return k * fact[sz(z2)] + rnk(z2);
}

bool read()
{
 	if(!(cin >> n >> k))
		return false;
	forn(i, n)
	{
		vector<int> p(k);
		forn(j, k)
		{
			cin >> p[j];
			--p[j];
		}
		a[i] = rnk(p);
	}
	return true;
}

void solve()
{
	vector<int> p1;
	forn(i, k) p1.pb(i);
	do
	{
		int r = rnk(p1);
		vector<int> p2;
		forn(i, k) p2.pb(i);
		do
		{
			int r2 = rnk(p2);
			vector<int> p3(k);
			forn(i, k) p3[i] = p1[p2[i]];
			int r3 = rnk(p3);
			nxt[r][r2] = r3;
		}
		while(next_permutation(all(p2)));
	}
	while(next_permutation(all(p1)));
	/*forn(i, fact[k]) 
	{
		set<int> zz;
		forn(j, fact[k])
		{
	 		cerr << i << " " << j << " " << nxt[i][j] << endl;
	 		zz.insert(nxt[i][j]);
	 	}
	 	cerr << sz(zz) << endl;
	}*/
	forn(i, n) pos[a[i]].push(i);
	li ans = -n;
	forn(i, n)
	{
		vector<int> used(fact[k], 0);
		used[0] = 1;
		vector<int> reachable(1, 0);
		vector<pair<int, int> > ch;
		forn(j, fact[k])
		{
			if(!pos[j].empty())
				ch.pb(mp(pos[j].front(), j));
		}
		int last = i - 1;
		sort(all(ch));
		vector<int> vv;
		forn(j, sz(ch))
		{
			int c = ch[j].y;
			int d = ch[j].x;
			ans += sz(reachable) * (d - last);
			last = d;
			if(!used[c])
			{
				vv.pb(c);
				queue<int> q;
				for(auto x : reachable) q.push(x);
				while(!q.empty())
				{
					int k = q.front();
					q.pop();
					for(auto c : vv)
					{
						if(!used[nxt[c][k]])
						{
							q.push(nxt[c][k]);
							reachable.pb(nxt[c][k]);
							used[nxt[c][k]] = 1;
						}
						if(!used[nxt[k][c]])
						{
							q.push(nxt[k][c]);
							reachable.pb(nxt[k][c]);
							used[nxt[k][c]] = 1;
						}
					}
				}
				//sort(all(reachable));
				//cerr << reachable << endl;
			}
		}
		ans += sz(reachable) * (n - last);
		//cerr <<  n << " " << last << " " << sz(reachable) << endl;
		pos[a[i]].pop();
	}
	cout << ans << endl;
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	ld curt = clock();
#endif        
	fact[0] = 1;
	forn(i, 9) fact[i + 1] = fact[i] * (i + 1);
	cout << setprecision(15) << fixed;
	cerr << setprecision(15) << fixed;
	read();
	solve();
#ifdef _DEBUG
	cerr << (clock() - curt) << endl;
#endif
}