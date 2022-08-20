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

int n,m;
int a[100000], b[100000];

ll get(int x) {
    ll sum = 0;
    F0R(i,n) sum += max(0,x-a[i]);
    F0R(i,m) sum += max(0,b[i]-x);
    return sum;
}

int main() {
    cin >> n >> m;
    F0R(i,n) cin >> a[i];
    F0R(i,m) cin >> b[i];
    
    ll lo = 0, hi = 1000000000;
    while (lo+3 <= hi) {
        if (get((2*lo+hi)/3) <= get((lo+2*hi)/3)) hi = (lo+2*hi)/3;
        else lo = (2*lo+hi)/3;
    }
    cout << min(get(lo),min(get(lo+1),get(lo+2)));
}