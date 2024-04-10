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

struct cnm {
	int pred, r;
	cnm(){}
};

cnm t[10001];

int n;

int get(int v) {
	if (t[v].pred == v) return v;
	t[v].pred = get(t[v].pred);
	return t[v].pred;
}

void merge(int a, int b) {
	a = get(a), b = get(b);
	if (a != b) {
		if (t[a].r < t[b].r) swap(a, b);
		t[b].pred = a;
		if (t[a].r == t[b].r) t[a].r++;
	}
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
		//freopen("lines.in", "r", stdin);
		//freopen("lines.out", "w", stdout);
	}
	cin >> n;
	for (int i = 0; i < n; i++) t[i].pred = i, t[i].r = 0;
	for (int i = 0; i < n; i++) {
		int q;
		cin >> q;
		merge(i, q - 1);
	}
	set<int> se;
	for (int i = 0; i < n; i++)
		se.insert(get(i));
	cout << se.size();
}