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
	int n, ans[1000005];
    cin >> n;
    FOR(i,1,n/2+1) {
        ans[i] = ans[n+1-i] = 2*i-1;
    }
    FOR(i,1,(n+1)/2) {
        ans[n+i] = ans[2*n-i] = 2*i;
    }
    if (n % 2==1) {
        ans[(n+1)/2] = ans[2*n] = n;
    } else {
        ans[3*n/2] = ans[2*n] = n;
    }

    FOR(i, 1, 2*n+1) printf("%d ", ans[i]);
	return 0;
}