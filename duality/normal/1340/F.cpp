#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------
#define S 200003
#define MOD 1000000007

int n,B;
int s[100000];
LLI inv(LLI n) {
    LLI r = 1;
    int e = MOD-2;
    while (e > 0) {
        if (e & 1) r = (r*n) % MOD;
        e >>= 1;
        n = (n*n) % MOD;
    }
    return r;
}
LLI power[100001],invpower[100001];
vi x[400];
vi h[400],hr[400];
int neg[400];
int build(int b) {
    int i;
    int e = min((b+1)*B,n);
    x[b].clear(),neg[b] = 0;
    for (i = b*B; i < e; i++) {
        if (s[i] < 0) {
            if (!x[b].empty() && (x[b].back() > 0)) {
                if (x[b].back() != -s[i]) {
                    neg[b] = 1e9;
                    break;
                }
                else x[b].pop_back();
            }
            else x[b].pb(s[i]),neg[b]++;
        }
        else x[b].pb(s[i]);
    }
    if (neg[b] != 1e9) {
        h[b].resize(x[b].size()+1),hr[b].resize(x[b].size()+1);
        h[b][0] = hr[b][x[b].size()] = 0;
        for (i = 0; i < x[b].size(); i++) h[b][i+1] = (h[b][i]+power[i]*x[b][i]) % MOD;
        for (i = (int) x[b].size()-1; i >= 0; i--) hr[b][i] = (hr[b][i+1]+power[x[b].size()-i-1]*x[b][i]) % MOD;
    }
    return 0;
}
int getHash(int b,int l,int r,int t) {
    if (t == 0) return ((h[b][r+1]-h[b][l])*invpower[l]) % MOD;
    else return ((hr[b][l]-hr[b][r+1])*invpower[x[b].size()-r-1]) % MOD;
}
struct sub { int b,l,r; };
vector<sub> v;
int main() {
    int i,j;
    int k,q;
    int t,p,l,r;
    scanf("%d %d",&n,&k),B = sqrt(n);
    power[0] = invpower[0] = 1;
    for (i = 1; i <= n; i++) power[i] = (S*power[i-1]) % MOD;
    invpower[1] = inv(S);
    for (i = 2; i <= n; i++) invpower[i] = (invpower[1]*invpower[i-1]) % MOD;
    for (i = 0; i < n; i++) scanf("%d",&s[i]);
    for (i = 0; i <= (n-1)/B; i++) build(i);
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d",&p,&t),p--;
            s[p] = t,build(p/B);
        }
        else {
            scanf("%d %d",&l,&r);
            l--,r--;

            v.clear();
            if (l/B == r/B) {
                for (j = l; j <= r; j++) {
                    if (s[j] > 0) v.pb((sub){-1,j,j});
                    else {
                        if (!v.empty() && (s[v.back().r] == -s[j])) v.pop_back();
                        else break;
                    }
                }
                printf(((j > r) && v.empty()) ? "Yes\n":"No\n");
            }
            else {
                int bad = 0;
                for (j = l/B+1; j < r/B; j++) {
                    if (neg[j] == 1e9) {
                        bad = 1;
                        break;
                    }
                }
                if (bad) {
                    printf("No\n");
                    continue;
                }
                for (j = l; j < (l/B+1)*B; j++) {
                    if (s[j] > 0) v.pb((sub){-1,j,j});
                    else {
                        if (!v.empty() && (s[v.back().r] == -s[j])) v.pop_back();
                        else {
                            bad = 1;
                            break;
                        }
                    }
                }
                if (bad) {
                    printf("No\n");
                    continue;
                }
                for (j = l/B+1; j < r/B; j++) {
                    int ll = 0,rr = neg[j]-1;
                    while (ll <= rr) {
                        if (v.empty()) {
                            bad = 1;
                            break;
                        }
                        else if (v.back().b == -1) {
                            if (s[v.back().r] != -x[j][ll]) {
                                bad = 1;
                                break;
                            }
                            else v.pop_back(),ll++;
                        }
                        else {
                            int s = min(rr-ll+1,v.back().r-v.back().l+1);
                            int hh = getHash(v.back().b,v.back().r-s+1,v.back().r,1)+getHash(j,ll,ll+s-1,0);
                            if ((hh % MOD) != 0) {
                                bad = 1;
                                break;
                            }
                            else {
                                ll += s,v.back().r -= s;
                                if (v.back().l > v.back().r) v.pop_back();
                            }
                        }
                    }
                    if (bad) break;
                    if (neg[j] <= (int) x[j].size()-1) v.pb((sub){j,neg[j],(int) x[j].size()-1});
                }
                if (bad) {
                    printf("No\n");
                    continue;
                }
                for (j = (r/B)*B; j <= r; j++) {
                    if (s[j] > 0) v.pb((sub){-1,j,j});
                    else {
                        if (v.empty()) {
                            bad = 1;
                            break;
                        }
                        else if (v.back().b == -1) {
                            if (s[v.back().r] != -s[j]) {
                                bad = 1;
                                break;
                            }
                            else v.pop_back();
                        }
                        else {
                            if (x[v.back().b][v.back().r] != -s[j]) {
                                bad = 1;
                                break;
                            }
                            v.back().r--;
                            if (v.back().l > v.back().r) v.pop_back();
                        }
                    }
                }
                printf((!bad && v.empty()) ? "Yes\n":"No\n");
            }
        }
    }

    return 0;
}