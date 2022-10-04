/*
   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#define ll long long
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

using namespace std;

const ll MOD = 1e9 + 7;

int n;
string s;
map<string, int> mp;

int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < n - 1; ++i) {
		mp[s.substr(i, 2)]++;
	}
	auto it = mp.end();
	it--;
	auto it2 = it;
	while (true) {
		if (it2->second > it->second)
			it = it2;
		if (it2 == mp.begin())
			break;
		it2--;
	}
	cout << it->first << endl;
}