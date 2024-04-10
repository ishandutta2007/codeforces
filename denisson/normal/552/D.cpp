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
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
 
using namespace std;
 
typedef long long ll;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const string LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
 
const ll P = 353251;
const ll P1 = 239017;
const ll P2 = 239017;
const ll MOD = 1e4 + 7;
const ll MOD2 = 1e9 + 9;

//

const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }

//

int n;
pair<int, int> a[2007];
map<pair<pair<int, int>, pair<int, int> >, int> ma;
pair<int, int> ss[3];
int gg[2007 * 2007];

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll go() {
	int ans = 0;
	forn(i, n)
		forn(j, n)
			forn(k, n) {
			if (i != j && i != k && j != k) {
				ss[0] = a[i];
				ss[1] = a[j];
				ss[2] = a[k];
				sort(ss, ss + 3);
				pair<int, int> d1 = mp(ss[1].XX - ss[0].XX, ss[1].YY - ss[0].YY);
				pair<int, int> d2 = mp(ss[2].XX - ss[0].XX, ss[2].YY - ss[0].YY);
				if (d1.XX * d2.YY != d1.YY * d2.XX)
					ans++;
			}
	}
	return ans / 6;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("fisher.in", "r", stdin);
		//freopen("fisher.out", "w", stdout);
	}
	while (1) {
		/*ma.clear();
		n = rand() % 15;
		set<pair<int, int> > rt;
		while (rt.size() < n) {
			rt.insert(mp(rand() % 5, rand() % 5));
		}
		int g = 0;
		for (auto q : rt)
			a[g++] = q;*/
		cin >> n;
		forn(i, n)
			scanf("%d%d", &a[i].XX, &a[i].YY);
		for (int s = 2; s <= 2005; s++)
			gg[s * (s - 1)] = s;
		forn(i, n)
			forn(j, n) {
			if (i != j) {
				int x = a[i].XX - a[j].XX;
				int y = a[i].YY - a[j].YY;
				if (x < 0)
					x = -x, y = -y;
				if (x != 0 && y != 0) {
					int p = gcd(abs(x), abs(y));
					x /= p;
					y /= p;
				}
				if (x == 0)
					y = 1;
				if (y == 0)
					x = 1;
				if (x == 0) {
					ma[mp(mp(x, y), mp(a[i].XX, 0))]++;
				} else {
					if (a[i].XX < 0) {
						int k = (-a[i].XX + x - 1) / x;
						int d = a[i].YY + k * y;
						int d2 = a[i].XX + k * x;
						ma[mp(mp(x, y), mp(d2, d))]++;
					} else {
						int k = (a[i].XX) / x;
						int d = a[i].YY - k * y;
						int d2 = a[i].XX - k * x;
						ma[mp(mp(x, y), mp(d2, d))]++;
					}
				}
			}
		}
		ll ans = 0;
		for (auto t : ma) {
			int now = gg[t.second];
			//cout << t.XX.XX.XX << ' ' << t.XX.XX.YY << ' ' << t.XX.YY.XX << ' ' << t.XX.YY.YY << endl;
			ans += (ll)(n - now) * (ll)t.second;
		}
		/*if (ans / 6 != go()) {
			forn(i, n)
				cout << a[i].XX << ' ' << a[i].YY << endl;
			cout << go() << ' ' << ans / 6 << endl;
			exit(0);
		}*/
		//cout << go() << endl;
		cout << ans / 6 << endl;
		exit(0);
	}
}