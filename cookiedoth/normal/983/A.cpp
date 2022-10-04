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

ll p, q, b;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> p >> q >> b;
		ll g = gcd(p, q);
		p /= g;
		q /= g;
		while (true) {
			ll x = gcd(q, b);
			if (x == 1)
				break;
			while (q % x == 0) {
				q /= x;
			}
		}
		if (q == 1)
			cout << "Finite\n";
		else
			cout << "Infinite\n";
	}

}