#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

int n, x;
string s, des = "101";

int query(string s) {
    cout << "? " << s << endl;
    int x = 0;
    // F0R(i,n) if (des[i] != s[i]) x ++;
    cin >> x;
    return x;
}

int numone(int lo, int hi) {
    string s1 = s; FOR(i,lo,hi+1) s1[i] = '1';
    int x1 = query(s1);
    return (x-x1+hi-lo+1)/2;
}

int numzero(int lo, int hi) {
    return hi-lo+1-numone(lo,hi);
} 

void solve0(int lo, int hi) {
    if (lo == hi) {
        cout << "! " << lo+1 << " " << 1 << endl;
        exit(0);
    }
    int mid = (lo+hi)/2;
    int t = numzero(lo,mid);
    if (t) solve0(lo,mid);
    else solve0(mid+1,hi);
}

void solve1(int lo, int hi) {
    if (lo == hi) {
        cout << "! " << 1 << " " << lo+1 << endl;
        exit(0);
    }
    int mid = (lo+hi)/2;
    int t = numone(lo,mid);
    if (t) solve1(lo,mid);
    else solve1(mid+1,hi);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	
	F0R(i,n) s += '0';
    x = query(s);
	
	string s1 = "1"; F0R(i,n-1) s1 += '0';
	int y = query(s1);
	
	if (x < y) solve1(1,n-1);
	else solve0(1,n-1);
}

// read!
// ll vs. int!