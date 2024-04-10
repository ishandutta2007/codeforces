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

template<int SZ> struct Sieve {
    int num[SZ+1], sq[SZ+1], lst[SZ+1];
    Sieve() {
        F0R(i,SZ+1) num[i] = lst[i] = sq[i] = 0;
        for (int i = 2; i <= SZ; ++i) if (!num[i]) 
            for (int j = i; j <= SZ; j += i) {
                num[j] ++;
                int j1 = j/i;
                if (!lst[j]) lst[j] = i;
                while (j1 % i == 0) j1 /= i, sq[j] = 1, num[j] ++;
            }
    }
};

Sieve<10000000> S;
ll co[4], cum[10000001];
ll n,z;

void gen0() {
	// distance 0: one is a prime > n/2, or 1
	FOR(i,1,n+1) if (i == 1 || (2*i > n && S.num[i] == 1)) z++;
	co[0] = n*(n-1)/2-(n-z)*(n-z-1)/2;
}

int mob(int x) {
    if (S.sq[x]) return 0;
    if (S.num[x] % 2 == 0) return 1;
    return -1;
}

void gen1() { // gcd > 1
    FOR(i,1,n+1) co[1] += mob(i)*(n/i)*(n/i);
    co[1] = n*n-co[1]-(n-1);
    co[1] /= 2;
}

ll get(int lo, int hi) {
    if (lo > hi) return 0;
    return cum[hi]-cum[lo-1];
}

void gen2() { // gcd = 1, lowest primes multiplied <= n
    FOR(i,2,n+1) {
        cum[S.lst[i]] ++;
    }
    FOR(i,1,n+1) cum[i] += cum[i-1];
    
    for (int i = 2; i*i <= n; ++i) if (S.num[i] == 1) {
        co[2] += get(i,i)*get(i+1,n/i);
        co[2] += get(i,i)*(get(i,i)-1)/2;
    }
    co[2] -= co[1];
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    
    gen0();
    gen1();
    gen2();
    
    co[3] = n*(n-1)/2-co[0]-co[1]-co[2];
    cout << co[1]+2*co[2]+3*co[3];
}

// read!
// ll vs. int!