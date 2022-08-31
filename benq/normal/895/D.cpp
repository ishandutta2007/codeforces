#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <assert.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SQ(a) (a)*(a)
#define PMOD(a, b) (((a) > 0) ? ((a)%(b)) : ((((a)+(b)*((-(a)/(b))+1))%(b))))
#define UMOD(a, b) (a) = (((a) > 0) ? ((a)%(b)) : ((((a)+(b)*((-(a)/(b))+1))%(b))))

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

const int MAX_N = 1000005;
const ll MOD = 1000000007;
ll fact[MAX_N];
ll factinv[MAX_N];
ll inv[MAX_N];
string a1, b1;
string a;

ll exp(ll x, ll pow) {
    ll prod = 1;
    while(pow > 0){
        if(pow%2 == 1) prod = (prod*x)%MOD;
        x = (x*x)%MOD; pow /= 2;
    }
    return prod;
}

ll inverse(ll a) {
    return exp(a, MOD-2);
}

ll calc(string k) {
    int cnt[26];
    M00(i, 26) cnt[i] = 0;
    M00(i, a.length()) cnt[a[i] - 'a']++;
    ll res = 0;
    M00(i, k.length()) {
        ll tot = fact[k.length()-i-1];
        M00(j, 26) if(cnt[j]) {
            tot *= factinv[cnt[j]];
            UMOD(tot, MOD);
        }
        M00(j, k[i] - 'a') if(cnt[j]) {
            ll delta = tot * cnt[j];
            res += delta;
            UMOD(res, MOD);
        }
        cnt[k[i]-'a']--;
        if(cnt[k[i]-'a'] < 0) return res;
    }
    return res;
}

int main() { FAST
    fact[0] = 1;
    factinv[0] = inverse(fact[0]);
    MOO(i, 1, MAX_N) {
        inv[i] = inverse(i);
        fact[i] = fact[i-1]*i;
        factinv[i] = factinv[i-1] * inv[i];
        UMOD(fact[i], MOD);
        UMOD(factinv[i], MOD);
    }
    cin >> a1 >> b1;
    int cnt[26];
    M00(i, 26) cnt[i] = 0;
    M00(i, a1.length()) cnt[a1[i] - 'a']++;
    //string alph = "abcdefghijklmnopqrstuvwxyz";
    M00(i, 26) {
        M00(j, cnt[i]) a += 'a' + i;
    }
    cout << PMOD(calc(b1) - calc(a1) - 1, MOD) << "\n";
}