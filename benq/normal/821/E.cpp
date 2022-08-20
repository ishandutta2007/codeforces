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

ll cur[16];

struct mat {
    ll dat[16][16];  
    mat() {
        F0R(i,16) F0R(j,16) dat[i][j] = 0;
    }
};

mat operator+ (mat a, mat b) {
    mat c;
    F0R(i,16) F0R(j,16) F0R(k,16) 
        c.dat[i][k] = (c.dat[i][k]+a.dat[i][j]*b.dat[j][k]) % MOD;
    return c;
}

mat po(mat x, ll power) {
    mat ans; F0R(i,16) ans.dat[i][i] = 1;
    while (power) {
        if (power & 1) ans = (ans+x);
        x = (x+x);
        power /= 2;
    }
    return ans;
}

mat init(int sz) {
    mat x;
    F0R(i,sz+1) {
        if (i) x.dat[i-1][i] = 1;
        x.dat[i][i] = 1;
        if (i+1 <= sz) x.dat[i+1][i] = 1;
    }
    return x;
}

int main() {
    ll n,k; cin >> n >> k;
    cur[0] = 1;
    F0R(i,n) {
        ll a,b,c; cin >> a >> b >> c;
        F0R(j,16) if (j > c) cur[j] = 0;
        mat z = po(init(c),min(b,k)-a);
        ll cur1[16]; F0R(j,16) cur1[j] = 0;
        F0R(j,16) F0R(k,16) 
            cur1[k] = (cur1[k]+cur[j]*z.dat[j][k]) % MOD;
        
        F0R(i,16) cur[i] = cur1[i];
    }
    cout << cur[0];
}