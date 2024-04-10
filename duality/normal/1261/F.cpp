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
#define MOD 998244353

vplli A,B,ans;
vector<pair<LLI,int> > a,b;
vplli com(vplli v) {
    int i;
    vplli vv;
    sort(v.begin(),v.end());
    LLI p = v[0].first,q = v[0].second;
    for (i = 1; i < v.size(); i++) {
        if (v[i].first > q+1) vv.pb(mp(p,q)),p = v[i].first,q = v[i].second;
        else q = max(q,v[i].second);
    }
    vv.pb(mp(p,q));
    return vv;
}
bool comp(pair<LLI,int> a,pair<LLI,int> b) {
    return a.second > b.second;
}
set<plli> S;
int insert(LLI x,LLI y) {
    auto it = S.upper_bound(mp(x,2e18));
    if (it != S.begin()) {
        it--;
        if (it->second >= y) return 0;
        if ((it->second >= x) && (it->first < x)) {
            plli p = *it;
            S.erase(it);
            if (x-1 >= p.first) S.insert(mp(p.first,x-1));
        }
    }
    it = S.upper_bound(mp(y,2e18));
    if (it != S.begin()) {
        it--;
        if ((it->second > y) && (it->first <= x)) {
            plli p = *it;
            S.erase(it),S.insert(mp(y+1,p.second));
        }
    }
    it = S.lower_bound(mp(x,0));
    while ((it != S.end()) && (it->second <= y)) it = S.erase(it);
    S.insert(mp(x,y));
    return 0;
}
int main() {
    int i;
    int n;
    LLI l,r;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%I64d %I64d",&l,&r),A.pb(mp(l,r));
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%I64d %I64d",&l,&r),B.pb(mp(l,r));
    A = com(A),B = com(B);

    int j;
    for (i = 0; i < A.size(); i++) {
        for (j = 60; j >= 0; j--) {
            if ((A[i].first^A[i].second) & (1LL << j)) break;
        }
        int p = j;
        for (j = p-1; j >= 0; j--) {
            if (A[i].second & (1LL << j)) a.pb(mp(A[i].second & (~((1LL << (j+1))-1)),j));
        }
        a.pb(mp(A[i].second,0));
        for (j = p-1; j >= 0; j--) {
            if (!(A[i].first & (1LL << j))) a.pb(mp((A[i].first^(1LL << j)) & (~((1LL << j)-1)),j));
        }
        a.pb(mp(A[i].first,0));
    }
    swap(a,b),swap(A,B);
    for (i = 0; i < A.size(); i++) {
        for (j = 60; j >= 0; j--) {
            if ((A[i].first^A[i].second) & (1LL << j)) break;
        }
        int p = j;
        for (j = p-1; j >= 0; j--) {
            if (A[i].second & (1LL << j)) a.pb(mp(A[i].second & (~((1LL << (j+1))-1)),j));
        }
        a.pb(mp(A[i].second,0));
        for (j = p-1; j >= 0; j--) {
            if (!(A[i].first & (1LL << j))) a.pb(mp((A[i].first^(1LL << j)) & (~((1LL << j)-1)),j));
        }
        a.pb(mp(A[i].first,0));
    }
    sort(a.begin(),a.end(),comp);
    sort(b.begin(),b.end(),comp);
    for (i = 0; i < a.size(); i++) {
        for (j = 0; j < B.size(); j++) {
            int m = a[i].second;
            LLI x = (a[i].first^B[j].first) & (~((1LL << m)-1));
            LLI y = x+(1LL << m)-1;
            insert(x,y);
            x = (a[i].first^B[j].second) & (~((1LL << m)-1));
            y = x+(1LL << m)-1;
            insert(x,y);
            if ((B[j].first >> m) != (B[j].second >> m)) {
                if (!(B[j].first & (1LL << m))) {
                    x = (a[i].first^B[j].first^(1LL << m)) & (~((1LL << m)-1));
                    y = x+(1LL << m)-1;
                    insert(x,y);
                }
                if (B[j].second & (1LL << m)) {
                    x = (a[i].first^B[j].second^(1LL << m)) & (~((1LL << m)-1));
                    y = x+(1LL << m)-1;
                    insert(x,y);
                }
            }
        }
    }
    for (i = 0; i < A.size(); i++) {
        for (j = 0; j < b.size(); j++) {
            int m = b[j].second;
            LLI x = (A[i].first^b[j].first) & (~((1LL << m)-1));
            LLI y = x+(1LL << m)-1;
            insert(x,y);
            x = (A[i].second^b[j].first) & (~((1LL << m)-1));
            y = x+(1LL << m)-1;
            insert(x,y);
            if ((A[i].first >> m) != (A[i].second >> m)) {
                if (!(A[i].first & (1LL << m))) {
                    x = (A[i].first^b[j].first^(1LL << m)) & (~((1LL << m)-1));
                    y = x+(1LL << m)-1;
                    insert(x,y);
                }
                if (A[i].second & (1LL << m)) {
                    x = (A[i].second^b[j].first^(1LL << m)) & (~((1LL << m)-1));
                    y = x+(1LL << m)-1;
                    insert(x,y);
                }
            }
        }
    }/*
    for (i = 0; i < a.size(); i++) {
        for (j = 0; j < b.size(); j++) {
            int m = max(a[i].second,b[j].second);
            LLI x = (a[i].first^b[j].first) & (~((1LL << m)-1));
            LLI y = x+(1LL << m)-1;
            insert(x,y);
        }
    }*/
    for (auto it = S.begin(); it != S.end(); it++) ans.pb(*it);
    LLI sum = 0;
    for (i = 0; i < ans.size(); i++) {
        if ((ans[i].second-ans[i].first+1) & 1) {
            LLI m = (ans[i].second+ans[i].first)/2;
            sum += (m % MOD)*((ans[i].second-ans[i].first+1) % MOD),sum %= MOD;
        }
        else {
            LLI m = (ans[i].second-ans[i].first+1)/2;
            sum += (m % MOD)*((ans[i].second+ans[i].first) % MOD),sum %= MOD;
        }
    }
    printf("%I64d\n",sum);

    return 0;
}