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
const ll MOD = 1e9 + 7;
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

int n;
string s1, s2;
int a, q1, q2;

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
	cin >> n >> s1 >> s2;
	forn(i, 2 * n) {
		if (s1[i] == '1' && s2[i] == '1')
			a++;
		else {
			if (s1[i] == '1')
				q1++;
			if (s2[i] == '1')
				q2++;
		}
	}
	int k1 = 0, k2 = 0;
	forn(i, 2 * n) {
		if (i % 2 == 0) {
			if (a > 0)
				a--, k1++;
			else {
				if (q1 > 0) {
					q1--;
					k1++;
				} else {
					if (q2 > 0)
						q2--;
				}
			}
		} else {
			if (a > 0)
				a--, k2++;
			else {
				if (q2 > 0) {
					q2--;
					k2++;
				} else {
					if (q1 > 0)
						q1--;
				}
			}
		}
	}
	if (k1 == k2)
		cout << "Draw";
	if (k1 > k2)
		cout << "First";
	if (k2 > k1)
		cout << "Second";
}