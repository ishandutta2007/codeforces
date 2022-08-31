#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,r; cin >> n >> r;
	double area = PI;
	double a = PI/n-sin(2*PI/n)/2;
	double s = sin(PI/n);
	a += s*s*tan(PI*(n-3)/2/n);
	area -= n*a;
	cout << fixed << setprecision(10) << area*r*r;
	return 0;
}