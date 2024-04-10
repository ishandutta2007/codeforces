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
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

//
/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/
//

ll n;
pair<ll, ll> a[300007];
ll ans = 1;
ll k;
multiset<ll> se;

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	}
	scanf("%I64d", &n);
	forn(i, n)
		scanf("%I64d%I64d", &a[i].XX, &a[i].YY);
	k = a[0].XX;
	sort(a + 1, a + n);
	int uk;
	for (int i = 1; i < n; i++) {
		if (a[i].XX <= k)
			uk = i;
		if (a[i].XX > k) {
			ans++;
			se.insert(a[i].YY - a[i].XX + 1);
		}
	}
	while (1) {
		ans = min(ans, (ll)se.size() + 1);
		if (se.size() == 0)
			break;
		if (*se.begin() > k)
			break;
		k -= *se.begin();
		se.erase(se.begin());
		while (uk > 0 && a[uk].XX > k)
			se.insert(a[uk].YY - a[uk].XX + 1), uk--;
		ans = min(ans, (ll)se.size() + 1);
		/*for (ll x : se)
			cout << x << ' ';
		cout << endl << "+==" << k << endl;*/
	}

	printf("%I64d", ans);
}