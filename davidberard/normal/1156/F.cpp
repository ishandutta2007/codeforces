#include <cassert>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ll mod = 998244353;


const int NMAX = 5050;
ll dpn[NMAX], dpd[NMAX];
ll sfn[NMAX], sfd[NMAX];
int n;
int a[NMAX];
int amt[NMAX];
int pre[NMAX];

ll an = 0, ad = 1;

ll modpow(ll b, ll p) {
    ll ans = 1;
    while(p) {
        if(p&1) ans = ans*b%mod;
        b = (b*b)%mod;
        p >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    for(int i=0; i<5050; ++i) dpd[i] = 1;
    cin >> n;
    vector<int> z(n);
    for(auto& x : z) cin >> x;
    sort(z.begin(), z.end());
    int lst = 0;
    int m = 0;
    for(int i=0; i<n; ++i) {
        if(lst != z[i]) {
            a[m++] = z[i];
        }
        ++amt[m-1];
        lst = z[i];
    }
    for(int i=0; i<m-i-1; ++i) {
        swap(amt[i], amt[m-i-1]);
    }
    pre[0] = 0;
    for(int i=1; i<=m; ++i) {
        pre[i] = pre[i-1]+amt[i-1];
    }
    dpn[m] = 1;
    for(int t=0; t<n-1; ++t) {
        sfn[m] = dpn[m];
        sfd[m] = dpd[m]*pre[m]%mod;
        //cerr << "! " << sfn[m] << " " << sfd[m] << endl;
        for(int i=m-1; i>=0; --i) {
            ll dd = (n-t)*dpd[i]%mod;
            sfn[i] = (dpn[i]*sfd[i+1]+dd*sfn[i+1])%mod;
            sfd[i] = (sfd[i+1]*dd)%mod;
            //cerr << " .. sfx " << i << " = " << sfn[i] << " " << sfd[i] << endl;
        }
        //cerr << endl;
        for(int i=0; i<m; ++i) {
            dpn[i] = sfn[i+1]*amt[i]%mod;
            dpd[i] = (sfd[i+1])%mod;
            //cerr << " .. " << i << ": " << dpn[i] << " " << dpd[i] << endl;
            if(amt[i] != 1) {
                //cerr << " -> " << amt[i]-1 << " " << pre[i+1]-1 << endl;
                ll nn = dpn[i]*(amt[i]-1)%mod;
                ll dd = (dpd[i]*(n-t-1))%mod;
                an = (an*dd+nn*ad)%mod;
                ad = (dd*ad)%mod;
            }
        }
        dpn[m] = 0;
        //cerr << endl;
    }
    //cerr << " .. " << an << " " << ad << endl;
    cout << (an*modpow(ad, mod-2))%mod << endl;
    return 0;
}