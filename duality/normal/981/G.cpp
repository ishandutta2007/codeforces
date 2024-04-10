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

int lazym[1 << 19],lazya[1 << 19],tree[1 << 19];
pii inter(pii a,pii b) {
    return mp(max(a.first,b.first),min(a.second,b.second));
}
int prop(int s,int e,int i) {
    if (s != e) {
        lazym[2*i+1] = ((LLI) lazym[2*i+1]*lazym[i]) % MOD;
        lazya[2*i+1] = ((LLI) lazya[2*i+1]*lazym[i]+lazya[i]) % MOD;
        lazym[2*i+2] = ((LLI) lazym[2*i+2]*lazym[i]) % MOD;
        lazya[2*i+2] = ((LLI) lazya[2*i+2]*lazym[i]+lazya[i]) % MOD;
    }
    tree[i] = ((LLI) lazym[i]*tree[i]+(LLI) lazya[i]*(e-s+1)) % MOD;
    lazym[i] = 1,lazya[i] = 0;
    return 0;
}
int update(int s,int e,int as,int ae,int i,int m,int a) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return tree[i];
    else if ((s >= as) && (e <= ae)) {
        lazym[i] = m,lazya[i] = a;
        prop(s,e,i);
        return tree[i];
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,m,a);
    update(mid+1,e,as,ae,2*i+2,m,a);
    tree[i] = (tree[2*i+1] + tree[2*i+2]) % MOD;
    return tree[i];
}
int query(int s,int e,int qs,int qe,int i) {
    prop(s,e,i);
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return (query(s,mid,qs,qe,2*i+1) + query(mid+1,e,qs,qe,2*i+2)) % MOD;
}
set<pii> S[200000];
set<int> Sslow[200000];
int size[200000];
int main() {
    int i,j;
    int n,q;
    int t,l,r,x;
    scanf("%d %d",&n,&q);
    fill(lazym,lazym+(1 << 19),1);
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d %d",&l,&r,&x);
            l--,r--,x--;
            vpii v;
            auto it = S[x].upper_bound(mp(l,n));
            if (it != S[x].begin()) it--;
            while ((it != S[x].end()) && (it->first <= r)) {
                pii ii = inter(*it,mp(l,r));
                if (ii.first <= ii.second) v.pb(ii);
                it++;
            }
            for (j = 0; j < v.size(); j++) {
                update(0,n-1,v[j].first,v[j].second,0,2,0);
                if (v[j].first > l) update(0,n-1,(j == 0) ? l:v[j-1].second+1,v[j].first-1,0,1,1);
            }
            if ((j == 0) || (v[j-1].second < r)) update(0,n-1,(j == 0) ? l:v[j-1].second+1,r,0,1,1);
            it = S[x].upper_bound(mp(l,n));
            if (it != S[x].begin()) it--;
            if ((it != S[x].end()) && (it->second < l-1)) it++;
            else if (it != S[x].end()) l = min(l,it->first);
            while ((it != S[x].end()) && (it->first <= r)) {
                r = max(r,it->second);
                it = S[x].erase(it);
            }
            S[x].insert(mp(l,r));
        }
        else if (t == 2) {
            scanf("%d %d",&l,&r);
            l--,r--;
            printf("%d\n",query(0,n-1,l,r,0));
        }
    }

    return 0;
}