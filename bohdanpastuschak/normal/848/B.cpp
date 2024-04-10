#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>
#include <functional>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <list>
#include <sstream>
#include <tuple>

#define ld long double
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll,ll>
#define MP make_pair
#define MT make_tuple
#define SZ(a) ll((a).size())
#define X first
#define Y second
#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REPEAT(t) FOR(name_that_will_never_apper, 0, t)
#define iter(el, arr) for(auto& el : arr)
#define ALL(a) a.begin(), a.end()

#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define vch vector<char>
#define vb vector<bool>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvch vector<vch>
#define vvb vector<vb>
#define vs vector<string>
#define vss vector<vs>
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define PI 3.141592653589793
using namespace std;

#define alphabet_size 26
#define mod 1000000007
#define INF (ll)1e18
#define MAXN 100001

int n;
int w;
int h;
vpii all;
vector<pair<pii, int>> a, b;

int compare(const int &lhs, const int &rhs)
{
	return (all[lhs].X < all[rhs].X);
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> w >> h;
	int aa, bb, cc;
	
	vch chy_a;
	FOR(i, 0, n)
	{
		cin >> aa >> bb >> cc;
		if (aa == 2)
			a.push_back(MP(MP(bb, cc), i));
		else
			b.push_back(MP(MP(bb, cc), i));
		all.push_back(MP(bb, cc));
		chy_a.push_back(0);
		if (aa == 2)
			chy_a[i] = 1;
	}
	
	set<int> in_a;
	FOR(i, 0, a.size())
		in_a.insert(a[i].Y);

	map<int, vi> m;
	FOR(i, 0, a.size())
		m[a[i].X.X - a[i].X.Y].push_back(a[i].Y);

	FOR(i, 0, b.size())
		m[b[i].X.X - b[i].X.Y].push_back(b[i].Y);

	vpii ans(n), ANS(n);
	FOR(i, 0, n)
		if (chy_a[i] == 1)
			ans[i] = MP(w, all[i].X);
		else
			ans[i] = MP(all[i].X, h);

	vi vec;
	vi vec_a, vec_b;
	vi numerac;
	for (auto i : m)
	{
		numerac.clear();
		vec_a.clear();
		vec_b.clear();
		vec = i.second;
		FOR(i, 0, vec.size())
			if (has(vec[i], in_a))
				vec_a.push_back(vec[i]);
			else
				vec_b.push_back(vec[i]);

				
		sort(ALL(vec_a), compare);
		sort(ALL(vec_b), compare);

		
		FOR(i, 0, vec_a.size())
			numerac.push_back(vec_a[i]);

		RFOR(i, vec_b.size(), 0)
			numerac.push_back(vec_b[i]);

		
		int curr = 0;
		RFOR(i, vec_b.size(), 0)
			ANS[vec_b[i]] = ans[numerac[curr++]];

		FOR(i, 0, vec_a.size())
			ANS[vec_a[i]] = ans[numerac[curr++]];
	}


	
	FOR(i, 0, n)
		cout << ANS[i].X << " " << ANS[i].Y << endl;
	//cin >> n;
	return 0;
}