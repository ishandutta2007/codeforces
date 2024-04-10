/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n, a[100000];
priority_queue<int,vector<int>,greater<int>> todo;

template<int SZ>
class SegTree {
	public:
		int seg[2*SZ];

		SegTree() {
			memset(seg,0,sizeof seg);	
		}

		void upd(int p, int value) {  // set value at position p
			for (seg[p += SZ] = value; p > 1; p >>= 1) seg[p>>1] = min(seg[p],seg[p^1]);
		}

		void build() {
			for (int i = SZ-1; i > 0; --i) seg[i] = min(seg[2*i],seg[2*i+1]);	
		}

		int qmin(int l, int r) {  // sum on interval [l, r)
			int res = MOD;
			for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
				if (l&1) res = min(res,seg[l++]);
				if (r&1) res = min(res,seg[--r]);
			}
			return res;
		}
};

template<int SZ>
class Seg1 {
	public:
		int seg[2*SZ];

		Seg1() {
			memset(seg,0,sizeof seg);	
		}

		void upd(int p, int value) {  // set value at position p
			for (seg[p += SZ] = value; p > 1; p >>= 1) seg[p>>1] = seg[p]+seg[p^1];
		}

		void build() {
			for (int i = SZ-1; i > 0; --i) seg[i] = seg[2*i]+seg[2*i+1];	
		}

		int qmin(int l, int r) {  // sum on interval [l, r)
			int res = 0;
			for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
				if (l&1) res += seg[l++];
				if (r&1) res += seg[--r];
			}
			return res;
		}
};

SegTree <1<<18> seg;
Seg1 <1<<18> seg1;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	F0R(i,n) {
	    cin >> a[i];
	    todo.push(a[i]);
	    seg.upd(i,a[i]);
	    seg.upd(i+n,a[i]);
	    seg1.upd(i,1);
	    seg1.upd(i+n,1);
	}
	
	ll ans = 0;
	int cpos = -1;
	while (todo.size()) {
	    int lo = 1, hi = n;
	    while (lo < hi) {
	        int mid = (lo+hi)/2;
	        if (seg.qmin(cpos+1,cpos+mid+1) == todo.top()) {
	            hi = mid;
	        }
	        else lo = mid+1;
	    }
	    if (cpos != -1) {
	        seg.upd(cpos,MOD);
	        seg.upd(cpos+n,MOD);
	        seg1.upd(cpos,0);
	        seg1.upd(cpos+n,0);
	    }
	    todo.pop();
	    ans += seg1.qmin(cpos+1,cpos+lo+1);
	    cpos = (cpos+lo) % n;
	}
	cout << ans;
}