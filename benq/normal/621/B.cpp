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

ll array1[2001], array2[2001];

ll combo(int x) {
	return x*(x-1)/2;
}

int main() {
	ll n;
	cin >> n;
	F0R(i,n) {
		ll a,b;
		cin >> a >> b;
		array1[a+b] ++;
		array2[a-b+1000] ++;
	}
	ll ans=0;
	F0R(i,2001) {
		ans += combo(array1[i])+combo(array2[i]);
	}
	cout << ans;
	return 0;
}