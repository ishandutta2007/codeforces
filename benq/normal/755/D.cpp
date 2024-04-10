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

ll sum[1<<22];

void update(int ind, int L, int R, int low) {
    if (low < L || R < low) return;
    if (low <= L && R <= low) {
    	sum[ind] = 1;
        return;
    }
    int M = (L+R)/2;
    update(2*ind,L,M,low);
    update(2*ind+1,M+1,R,low);
    sum[ind] = sum[2*ind]+sum[2*ind+1];
} 

ll query(int ind, int L, int R, int low, int high) {
	if (high < L || R < low) return 0;
	if (low <= L && R <= high) return sum[ind];
    int M = (L+R)/2;
    return (query(2*ind,L,M,low,high)+query(2*ind+1,M+1,R,low,high));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k; cin >> n >> k;
	k = min(k,n-k);
	int cur = 1;
	ll ans = 1;
	F0R(i,n) {
		ans += query(1,1,1<<21,cur+1,cur+k-1)+1;
		if (cur-k+1 >= 1) ans += query(1,1,1<<21,cur-k+1,cur-1);
		else ans += query(1,1,1<<21,cur-k+1+n,cur-1+n);
		update(1,1,1<<21,cur);
		update(1,1,1<<21,cur+n);
		cur = (cur+k) % n;
		if (cur == 0) cur += n;
		cout << ans << " ";
	}
}