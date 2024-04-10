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

int s[5000],occ[5000],occ2[5000];
vi poss[5000];
int main() {
    int i;
    int n,m,f,h;
    scanf("%d %d",&n,&m);
    for (i = 0; i < n; i++) scanf("%d",&s[i]),occ[--s[i]]++;
    for (i = 0; i < m; i++) scanf("%d %d",&f,&h),poss[f-1].pb(h);
    for (i = 0; i < n; i++) sort(poss[i].begin(),poss[i].end());

    int j,k;
    int ans = 0;
    LLI ways = 0;
    for (i = 0; i <= n; i++) {
        LLI w = 1;
        int a = 0;
        for (j = 0; j < n; j++) {
            int x = occ2[j],y = occ[j]-occ2[j];
            if (x > y) swap(x,y);
            int possa = 0;
            if (poss[j].empty()) possa = 0;
            if ((poss[j].size() >= 1) && (poss[j][0] <= y)) possa = 1;
            if ((poss[j].size() >= 2) && (poss[j][0] <= x) && (poss[j][1] <= y)) possa = 2;
            if ((i > 0) && (j == s[i-1])) {
                if (possa == 0) break;
                else if (possa == 1) {
                    for (k = 0; k < poss[j].size(); k++) {
                        if (poss[j][k] == occ2[j]) break;
                    }
                    if (k == poss[j].size()) break;
                    else a++;
                }
                else {
                    for (k = 0; k < poss[j].size(); k++) {
                        if (poss[j][k] == occ2[j]) break;
                    }
                    if (k == poss[j].size()) break;
                    int p = k,c = 0;
                    for (k = 0; k < poss[j].size(); k++) {
                        if ((k != p) && (poss[j][k] <= occ[j]-occ2[j])) c++;
                    }
                    a += 2,w *= c,w %= MOD;
                }
            }
            else {
                if (possa == 0) continue;
                else if (possa == 1) {
                    int c = 0;
                    for (k = 0; k < poss[j].size(); k++) {
                        if (poss[j][k] <= x) c++;
                        if (poss[j][k] <= y) c++;
                    }
                    a++,w *= c,w %= MOD;
                }
                else {
                    int cx = 0,cy = 0;
                    for (k = 0; k < poss[j].size(); k++) {
                        if (poss[j][k] <= x) cx++;
                        if (poss[j][k] <= y) cy++;
                    }
                    int cc = cx*(cy-cx)+cx*(cx-1);
                    a += 2,w *= cc,w %= MOD;
                }
            }
        }
        if (j == n) {
            //cout<<i<<":"<<a<<","<<w<<endl;
            if (a > ans) ans = a,ways = w;
            else if (a == ans) ways += w,ways %= MOD;
        }
        if (i < n) occ2[s[i]]++;
    }/*

    int j,k;
    int ans = 0;
    LLI ways = 1;
    for (i = 0; i < n; i++) {
        sort(poss[i].begin(),poss[i].end());
        if (poss[i].empty()) continue;
        else if (poss[i].size() == 1) {
            if (poss[i][0] <= occ[i]) ans++,ways *= 2,ways %= MOD;
        }
        else {
            if (poss[i][0]+poss[i][1] <= occ[i]) {
                int c = 0;
                ans += 2;
                for (j = 0; j < poss[i].size(); j++) {
                    for (k = 0; k < j; k++) {
                        if (poss[i][j]+poss[i][k] <= occ[i]) c++;
                    }
                }
                ways *= 2*c,ways %= MOD;
            }
            else if (poss[i][0] <= occ[i]) {
                int c = 0;
                ans++;
                for (j = 0; j < poss[i].size(); j++) {
                    if (poss[i][j] <= occ[i]) c++;
                }
                ways *= 2*c,ways %= MOD;
            }
        }
    }*/
    if (ans == 0) ways = 1;
    printf("%d %I64d\n",ans,ways);

    return 0;
}