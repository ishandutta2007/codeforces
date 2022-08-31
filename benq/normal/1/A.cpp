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

ll ceil (ll x, ll y) {
	if (x % y == 0) return x/y;
	else return (x/y+1);
}

int main() {
	ll n,m,a;
	cin >> n >> m >> a;
	cout << ceil(n,a)*ceil(m,a);
	return 0;
}