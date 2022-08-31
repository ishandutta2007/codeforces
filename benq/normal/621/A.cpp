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

ll n, odds=0, minodd = 1999999999, sum=0;

int main() {
	cin >> n;
	F0R(i,n) {
		ll a;
		cin >> a;
		sum += a;
		if (a % 2 == 1) {
			if (a<minodd) minodd=a;
			odds++;
		}
	}
	if (odds % 2 == 1) sum -= minodd;
	cout << sum;
	return 0;
}