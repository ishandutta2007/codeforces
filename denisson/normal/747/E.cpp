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

string s;
vector<string> ans[1000007];

int get(string s) {
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		ans = ans * 10 + s[i] - '0';
	}
	return ans;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("just.in", "r", stdin);
		//freopen("just.out","w", stdout);
	}
	cin >> s;
	s += ',';
	string now = "";
	int lv = 0;
	vector<int> t;
	bool f = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ',') {
			if (!f) {
				ans[t.size()].pub(now);
			} else {
				if (now == "0") {
					if (t.size() > 0) {
						t.back()--;
						if (t.back() == 0) {
							t.pop_back();
							while (t.size() > 0 && t.back() - 1 == 0)
								t.pop_back();
							if (t.size() > 0)
								t.back()--;
						}
					}
				} else
					t.pub(get(now));
			}
			f = !f;
			now = "";
		} else {
			now += s[i];
		}
	}
	int ma = 0;
	for (int i = 0; i < 1000007; i++)
		if (ans[i].size() == 0) {
			ma = i - 1;
			break;
		}
	ma++;
	cout << ma << "\n";
	for (int i = 0; i < ma; i++) {
		for (string x : ans[i])
			cout << x << ' ';
		cout << "\n";
	}
}