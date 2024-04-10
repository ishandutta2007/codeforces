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

array<int,5> P[200000];
array<int,5> perm[120],a;
int com[120][120];
int MM[3125];
class comp {
    public:
        bool operator()(bitset<120> a,bitset<120> b) const {
            int i;
            for (i = 0; i < 120; i++) {
                if (a[i] != b[i]) return b[i];
            }
            return 0;
        }
};
map<bitset<120>,bitset<120>,comp> M2;
int hh(array<int,5> a) {
    int i,x = 0;
    for (i = 0; i < 5; i++) x *= 5,x += a[i];
    return x;
}
array<int,5> pcom(array<int,5> a,array<int,5> b) {
    int i;
    array<int,5> c;
    for (i = 0; i < 5; i++) c[i] = b[a[i]];
    return c;
}
bitset<120> close(array<int,5> a) {
    int aa = MM[hh(a)],c = 0;
    bitset<120> poss;
    while (!poss[c]) poss[c] = 1,c = com[c][aa];
    return poss;
}
bitset<120> ccom(bitset<120> a,bitset<120> b) {
    a |= b;
    if (M2.count(a)) return M2[a];
    bitset<120> t = a;
    int i,j,f = 1;
    while (f) {
        f = 0;
        for (i = 0; i < 120; i++) {
            if (!a[i]) continue;
            for (j = 0; j <= i; j++) {
                if (a[j] && !a[com[i][j]]) a[com[i][j]] = 1,f = 1;
            }
        }
    }
    M2[t] = a;
    return a;
}
bitset<120> bs[200000];
vector<pair<bitset<120>,int> > vv,vv2;
bool comp2(pair<bitset<120>,int> a,pair<bitset<120>,int> b) {
    int i;
    for (i = 0; i < 120; i++) {
        if (a.first[i] != b.first[i]) return b.first[i];
    }
    return 0;
}
int main() {
    int i,j;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) scanf("%d",&P[i][j]),P[i][j]--;
        for (j = k; j < 5; j++) P[i][j] = j;
    }

    int c = 0;
    for (i = 0; i < 5; i++) a[i] = i;
    do {
        int x = 0;
        for (i = 0; i < 5; i++) perm[c][i] = a[i],x *= 5,x += a[i];
        MM[x] = c;
        c++;
    } while (next_permutation(a.begin(),a.end()));
    for (i = 0; i < 120; i++) {
        for (j = 0; j < 120; j++) com[i][j] = MM[hh(pcom(perm[i],perm[j]))];
    }
    for (i = 0; i < n; i++) bs[i] = close(P[i]);

    LLI ans = 0;
    for (i = 0; i < n; i++) {
        vv.pb(mp(bs[i],1));
        for (j = 0; j < vv.size(); j++) vv[j].first = ccom(vv[j].first,bs[i]);
        sort(vv.begin(),vv.end(),comp2);
        vv2.clear();
        for (j = 0; j < vv.size(); j++) {
            if (vv2.empty() || (vv[j].first != vv2.back().first)) vv2.pb(vv[j]);
            else vv2.back().second += vv[j].second;
        }
        for (j = 0; j < vv2.size(); j++) ans += vv2[j].first.count()*vv2[j].second;
        vv = vv2;
    }
    printf("%I64d\n",ans);

    return 0;
}