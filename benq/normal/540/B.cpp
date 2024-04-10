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
	int n,k,p,x,y;
	vi track,ans;
	cin >> n >> k >> p >> x >> y;
	
	F0R(i,k) {
		int a;
		cin >> a;
		track.pb(a);
	}
	
	sort(track.begin(),track.end());
	int curmed = 0, curmed2 = 0;
	F0R(i,k) {
		if (track[i]<y) curmed++;
		else break;
	}
	if (curmed >= (n+1)/2) {
		cout << -1;
		return 0;
	}
	F0R(i,(n-1)/2-curmed) ans.pb(1);
	F0R(i,(n+1)/2-k+curmed) ans.pb(y);

	int sum = 0;
	F0R(i,k) sum += track[i];
	F0R(i,n-k) sum += ans[i];
	
	if (sum>x) {
		cout << -1;
		return 0;
	}
	
	F0R(i,n-k) cout << ans[i] << " ";
	return 0;
}