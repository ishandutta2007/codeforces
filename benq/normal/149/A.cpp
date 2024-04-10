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
	int k, a[12];
    cin >> k;
    F0R(i,12) cin >> a[i];
    sort(a,a+12);
    int count = 12, asdf = 0;
    while(count>0 && asdf<k) {
        count--;
        asdf += a[count];
    }
    if (asdf<k) cout << -1;
    else cout << (12-count);
	return 0;
}