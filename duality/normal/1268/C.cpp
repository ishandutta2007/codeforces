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

int p[300000],inv[300000];
int bit[300001];
int tree[1 << 20],lazy[1 << 20];
int tree2[1 << 20],lazy2[1 << 20];
set<int> S;
int query(int l,int r) {
    if (l > r) return 0;
    int i,sum = 0;
    for (i = r+1; i > 0; i -= i & (-i)) sum += bit[i];
    for (i = l; i > 0; i -= i & (-i)) sum -= bit[i];
    return sum;
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&p[i]),inv[--p[i]] = i;

    int j;
    LLI ans = 0;
    auto it = S.begin();
    int l = 0,r = 0;
    for (i = 0; i < n; i++) {
        int sum = i;
        for (j = inv[i]+1; j > 0; j -= j & (-j)) sum -= bit[j];
        ans += sum;
        //cout<<ans<<endl;
        if (S.empty()) S.insert(inv[i]),it = S.begin();
        else {
            if (S.size() & 1) {
                if (inv[i] < *it) {
                    ans -= query(0,inv[i]);
                    debug "here1";
                    debug ans;
                    ans += (*it-inv[i]-1)-query(inv[i]+1,*it-1);
                    debug ans;
                }
                else {
                    debug "here2";
                    ans -= query(inv[i],n-1);
                    debug ans;
                    ans += (inv[i]-*it-1)-query(*it+1,inv[i]-1);
                    debug ans;
                }
            }
            else {
                if (inv[i] < *it) {
                    debug "here3";
                    ans -= query(0,inv[i]);
                    debug ans;
                    ans += (*it-inv[i]-1)-query(inv[i]+1,*it-1);
                    debug ans;
                }
                else {
                    debug "here4";
                    ans -= query(inv[i],n-1);
                    debug ans;
                    auto it2 = it;
                    it2++;
                    if (inv[i] > *it2) {
                        ans += (inv[i]-*it2-1)-query(*it2+1,inv[i]-1);
                        debug ans;
                    }
                }
            }
            if (inv[i] < *it) l++;
            else r++;
            S.insert(inv[i]);
            if (l > r) it--,l--,r++;
            else if (r >= l+2) it++,l++,r--;
        }
        for (j = inv[i]+1; j <= n; j += j & (-j)) bit[j]++;
        printf("%I64d ",ans);
    }
    printf("\n");

    return 0;
}