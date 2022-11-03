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
 
const int p1 = 353251;
const int p2 = 239017;
const int mod = 1e9 + 7;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
 
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

int n, p;
pair<int, int> a[100007];

bool can(double x) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		if ((double)a[i].x * (double)x > (double)a[i].y)
			sum -= (double)a[i].y - (double)a[i].x * (double)x;
	}
	if ((double)sum <= (double)x * (double)p) return 1;
	return 0;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("beads.in", "r", stdin);
		//freopen("beads.out", "w", stdout);
	}
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; i++) scanf("%d %d", &a[i].x, &a[i].y);
	ll ss = 0;
	for (int i = 0; i < n; i++) ss += a[i].x;
	if (ss <= (ll)p) cout << -1, exit(0);
	double l = 0, r = 1e11;
	for (int i = 0; i < 200; i++) {
		double m = (double)(l + r) / (double)2;
		if (can(m))
			l = m;
		else
			r = m;
	}
	cout.precision(8);
	cout << fixed << l;
}