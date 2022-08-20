#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int main() {
	ll n;
    cin >> n;
    ll k = (ll) (-1+sqrt(1+8*n))/2;
   
    while(k*(k+1)/2 > n) k--;
    while((k+2)*(k+1)/2 <= n) k++;
    ll j = k*(k+1)/2;
    if (j == n) cout << k;
    else cout << (n-j);
	return 0;
}