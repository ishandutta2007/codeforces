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
int k[7];

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
	cin >> s >> s;
	if ((int)s.size() % 4 != 0)
		cout << "===", exit(0);
	int need = (int)s.size() / 4;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A')
			k[0]++;
		if (s[i] == 'C')
			k[1]++;
		if (s[i] == 'G')
			k[2]++;
		if (s[i] == 'T')
			k[3]++;
		if (s[i] == '?')
			k[4]++;
	}
	for (int i = 0; i < 4; i++)
		if (k[i] > need)
			cout << "===", exit(0);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '?') {
			if (k[0] != need) {
				s[i] = 'A';
				k[0]++;
				continue;
			}
			if (k[1] != need) {
				s[i] = 'C';
				k[1]++;
				continue;
			}
			if (k[2] != need) {
				s[i] = 'G';
				k[2]++;
				continue;
			}
			if (k[3] != need) {
				s[i] = 'T';
				k[3]++;
				continue;
			}
		}
	} 
	cout << s;
}