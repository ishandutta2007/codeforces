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
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

/*
const int MAX_MEM = 2e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/

string s1, s2;
int k1, k2;
pair<int, int> was[107];

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	for (int i = 0; i < 107; i++)
		was[i] = mp(-1, -1);
	cin >> k1 >> k2 >> s1 >> s2;
	set<char> se;
	for (int i = 0; i < s1.size(); i++)
		se.insert(s1[i]);
	for (int i = 0; i < s2.size(); i++)
		if (se.find(s2[i]) == se.end())
			cout << 0, exit(0);
	int d1 = 0, d2 = 0, fa = 0;
	int kk = 0, uk, ss, uze, p = 1, st;
	while (1) {
		d1++;
		bool f = 0;
		for (int i = 0; i < s1.size(); i++)
			if (s1[i] == s2[kk]) {
				kk++;
				if (kk == s2.size()) {
					kk = 0, d2++;
					fa++;
					if (was[i] != mp(-1, -1)) {
						st = i, uk = was[i].XX, ss = d1 - was[i].XX, uze = was[i].YY;
						p = fa - was[i].YY;
						f = 1;
						break;
					}
					was[i] = mp(d1, fa);
				}
			}
		if (d1 == k1) {
			cout << fa / k2;
			exit(0);
		}
		if (f)
			break;
		if (kk == 0) {
			uk = 0;
			ss = d1;
			uze = 0;
			p = fa;
			st = (int)s1.size() - 1;
			break;
		}
	}
	//cout << uk << ' ' << ss << ' ' << uze << ' ' << p << endl;
	int can = p * (k1 - uk) / ss;
	int ans = (uze + can);
	int ost = (k1 - uk) % ss + (int)s1.size() - st - 1;
	uk = 0;
	/*for (int i = 0; i < ost; i++)
		if (s1[(st + i + 1) % (int)s1.size()] == s2[uk]) {
			uk++;
			if (uk == (int)s2.size())
				uk = 0, ans++;
		}*/
	cout << ans / k2;
}