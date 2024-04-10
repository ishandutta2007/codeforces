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

string s1, s2;
int pr[100007], suf[100007];
int was[100007];

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
	cin >> s1 >> s2;
	int uk = 0;
	for (int i = 0; i < s2.size(); i++) {
		while (uk < s1.size() && s1[uk] != s2[i]) uk++;
		if (uk >= s1.size())
			pr[i] = s1.size() + 1;
		else
			pr[i] = uk;
		uk++;
	}
	uk = (int)s1.size() - 1;
	for (int i = (int)s2.size() - 1; i >= 0; i--) {
		while (uk >= 0 && s1[uk] != s2[i]) uk--;
		if (uk < 0)
			suf[i] = -1;
		else
			suf[i] = uk;
		uk--;
	}
	suf[s2.size()] = s1.size();
	int poss = -1, mi = INF;
	for (int i = 0; i < s2.size(); i++) {
		int now = -1;
		if (i - 1 >= 0) now = pr[i - 1];
		if (now == s1.size() + 1) break;
		int pos = now;
		int l = i - 1, r = s2.size() + 1;
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			if (suf[m] > pos) r = m;
			else l = m;
		}
		was[i] = r;
		int lennow = r - i - 1;
		if (lennow < mi) {
			mi = lennow;
			poss = i;
		}
	}
	string ans;
	for (int i = 0; i < poss; i++) {
		ans += s2[i];
	}
	for (int i = was[poss]; i < s2.size(); i++) {
		ans += s2[i];
	}
	if (ans.size() == 0) cout << "-"; else cout << ans;
}