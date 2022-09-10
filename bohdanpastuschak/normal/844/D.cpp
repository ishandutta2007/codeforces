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

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define iter(el, arr) for(auto& el : arr)
#define ALL(a) a.begin(), a.end()

#define ld long double
#define ll long long
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

#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define vch vector<char>
#define vvi vector<vi>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vb vector<bool>
#define vvb vector<vb>
#define vs vector<string>
#define pdd pair<ld, ld>
#define vpll vector<pll>
#define vpdd vector<pdd>
#define pq priority_queue
#define mod 1000000007
	using namespace std;

const ll INF = 1e18;
const ll MAXN = 100001;

void bad()
{
	cout << "! -1" << endl;
	cout.flush();
	exit(0);
}

void good(ll v)
{
	cout << "! " << v << endl;
	cout.flush();
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	ll n, s, x;
	cin >> n >> s >> x;

	srand(time(NULL));

	cout << "? " << s << endl;
	cout.flush();
	ll val, nex;
	cin >> val >> nex;
	cout.flush();

	if (val >= x)
		good(val);

	int curr = 0;
	vpll known;
	known.push_back(MP(val, s));
	int A1 = 1000;
	int A2 = 990;

	REPEAT(A1)
	{
		curr += rand() % n + 1;
		curr %= n;
		++curr;
		cout << "? " << curr << endl;
		cout.flush();
		cin >> val >> nex;
		cout.flush();
		known.push_back(MP(val, curr));

		if (nex == -1 && val < x)
			bad();

		if (val == x)
			good(val);
	}

	sort(ALL(known));
	int first_less = 0;
	while (first_less < known.size() && known[first_less].X < x)
		first_less++;

	if (first_less == known.size())
	{
		curr = known[known.size() - 1].Y;
		REPEAT(A2)
		{
			cout << "? " << curr << endl;
			cout.flush();
			cin >> val >> nex;
			cout.flush();
			if (val >= x)
				good(val);

			curr = nex;
			if (nex == -1)
				bad();
		}
		bad();
	}

	curr = known[first_less - 1].Y;
	REPEAT(A2)
	{
		cout << "? " << curr << endl;
		cout.flush();
		cin >> val >> nex;
		if (val >= x)
			good(val);

		curr = nex;
		if (nex == -1)
			bad();
	}
	bad();
}