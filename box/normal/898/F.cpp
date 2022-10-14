#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000009;
const int M2 = 998244853;

int pfx1[1<<20],pfx2[1<<20];
int ex1[1<<20],ex2[1<<20];

pii ga(int L,int R){
    if(L==0)return {pfx1[R],pfx2[R]};
    else return {(pfx1[R]+1ll*pfx1[L-1]*ex1[R-L+1])%MOD,(pfx2[R]+1ll*pfx2[L-1]*ex2[R-L+1])%M2};
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s; cin>>s;
    int n=s.size();
    ex1[0]=ex2[0]=1;
    rep1(i,n)ex1[i]=10ll*ex1[i-1]%MOD,ex2[i] = 10ll * ex2[i-1] % M2;
    rep(i, n+1)
        ex1[i] = MOD - ex1[i], ex2[i] = M2 - ex2[i];
    pfx1[0] = pfx2[0] = s[0] - '0';
    rep1(i, n-1) {
        pfx1[i] = (10ll * pfx1[i-1] + s[i] - '0') % MOD;
        pfx2[i] = (10ll * pfx2[i-1] + s[i] - '0') % M2;
    }
    auto che = [&](int a, int b, int c) {
        if(a + b + c != n) return 0;
        if(a > n || b > n || c > n) return 0;
        if(a <= 0 || b <= 0 || c <= 0) return 0;
        int x = 0, y = a, z = a + b;
        if(a != 1 && s[x] == '0') return 0;
        if(b != 1 && s[y] == '0') return 0;
        if(c != 1 && s[z] == '0') return 0;
        auto [a1, a2] = ga(x, x+a-1);
        auto [b1, b2] = ga(y, y+b-1);
        auto [c1, c2] = ga(z, z+c-1);
        if((a1+b1)%MOD!=c1) return 0;
        if((a2 + b2) % M2 != c2) return 0;
        iter(i, x, x+a) cout << s[i];
        cout << '+';
        iter(i, y, y+b) cout << s[i];
        cout << '=';
        iter(i, z, z+c) cout << s[i];
        cout << endl;
        return 1;
    };
    rep(s, n+1) {
        if(che(n-s-(s), s, s)) exit(0);
        if(che(n-s-(s-1), s-1, s)) exit(0);
        if(che(s, n-s-(s), s)) exit(0);
        if(che(s-1, n-s-(s-1), s)) exit(0);
    }
}