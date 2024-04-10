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

#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

vector<pii> segments, ans;
int n,k,a,b, count1=0,begin1,z,q,v,cur;

int main() {
	scanf("%d%d",&n,&k);
	F0R(i,n) {
		scanf("%d%d",&a,&b);
		segments.pb(mp(a,1));
		segments.pb(mp(b,-1));
	}
	sort(segments.begin(),segments.end());
	F0R(i,2*n) {
		cur = 0;
		q = count1;
		z = segments[i].f;
		v = i;
		if (segments[i].s == 1) {
			count1++;
			cur++;
		} else count1 --;
		while ((i+1)<2*n && segments[i+1].f == z) {
			i++;
			if (segments[i].s == 1) {
				count1++;
				cur++;
			} else count1 --;
		}
		if (q >= k) {
			if (count1 < k) ans.pb(mp(begin1,z));
		} else if (count1 >= k) begin1 = z;
		else if (q+cur >= k) ans.pb(mp(z,z));
	}
	printf("%d\n", ans.size());
	F0R(i,ans.size()) printf("%d %d\n",ans[i].f,ans[i].s);
	return 0;
}