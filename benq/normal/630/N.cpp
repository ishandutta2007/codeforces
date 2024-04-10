#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
 
int main() {
	double a,b,c;
	cin >> a >> b >> c;
	double ans1 = (-b+sqrt(b*b-4*a*c))/(2*a);
	double ans2 = (-b-sqrt(b*b-4*a*c))/(2*a);
	cout << fixed << setprecision(10) << max(ans1,ans2) << endl << min(ans1,ans2);
	return 0;
}