#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int n;
pair<ll,ll> bit1[100001]; // stores position of num
double ans = 0;
vi nums;

void upd(int a, int val) {
	while (a <= n) {
		bit1[a].s += val;
		bit1[a].f ++;
		a += (a & -a);
	}
}

pair<ll,ll> query(int a) {
	pair<ll,ll> fin;
	while (a>0) {
		fin.f += bit1[a].f;
		fin.s += bit1[a].s;
		a -= (a & -a);
	}
	return fin;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	// for every pair a<b
	// probability that it changes is a*(n+1-b)/n/(n+1)
	// store segment tree with position for each
	// add to segment tree from top to bottom
	cin >> n; nums.resize(n);
	F0R(i,n) cin >> nums[i];
	
	F0Rd(i,n) {
		upd(nums[i],i);
		
		// how many are greater?
		auto a1 = query(n);
		auto a2 = query(nums[i]);
		auto a = mp(a1.f-a2.f,a1.s-a2.s);
		ans += (double)(i+1)*(a.f*n-a.s)/n/(n+1);
		// probability that it flips is less than 1/2 :o
		
		// less
		auto b = query(nums[i]-1);
		ans += b.f-(double)(i+1)*(b.f*n-b.s)/n/(n+1);
		// cout << ans << "\n";
		// what if it's not inverted?
	}
	cout << fixed << setprecision(15) << ans;
}