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

int o = 0, z = 0;
int trie[10000000][2]; // easily changed to character
int num[10000000];
int n,m;
set<int> uni;

void ins(int x) {
    int cur = 0; num[cur] ++;
    F0Rd(i,19) {
        int t = (x&(1<<i))>>i;
        if (!trie[cur][t]) trie[cur][t] = ++o;
        cur = trie[cur][t];
        num[cur] ++;
    }
}

int test(int x) {
    int cur = 0, ans = 0;
    
    F0Rd(i,19) {
        int t = (x&(1<<i))>>i;
        if (!trie[cur][t]) return ans;
        if (num[trie[cur][t]] == 1<<i) t ^= 1, ans ^= (1<<i);
        if (!trie[cur][t]) return ans;
        cur = trie[cur][t];
    }
    
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,n) {
	    int a; cin >> a;
	    if (uni.find(a) != uni.end()) continue;
	    uni.insert(a);
	    ins(a);
	}
	F0R(i,m) {
	    int x; cin >> x;
	    z ^= x;
	    cout << test(z) << "\n";
	}
}
// read!
// ll vs. int!