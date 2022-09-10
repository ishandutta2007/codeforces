#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <iterator>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <functional>
#include <stack>
#include <deque>
#include <sstream>
using namespace std;

#define ll long long
#define mod 1000000007
#define ld long double
#define infinity (ll)1e18+1
#define PI 3.14159265358979

#define pdd pair<ld,ld>
#define pll pair<ll, ll>
#define pii pair<int,int>

#define MP make_pair
#define SZ size()
#define PB push_back

#define vi vector<int>//ll
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define vch vector<char>
#define vb vector<bool>
#define vld vector<ld>
#define vs vector<string>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 200001

int n, k, q;
vi l, r;
int a, b;

int t[4 * MAXN];
int res[MAXN];

void build(int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = a[tl];
	else {
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
	}
}

void update(int v, int tl, int tr, int l, int r, int add) {
	if (l > r)
		return;
	if (l == tl && tr == r)
		t[v] += add;
	else {
		int tm = (tl + tr) / 2;
		update(v * 2, tl, tm, l, min(r, tm), add);
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
	}
}

int get(int v, int tl, int tr, int pos) {
	if (tl == tr)
		return t[v];
	int tm = (tl + tr) / 2;
	if (pos <= tm)
		return t[v] + get(v * 2, tl, tm, pos);
	else
		return t[v] + get(v * 2 + 1, tm + 1, tr, pos);
}

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	cin >> n >> k >> q;
	l.assign(n, 0);
	r.assign(n, 0);

	FOR(i, 0, MAXN)
		res[i] = 0;

	build(res, 1, 0, n - 1);

	FOR(i, 0, n)
	{
		cin >> l[i] >> r[i];
		update(1, 0, MAXN - 1, l[i], r[i], 1);
	}

	vi pref;
	pref.assign(MAXN, 0);
	pref[0] = 0;
	FOR(i, 1, MAXN)
	{
		pref[i] = pref[i - 1];
		if (get(1, 0, MAXN - 1, i) >= k)
			pref[i]++;
	}

	REPEAT(q)
	{
		cin >> a >> b;
		cout << pref[b] - pref[a-1] << endl;
	}

	return 0;
}