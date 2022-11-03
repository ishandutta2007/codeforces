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

int a, b, c, n;
vector<int> t1, t2;

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("subrev.in", "r", stdin);
		//freopen("subrev.out", "w", stdout);
	}
	cin >> a >> b >> c >> n;
	for (int i = 0; i < n; i++) {
		int k;
		string s;
		cin >> k >> s;
		if (s[0] == 'U') {
			t1.pub(k);
		} else {
			t2.pub(k);
		}
	}
	sort(all(t1));
	sort(all(t2));
	int kol = 0;
	ll sum = 0;
	int uk1 = 0, uk2 = 0;
	while (1) {
		if (a == 0 || uk1 == t1.size()) break;
		a--; 
		kol++;
		sum += (ll)t1[uk1++];
	}
	while (1) {
		if (b == 0 || uk2 == t2.size()) break;
		b--; 
		kol++;
		sum += (ll)t2[uk2++];
	}
	vector<int> t3;
	for (int i = uk1; i < t1.size(); i++) t3.pub(t1[i]);
	for (int i = uk2; i < t2.size(); i++) t3.pub(t2[i]);
	sort(all(t3));
	int ukk = 0;
	while (1) {
		if (c == 0 || ukk == t3.size()) break;
		c--; 
		kol++;
		sum += (ll)t3[ukk++];
	}
	cout << kol << ' ' << sum;
}