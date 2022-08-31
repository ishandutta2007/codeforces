#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

string a,b;

int main() {
	cin >> a >> b;
	if (a.size() > b.size()) {
		F0R(i,a.size()-b.size()) if (a[i] > '0') {
			cout << '>';
			return 0;
		}
		a = a.substr(a.size()-b.size(),b.size());
	} else if (a.size() < b.size()) {
		F0R(i,b.size()-a.size()) if (b[i] > '0') {
			cout << '<';
			return 0;
		}
		b = b.substr(b.size()-a.size(),a.size());
	} 
	F0R(i,a.size()) {
		if (a[i]>b[i]) {
			cout << '>';
			return 0;
		} else if (a[i] < b[i]) {
			cout << '<';
			return 0;
		}
	}
	cout << '=';
	return 0;
}