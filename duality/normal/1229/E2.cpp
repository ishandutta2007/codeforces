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
#define MOD 1000000007

int inv(int n) {
    int e = MOD-2,r = 1;
    while (e > 0) {
        if (e & 1) r = ((LLI) r*n) % MOD;
        e >>= 1;
        n = ((LLI) n*n) % MOD;
    }
    return r;
}
int P[7][7];
int a[128],b[8][128],c[8];
vpii v[7],v2[3];
unordered_map<LLI,int> m3,m4;
vector<pair<LLI,int> > v3,v4;
int main() {
    int i,j;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) scanf("%d",&P[i][j]);
    }
    for (i = n; i < 7; i++) P[i][i] = 100;

    int k,l,m;
    int inv100 = inv(100);
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 128; j++) {
            LLI p = 1;
            for (k = 0; k < 7; k++) {
                if (j & (1 << k)) p *= ((LLI) P[k][i]*inv100) % MOD,p %= MOD;
                else p *= ((LLI) (100-P[k][i])*inv100) % MOD,p %= MOD;
            }
            v[i].pb(mp(j,p));
        }
    }
    for (i = 0; i < 128; i++) {
        int x = 0;
        for (j = 0; j < 7; j++) {
            if (i & (1 << j)) x++;
        }
        a[i] = c[x]++,b[x][a[i]] = i;
    }
    for (i = 0; i < 6; i += 2) {
        vpii temp;
        for (j = 0; j < v[i].size(); j++) {
            for (k = 0; k < v[i+1].size(); k++) {
                int poss = 0;
                for (l = 0; l < 7; l++) {
                    for (m = 0; m < 7; m++) {
                        if (l != m) {
                            if ((v[i][j].first & (1 << l)) && (v[i+1][k].first & (1 << m))) poss |= (1 << a[(1 << l) | (1 << m)]);
                        }
                    }
                }
                temp.pb(mp(poss,((LLI) v[i][j].second*v[i+1][k].second) % MOD));
            }
        }
        sort(temp.begin(),temp.end());
        for (j = 0; j < temp.size(); j++) {
            if (v2[i/2].empty() || (temp[j].first != v2[i/2].back().first)) v2[i/2].pb(temp[j]);
            else v2[i/2].back().second += temp[j].second,v2[i/2].back().second %= MOD;
        }
    }
    for (i = 0; i < v2[0].size(); i++) {
        for (j = 0; j < v2[1].size(); j++) {
            LLI poss = 0;
            for (k = 0; k < 21; k++) {
                if (!(v2[0][i].first & (1 << k))) continue;
                for (l = 0; l < 21; l++) {
                    if ((b[2][k] & b[2][l]) == 0) {
                        if (v2[1][j].first & (1 << l)) poss |= (1LL << a[b[2][k] | b[2][l]]);
                    }
                }
            }
            m3[poss] += ((LLI) v2[0][i].second*v2[1][j].second) % MOD;
            if (m3[poss] >= MOD) m3[poss] -= MOD;
        }
    }
    for (i = 0; i < v2[2].size(); i++) {
        for (j = 0; j < v[6].size(); j++) {
            LLI poss = 0;
            for (k = 0; k < 21; k++) {
                for (l = 0; l < 7; l++) {
                    if ((b[2][k] & b[1][l]) == 0) {
                        if ((v2[2][i].first & (1 << k)) && (v[6][j].first & (1 << l))) poss |= (1LL << a[b[2][k] | b[1][l]]);
                    }
                }
            }
            m4[poss] += ((LLI) v2[2][i].second*v[6][j].second) % MOD;
            if (m4[poss] >= MOD) m4[poss] -= MOD;
        }
    }
    for (auto it = m3.begin(); it != m3.end(); it++) v3.pb(*it);
    for (auto it = m4.begin(); it != m4.end(); it++) v4.pb(*it);
    int ans = 0;
    for (i = 0; i < v3.size(); i++) {
        LLI r = 0;
        for (j = 0; j < 35; j++) {
            if (v3[i].first & (1LL << j)) r |= (1LL << (34-j));
        }
        int sum = 0;
        for (j = 0; j < v4.size(); j++) {
            if ((r & v4[j].first) > 0) {
                sum += v4[j].second;
                if (sum >= MOD) sum -= MOD;
            }
        }
        ans += ((LLI) v3[i].second*sum) % MOD,ans %= MOD;
    }
    printf("%d\n",ans);

    return 0;
}