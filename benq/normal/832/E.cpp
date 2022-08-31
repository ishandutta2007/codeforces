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

int n,m,q,bad=0;
ll po5[501];
int inv[5] = {0,1,3,2,4};
bool done[500];
vi s[500], s1[500];
string b; 

void sub(int num, vi& ori, vi& res) {
    F0R(i,m) res[i] = ((res[i]-num*ori[i] % 5)+5)%5;
} // correct

void gen() {
    F0R(i,m) F0R(j,n) if (!done[j] && s[j][i]) {
        int t = inv[s[j][i]];
        FOR(k,i,m) s[j][k] = (s[j][k]*t) % 5;
        F0R(k,n) 
            if (!done[k] && k != j) 
                sub(s[k][i],s[j],s[k]);
        done[j] = 1;
        s1[i] = s[j];
        bad--;
        break;
    }
}

void init() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	po5[0] = 1;
	FOR(i,1,501) {
	    po5[i] = (5*po5[i-1]) % MOD;
	}
	cin >> n >> m;
	F0R(i,n) F0R(j,m) {
	    char c; cin >> c;
	    s[i].pb(int(c-'a'));
	}
	bad = n;
	gen();
	cin >> q;
}

bool ok(string b) {
    vi tmp(m);
    F0R(i,m) tmp[i] = (b[i]-'a');
    
    F0R(i,m) if (tmp[i]) {
        if (s1[i].size() == 0) return 0;
        sub(tmp[i],s1[i],tmp);
    }
    return 1;
}

int main() {
    init();
	F0R(i,q) {
	    cin >> b;
	    if (ok(b)) cout << po5[bad] << "\n";
	    else cout << 0 << "\n";
	}
}