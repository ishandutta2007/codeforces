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

string s;
vi a(6);
int ans = MOD;

int test1(int sum) {
    int s1 = a[0]+a[1]+a[2];
    if (s1 == sum) return 0;
    if (s1 > sum) {
        int z = max(a[0],max(a[1],a[2]));
        if (s1-z <= sum) return 1;
        int z1 = min(a[0],min(a[1],a[2]));
        if (z1 <= sum) return 2;
        return 3;
    }
    int z = 9-min(a[0],min(a[1],a[2]));
    if (s1+z >= sum) return 1;
    int z1 = 18+max(a[2],max(a[0],a[1]));
    if (z1 >= sum) return 2;
    return 3;
}

int test2(int sum) {
    int s1 = a[3]+a[4]+a[5];
    if (s1 == sum) return 0;
    if (s1 > sum) {
        int z = max(a[3],max(a[4],a[5]));
        if (s1-z <= sum) return 1;
        int z1 = min(a[3],min(a[4],a[5]));
        if (z1 <= sum) return 2;
        return 3;
    }
    int z = 9-min(a[3],min(a[4],a[5]));
    if (s1+z >= sum) return 1;
    int z1 = 18+max(a[3],max(a[4],a[5]));
    if (z1 >= sum) return 2;
    return 3;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> s;
	F0R(i,6) a[i] = s[i]-'0';
	for (int i = 0; i <= 27; ++i) ans = min(ans,test1(i)+test2(i));
	cout << ans;
}

// read!
// ll vs. int!