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

#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rep0(i, n) for(ll i = (0); i < (n); i++)
#define repd(i,m,n) for(ll i=(m); i > (n); i--)
#define iter(el, arr) for(auto& el : arr)
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()

#define ld long double
#define ll long long
#define ull unsigned ll
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define plli pair<pll,ll>
#define MP make_pair
#define SZ(a) ll((a).size())
#define X first
#define Y second

#define endl '\n'
#define PB push_back
#define has(i, m) (m.find(i) != m.end())

#define vi vector<int>
#define vll vector<ll>
#define vch vector<char>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vb vector<bool>
#define vvb vector<vb>
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define pq priority_queue
#define mod 1000000007
using namespace std;

const ll INF = 1e18;
const ll MAXN = 2001;

int n;
int q;
int c;
ll ans;
struct star
{
	int x;
	int y;
	int s;
};

vector<star> stars;

ll time_now;
pii l;
pii r;

int here[11][101][101];
int hel[11][101][101];

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);

	cin >> n >> q >> c;
	vector<star> all(n);
	FOR(i, 0, n)
		cin >> all[i].x >> all[i].y >> all[i].s;

	FOR(i, 0, 11)
		FOR(j, 0, 101)
		FOR(k, 0, 101)
		here[i][j][k] = 0, hel[i][j][k] = 0;

	FOR(i, 0, n)
		hel[all[i].s][all[i].x][all[i].y]++;

	FOR(i, 1, 101)
		FOR(j, 0, 11)
		here[j][1][i] = hel[j][1][i] + here[j][1][i - 1], here[j][i][1] = hel[j][i][1] + here[j][i - 1][1];

	FOR(i, 2, 101)
		FOR(j, 2, 101)
		FOR(k, 0, 11)
		here[k][i][j] = here[k][i - 1][j] + here[k][i][j - 1] - here[k][i - 1][j - 1] + hel[k][i][j];

	
	REPEAT(q)
	{
		cin >> time_now >> l.X >> l.Y >> r.X >> r.Y;
		ans = 0;

		int number[11];
		FOR(i, 0, 11)
			number[i] = 0;

		FOR(i, 0, 11)
			number[i] = here[i][r.X][r.Y] - here[i][l.X - 1][r.Y] - here[i][r.X][l.Y - 1] + here[i][l.X - 1][l.Y - 1];

		FOR(i, 0, 11)
			ans += number[i] * ((i + time_now) % (c + 1));
		
		cout << ans << endl;
	}


	return 0;
}
//don't forget about MAXN, INF and mod