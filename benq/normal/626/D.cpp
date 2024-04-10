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
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

ll n, balls[5000], a[5000],b[10000], ans=0;
double ans1;

int main() {
	scanf("%d", &n);
	F0R(i,n) scanf("%d",&balls[i]);
	sort(balls,balls+n);
	F0R(i,n) FOR(j,i+1,n) a[balls[j]-balls[i]]++;
	F0R(i,5000) F0R(j,5000) b[i+j] += a[i]*a[j];
	F0R(i,5000) F0R(j,i) ans += a[i]*b[j];
	ll x = n*(n-1)/2;
	ll k = (n*(n-1)/2)*(n*(n-1)/2)*(n*(n-1)/2);
	ans1 = double(ans)/double(k);
	cout << fixed << setprecision(10) << ans1;
	return 0;
}