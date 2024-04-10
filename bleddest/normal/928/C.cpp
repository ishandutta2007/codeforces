#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator << (ostream &out, pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template<class A> ostream& operator << (ostream &out, vector<A> &a) {
 	out << "[";
 	forn(i, sz(a)) {
 		if(i) out << ", ";
 		out << a[i];
 	}
 	return out << "]\n";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld PI = acosl(-1.0);
const ld EPS = 1e-9; 

mt19937 rnd(time(NULL));
mt19937_64 rnd64(time(NULL));

int n;
char buf[15];

typedef pair<string, int> project;
map<project, int> p2id;
map<int, project> id2p;

int get_id(const project& z)
{
	if (p2id.count(z))
		return p2id[z];
	int x = sz(p2id);
	id2p[x] = z;
	p2id[z] = x;
	return x;
}

vector<int> g[1043];

bool read() {
 	if(scanf("%d", &n) != 1)
 		return false;
 	forn(i, n)
 	{
 		int v;
 		scanf("%s %d", buf, &v);
 		string s = buf;
 		//cerr << s << v << endl;
 		int w = get_id(mp(s, v));
 		int k;
 		scanf("%d", &k);
 		forn(j, k)
 		{
 			scanf("%s %d", buf, &v);
 			s = buf;
 			//cerr << s << " " << v << endl;
 			int z = get_id(mp(s, v));
 			g[w].push_back(z);
 		}
 	}
 	return true;
}

int used[1043];
map<string, int> best_version;

void solve() {
	//forn(i, 9) cerr << g[i];
	used[0] = 1;
	best_version[id2p[0].x] = id2p[0].y;
	vector<int> layer(1, 0);
	while(!layer.empty())
	{
		vector<int> new_layer;
		map<string, int> cur_version;
		for(auto x : layer)
			for(auto y : g[x])
				if(!used[y])
				{
					used[y] = 1;
					new_layer.pb(y);
					cur_version[id2p[y].x] = max(cur_version[id2p[y].x], id2p[y].y);
				}
		layer.clear();
		for(auto x : new_layer)
		{
			string proj = id2p[x].x;
			int v = id2p[x].y;
			if(!best_version.count(proj) && v == cur_version[proj])
			{
				layer.pb(x);
				best_version[proj] = v;
			}
		}
	}
	
	best_version.erase(id2p[0].x);
	printf("%d\n", sz(best_version));
	for(auto x : best_version)
	{
		printf("%s %d\n", x.x.c_str(), x.y);
	}
}

int main() {
	
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int tt = clock();
#endif

	srand(time(NULL));
	cout << fixed << setprecision(15);

	if(read()) {

		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << " ms\n";
		tt = clock();
#endif

	}
	
	return 0;
}