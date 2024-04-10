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

int n, m, k;
map<int, bool> ma;

int get(int len) {
	if (ma[len] != 0)
		return ma[len];
	int ans = 1;
	for (int del = 2; del * del <= len; del++) {
		if (len % del == 0) {
			int f1 = get(del);
			int f2 = get(len / del);
			bool f3 = 1, f4 = 1;
			if (del < k)
				f3 = 0;
			if (len / del < k)
				f4 = 0;
			if (f3 && f1 == 1 || f4 && f2 == 1)
				ans = 2;
			if (f3 && f1 == 2 && (len / del) % 2 == 0) {
				ans = 2;
			}
			if (f4 && f2 == 2 && del % 2 == 0) {
				ans = 2;
			}
			if (ans == 2)
				break;
		} 
	}
	if (1 >= k && len > 1)
		ans = 2;
	ma[len] = ans;
	return ans;
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
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	cin >> n >> m >> k;
	int f = get(m);
	if (f == 2 && n % 2 == 1)
		cout << "Timur";
	else
		cout << "Marsel";
}