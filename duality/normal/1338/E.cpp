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

bitset<8000> adjMat[8000];
pii out[8000];
int main() {
    int i,j,k;
    int n;
    char c;
    scanf("%d\n",&n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n/4; j++) {
            c = getchar();
            c = ((c >= '0') && (c <= '9')) ? (c-'0'):(c-'A'+10);
            for (k = 0; k < 4; k++) {
                if (c & (1 << (3-k))) adjMat[i][4*j+k] = 1;
            }
        }
        getchar();
    }

    LLI ans = 0;
    for (i = 0; i < n; i++) out[i] = mp(adjMat[i].count(),i);
    sort(out,out+n);
    for (i = n-1; i >= 0; i--) {
        if (out[i].first == i) ans += i+614LL*n*i;
        else break;
    }
    if (i < 0) {
        printf("%lld\n",ans);
        return 0;
    }
    vi v,vv,vv2;
    for (; i >= 0; i--) v.pb(out[i].second);
    swap(v[0],v.back());
    for (i = 1; i < v.size(); i++) {
        if (adjMat[v[0]][v[i]]) {
            int c = 0;
            for (j = 1; j < v.size(); j++) {
                if (adjMat[v[j]][v[0]] && adjMat[v[i]][v[j]]) c++;
            }
            vv.pb(c);
        }
    }
    sort(vv.begin(),vv.end());
    for (i = 1; i <= v.size()-vv.size(); i++) vv2.pb(lower_bound(vv.begin(),vv.end(),i)-vv.begin());
    for (i = 0; i < vv.size(); i++) {
        ans += vv.size()-i-1+vv[i];
        ans += 2*(vv2[vv[i]-1]+(vv2.size()-vv[i]));
        ans += 3*(i-vv2[vv[i]-1]);
    }
    for (i = 0; i < vv2.size(); i++) {
        ans += vv2.size()-i-1+vv2[i];
        if (vv2[i] > 0) {
            ans += 2*(vv[vv2[i]-1]+vv.size()-vv2[i]);
            ans += 3*(i-vv[vv2[i]-1]);
        }
        else {
            ans += 2*vv.size();
            ans += 3*i;
        }
    }
    printf("%lld\n",ans);

    return 0;
}