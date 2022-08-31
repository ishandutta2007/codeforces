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

int mod = 1000000000;

int main() {
	int n;
	ll b;
	vector<ll> cur;
	cin >> n >> b;
	// n = 200000, b = 1000;
	b++;
	F0R(i,n) {
		int x,y;
		// cout << x << " " << y << endl;
		scanf("%d%d",&x,&y);
		while(cur.size()>0 && cur[0]<= (ll)(x)) cur.erase(cur.begin());
		if (cur.size()<b) {
			if (cur.size() != 0) {
				int k = cur.size();
				cout << (cur[k-1]+(ll)(y)) << " ";
				cur.pb(cur[k-1]+(ll)(y));
			} else {
				cur.pb(x+y);
				printf("%d ",x+y);
			}
		} else printf("%d ",-1);
	}
	return 0;
}