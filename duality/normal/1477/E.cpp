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

int a[200000],b[200000];
struct data {
    LLI bit[1000005],bit2[1000005];
    multiset<int> S;
    int insert(int x) {
        int i;
        S.insert(x);
        for (i = x+1; i < 1000005; i += i & (-i)) bit[i]++,bit2[i] += x;
        return 0;
    }
    int erase(int x) {
        int i;
        S.erase(S.find(x));
        for (i = x+1; i < 1000005; i += i & (-i)) bit[i]--,bit2[i] -= x;
        return 0;
    }
    LLI query(int c) {
        int i;
        LLI s = 0,s2 = 0;
        for (i = 1000004; i > 0; i -= i & (-i)) s2 += bit2[i],s += bit[i];
        for (i = min(-c,1000004); i > 0; i -= i & (-i)) s2 -= bit2[i],s -= bit[i];
        return s2+c*s;
    }
};
data A,B;
int main() {
    int i;
    int n,m,q;
    int t,p,x;
    scanf("%d %d %d",&n,&m,&q);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),B.insert(a[i]);
    for (i = 0; i < m; i++) scanf("%d",&b[i]),A.insert(b[i]);
    while (q--) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d",&p,&x),p--;
            B.erase(a[p]);
            a[p] = x;
            B.insert(a[p]);
        }
        else if (t == 2) {
            scanf("%d %d",&p,&x),p--;
            A.erase(b[p]);
            b[p] = x;
            A.insert(b[p]);
        }
        else {
            scanf("%d",&x);

            LLI ans = -1e18;
            vpii cand;
            cand.pb(mp(*A.S.begin(),0));
            cand.pb(mp(*A.S.rbegin(),0));
            cand.pb(mp(*B.S.begin(),1));
            cand.pb(mp(*B.S.rbegin(),1));
            if (m > 1) {
                auto it = ++A.S.rbegin();
                auto it2 = B.S.lower_bound(*it+x);
                if (it2 != B.S.end()) cand.pb(mp(*it2,1));
                if (it2 != B.S.begin()) cand.pb(mp(*(--it2),1));
            }
            for (i = 0; i < cand.size(); i++) {
                LLI s = 0;
                if (cand[i].second == 0) {
                    A.erase(cand[i].first);
                    s = -A.query(x-cand[i].first)-x;
                    int y,l;
                    if (A.S.empty()) y = x,l = cand[i].first;
                    else y = max(*A.S.begin()+x-cand[i].first,0),l = *A.S.begin();
                    y = max(y+*B.S.begin()-l,0);
                    s += B.query(y-*B.S.begin());
                    A.insert(cand[i].first);
                }
                else {
                    B.erase(cand[i].first);
                    s = -A.query(x-cand[i].first),s += x;
                    int y,l;
                    if (A.S.empty()) y = x,l = cand[i].first;
                    else y = max(*A.S.begin()+x-cand[i].first,0),l = *A.S.begin();
                    if (!B.S.empty()) {
                        y = max(y+*B.S.begin()-l,0);
                        s += B.query(y-*B.S.begin());
                    }
                    B.insert(cand[i].first);
                }
                ans = max(ans,s);
            }
            printf("%lld\n",ans);
        }
    }

    return 0;
}