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

int a[7], n;
vector<int> q[6];
int ans[100007];

int get(string s) {
	if (s == "S")
		return 0;
	if (s == "M")
		return 1;
	if (s == "L")
		return 2;
	if (s == "XL")
		return 3;
	if (s == "XXL")
		return 4;
	if (s == "XXXL")
		return 5;
}

void print(int k) {
	if (k == 0)
		cout << "S" << LN;
	if (k == 1)
		cout << "M" << LN;
	if (k == 2)
		cout << "L" << LN;
	if (k == 3)
		cout << "XL" << LN;
	if (k == 4)
		cout << "XXL" << LN;
	if (k == 5)
		cout << "XXXL" << LN;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	}
	forn(i, 6)
		cin >> a[i];
	cin >> n;
	forn(i, n) {
		string now;
		cin >> now;
		string kek;
		forn(i, now.size()){
			if (now[i] == ',')
				break;
			kek += now[i];
		}
		int ha = get(kek);
		if (now.size() == kek.size()) {
			a[ha]--;
			ans[i] = ha;
		} else {
			q[ha].pub(i);
		}
	}
	for (int i = 4; i >= 0; i--){
		for (int c : q[i]) {
			if (a[i + 1] <= 0) {
				ans[c] = i;
				a[i]--;
			} else {
				ans[c] = i + 1;
				a[i + 1]--;
			}
		}
	}
	forn(i, 6)
		if (a[i] < 0) {
			cout << "NO";
			exit(0);
		}
	cout << "YES" << LN;
	forn(i, n)
		print(ans[i]);
}