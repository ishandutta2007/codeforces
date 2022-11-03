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
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
 
const ll P = 353251;
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
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
string a[100007];

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //ios_base::sync_with_stdio(0); cin.tie(0);  
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("just.in", "r", stdin);
        //freopen("just.out","w", stdout);
    }
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	string last = "0";

	for (int i = 0; i < n; i++) {
		string now = a[i];
		if (a[i].size() < last.size())
			cout << "NO", exit(0);
		if (last.size() < a[i].size()) {
			if (a[i][0] == '?')
				a[i][0] = '1';
			for (int j = 1; j < a[i].size(); j++)
				if (a[i][j] == '?')
					a[i][j] = '0';
		} else {
			bool bo = 0;
			int la = -1;
			for (int j = 0; j < last.size(); j++) {
				if (a[i][j] == '?') {
					if (bo) {
						a[i][j] = '0';
					} else {
						if (last[j] != '9')
							la = j;
						a[i][j] = last[j];
					}
				} else {
					if (!bo) {
						if (a[i][j] < last[j]) {
							if (la == -1)
								cout << "NO", exit(0);
							else {
								bo = 1;
								a[i][la] = last[la] + 1;
								for (int k = la + 1; k < last.size(); k++)
									if (now[k] == '?')
										a[i][k] = '0';
							}
						}
						if (a[i][j] > last[j])
							bo = 1;
					}
				}
			}
			if (!bo) {
				if (la == -1)
					cout << "NO", exit(0);
				else {
					a[i][la] = last[la] + 1;
					for (int j = la + 1; j < last.size(); j++)
						if (now[j] == '?')
							a[i][j] = '0';
				}
			}
		}
		last = a[i];
	}

	cout << "YES" << LN;
	for (int i = 0; i < n; i++)
		cout << a[i] << LN;

}