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
#include <random>
#include <cassert>
 
using namespace std;

typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)4e18 + 7;
const double pi = acos(-1.0);
 
const ll p1 = 353251;
const ll p2 = 239017;
const ll mod = 1e9 + 7;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
 
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

int n;
int a[507];
ll ans = LINF;

set<int> was;

ll get(int x) {
    if (x <= 0) return LINF;
    if (was.find(x) != was.end()) return LINF;
    was.insert(x);
	ll fa = 0;
	for (int i = 0; i < n; i++) {
	    ll s = a[i];
	    ll k = s / (x + 1);
	    ll ost = s % (x + 1);
	    fa += k;
	    if (ost == 0) continue;
	    ll need = x - ost;
	    fa++;
	    if (need > k) return LINF;
	    
	}
	//cout << x << ' ' << fa << endl;
	return fa;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("beads.in", "r", stdin);
		//freopen("beads.out", "w", stdout);
	}
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= 40000; i++) ans = min(ans, get(i));
    for (int i = 1; i <= 40000; i++) ans = min(ans, get(a[0] / i));
    for (int i = 1; i <= 40000; i++) ans = min(ans, get(1 + a[0] / i));
    for (int i = 1; i <= 40000; i++) ans = min(ans, get(-1 + a[0] / i));
	cout << ans;
}