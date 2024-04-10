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

int n, ans = 0, speed = 0;
vi v1 = {300};
vi v2 = {1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    
    F0R(i,n) {
        int t; cin >> t;
        if (t == 1) {
            cin >> speed;
            while (v1[v1.size()-1] < speed) v1.erase(v1.end()-1), ans++;
        } else if (t == 2) {
            while (v2[v2.size()-1] == 0) v2.erase(v2.end()-1), ans++;
        } else if (t == 3) {
            int s; cin >> s;
            if (s < speed) ans++;
            else v1.pb(s);
        } else if (t == 4) {
            v2.pb(1);
        } else if (t == 5) {
            v1.pb(300);
        } else {
            v2.pb(0);
        }
    }
    cout << ans;
}