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
 
pii p[800000];
bool comp(pii a,pii b) {
    return a.first+a.second < b.first+b.second;
}
multiset<int> A,B;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d",&p[i].first,&p[i].second);
    sort(p,p+n,comp);
 
    int c = 0,add = 0;
    LLI ans = 0;
    for (i = 0; i < n; i++) {
        if (i == 0) A.insert(p[i].first),B.insert(p[i].first);
        else {
            add += p[i].first+p[i].second-c;
            if (p[i].first <= *A.rbegin()) {
                ans += *A.rbegin()-p[i].first;
                A.insert(p[i].first),A.insert(p[i].first);
            }
            else if (p[i].first >= *B.begin()+add) {
                ans += p[i].first-(*B.begin()+add);
                B.insert(p[i].first-add),B.insert(p[i].first-add);
            }
            else A.insert(p[i].first),B.insert(p[i].first-add);
            if (A.size() > B.size()) {
                B.insert(*A.rbegin()-add);
                A.erase(--A.end());
            }
            else if (A.size() < B.size()) {
                A.insert(*B.begin()+add);
                B.erase(B.begin());
            }
        }
        c = p[i].first+p[i].second;
    }
    printf("%I64d\n",ans);
 
    return 0;
}