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

int n;
int a[1007];
int sz = 1;
pair<int, int> t[1007 * 1007];
bool was[1007 * 1007];
vector<string> uk[1007];
int bad[1007 * 1007];

void add(int len) {
	int v = 0;
	vector<int> tt;
	tt.pub(0);
	if (bad[0] == 2)
		cout << "NO", exit(0);
	for (int i = 0; i < len; i++) {
		if (t[v].XX == -1) {
			t[v].XX = sz;
			v = sz++;
			tt.pub(v);
			continue;
		}
		if (bad[t[v].XX] != 2 && !was[t[v].XX]) {
			v = t[v].XX;
			tt.pub(v);
			continue;
		}
		if (t[v].YY == -1) {
			t[v].YY = sz;
			v = sz++;
			tt.pub(v);
			continue;
		}
		if (bad[t[v].YY] != 2 && !was[t[v].YY]) {
			v = t[v].YY;
			tt.pub(v);
			continue;
		}
		cout << "NO";
		exit(0);
	}
	reverse(all(tt));
	for (int i = 1; i < tt.size(); i++) {
		bad[tt[i]]++;
		if (bad[tt[i]] != 2)
			break;
	}
	was[v] = 1;
}

string s = "";
void go(int v) {
	if (was[v])
		uk[s.size()].pub(s);
	if (t[v].XX != -1) {
		s += '0';
		go(t[v].XX);
		s.pop_back();
	}
	if (t[v].YY != -1) {
		s += '1';
		go(t[v].YY);
		s.pop_back();
	}
}

int b[1007];

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("lasers.in", "r", stdin);
		//freopen("lasers.out","w", stdout);
	}
	for (int i = 0; i < 1007 * 1007; i++)
		t[i] = mp(-1, -1);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], b[i] = a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		add(a[i]);
	cout << "YES" << "\n";
	go(0);
	for (int i = 0; i < n; i++)
		cout << uk[b[i]].back() << "\n", uk[b[i]].pop_back();
}