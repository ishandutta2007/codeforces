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
#define db double
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

int d[367];
int p[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get(string s) {
	if (s == "monday")
		return 1;
	if (s == "tuesday")
		return 2;
	if (s == "wednesday")
		return 3;
	if (s == "thursday")
		return 4;
	if (s == "friday")
		return 5;
	if (s == "saturday")
		return 6;
	if (s == "sunday")
		return 7;
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
	string s1, s2;
	cin >> s1 >> s2;
	int q1 = get(s1);
	int q2 = get(s2);
	for (int j = 1; j <= 7; j++){
		d[1] = j;
		for (int i = 2; i <= 365; i++) {
			d[i] = d[i - 1] + 1;
			if (d[i] == 8)
				d[i] = 1;
		}
		int now = 1;
		forn(i, 11) {
			if (d[now] == q1 && d[now + p[i]] == q2)
				cout << "YES", exit(0);
			now += p[i];
		}
	}
	cout << "NO";
}