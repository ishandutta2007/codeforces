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

bitset<2000> xx[2001];
bitset<2000> bs[2000];
int c[2000];
set<pii> S,S2;
int main() {
    int i,j;
    int n,m,q;
    int a,l,r;
    scanf("%d %d %d",&n,&m,&q);
    for (i = 0; i < m; i++) xx[i+1] = xx[i],xx[i+1][i] = 1;
    for (i = 0; i < n; i++) S.insert(mp(c[i],i));
    for (i = 0; i < q; i++) {
        scanf("%d %d %d",&a,&l,&r);
        a--,l--,r--;
        auto it = S.find(mp(c[a],a));
        if (it != S.begin()) {
            auto it2 = it;
            it2--;
            if (S2.count(mp(it2->second,it->second))) S2.erase(mp(it2->second,it->second));
        }
        if (it != (--S.end())) {
            auto it2 = it;
            it2++;
            if (S2.count(mp(it->second,it2->second))) S2.erase(mp(it->second,it2->second));
        }
        if ((it != S.begin()) && (it != (--S.end()))) {
            auto it2 = it,it3 = it;
            it2--,it3++;
            if ((bs[it2->second] & bs[it3->second]) != bs[it2->second]) S2.insert(mp(it2->second,it3->second));
        }
        S.erase(it);
        bs[a] ^= xx[r+1]^xx[l],c[a] = bs[a].count();
        it = S.insert(mp(c[a],a)).first;
        if (it != S.begin()) {
            auto it2 = it;
            it2--;
            if ((bs[it2->second] & bs[it->second]) != bs[it2->second]) S2.insert(mp(it2->second,it->second));
        }
        if (it != (--S.end())) {
            auto it2 = it;
            it2++;
            if ((bs[it->second] & bs[it2->second]) != bs[it->second]) S2.insert(mp(it->second,it2->second));
        }
        if ((it != S.begin()) && (it != (--S.end()))) {
            auto it2 = it,it3 = it;
            it2--,it3++;
            if (S2.count(mp(it2->second,it3->second))) S2.erase(mp(it2->second,it3->second));
        }
        if (S2.empty()) printf("-1\n");
        else {
            int y1 = S2.begin()->first,y2 = S2.begin()->second;
            if (y1 > y2) swap(y1,y2);
            bitset<2000> b = bs[y1] & ~bs[y2];
            for (j = 0; j < m; j++) {
                if (b[j]) break;
            }
            int x1 = j;
            b = ~bs[y1] & bs[y2];
            for (j = 0; j < m; j++) {
                if (b[j]) break;
            }
            int x2 = j;
            if (x1 > x2) swap(x1,x2);
            printf("%d %d %d %d\n",y1+1,x1+1,y2+1,x2+1);
        }
    }

    return 0;
}