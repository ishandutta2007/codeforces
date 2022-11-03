#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef unsigned long long ll;
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define clr(a, n) memset(a, n, sizeof(a));
#define sqr(x) x*x
#define mp make_pair
#define pb push_back
#define pob pop_back
#define XX first
#define YY second
#define in insert
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 dsfgsdfgsdfgsdfgsdfgsdfg1
#define sz size
#define rs resize
#define vec vector
#define all(a) a.begin(), a.end()
const str LN = "\n";
const double eps = 1e-7;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;

const bool is_testing = 0;
//const int p = 997;
const int MOD = (int)1e9;
const int MOD2 = (int)1e9 + 11;
const int MAXN = (int)2e5 + 7;

int n;
pair<int, int> a[1007];
int ans = 0;
vec< pair< pair<int, int>, int> > q1, q2;

int op (pair<int, int> a, pair<int, int> b)
{
	if (a.XX == b.XX)
	{
		if (b.YY > a.YY)
			re 1;
		re 3;
	}
	else
	{
		if (b.XX > a.XX)
			re 2;
		re 4;
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	//freopen("st2d.in", "r", stdin);
	//freopen("st2d.out", "w", stdout);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	}
	cin >> n;
	forn(i, n + 1)
		cin >> a[i].XX >> a[i].YY;
	forn(i, n - 1)
	{
		pair<int, int> t1 = a[i];
		pair<int, int> t2 = a[i + 1];
		pair<int, int> t3 = a[i + 2];
		int type = op(t1, t2);
		int type2 = op(t2, t3);
		if (type == 1)
			if (type2 == 4)
				ans++;
		if (type == 2)
			if (type2 == 1)
				ans++;
		if (type == 3)
			if (type2 == 2)
				ans++;
		if (type == 4)
			if (type2 == 3)
				ans++;
	}
	/*
	forn(i, n)
	{
		pair<int, int> t1 = a[i];
		pair<int, int> t2 = a[i + 1];
		if (t1.XX == t2.XX)
			q1.pb( mp ( mp( min(t1.YY, t2.YY), max(t1.YY, t2.YY) ) , t1.XX) );
		else
			q2.pb( mp ( mp( min(t1.XX, t2.XX), max(t1.XX, t2.XX) ) , t1.YY) );
	}

	forn(i, n)
	{
		pair<int, int> t1 = a[i];
		pair<int, int> t2 = a[i + 1];
		if (t1.XX == t2.XX)
		{
			if (t2.YY > t1.YY)
			{
				bool f = false;
				forn(j, q2.size())
					if (q2[j].YY > t2.YY)
					{
						if (in(t1.XX, q2[j].XX.XX, q2[j].XX.YY))
							f = true;
					}
				if (f)
					ans++;
			}
			else
			{
				bool f = false;
				forn(j, q2.size())
					if (q2[j].YY < t2.YY)
					{
						if (in(t1.XX, q2[j].XX.XX, q2[j].XX.YY))
							f = true;
					}
				if (f)
					ans++;
			}
		}
		else
		{
			if (t2.XX > t1.XX)
			{
				bool f = false;
				forn(j, q1.size())
					if (q1[j].YY > t2.XX)
					{
						if (in(t1.YY, q1[j].XX.XX, q1[j].XX.YY))
							f = true;
					}
				if (f)
					ans++;
			}
			else
			{
				bool f = false;
				forn(j, q1.size())
					if (q1[j].YY < t2.XX)
					{
						if (in(t1.YY, q1[j].XX.XX, q1[j].XX.YY))
							f = true;
					}
				if (f)
					ans++;
			}
		}
		cout << ans << LN;
	}
	*/
	cout << ans;
	//system("pause");			
	return 0;
}