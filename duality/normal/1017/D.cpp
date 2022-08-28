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

int w[12];
int num[1 << 12];
int value[1 << 12];
vpii wu;
int place[1 << 12];
vi pre[1 << 12];
char s[13];
int main() {
    int i,j;
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for (i = 0; i < n; i++) scanf("%d",&w[i]);
    for (i = 0; i < m; i++) {
        scanf("%s",s);
        int x = 0;
        for (j = 0; j < n; j++) {
            if (s[j] == '1') x |= (1 << j);
        }
        num[x]++;
    }

    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) value[i] += w[j];
        }
        wu.pb(mp(value[i],i));
    }
    sort(wu.begin(),wu.end());
    for (i = 0; i < (1 << n); i++) place[wu[i].second] = i;
    for (i = 0; i < (1 << n); i++) {
        pre[i].resize(1 << n);
        for (j = 0; j < (1 << n); j++) pre[i][place[((1 << n)-1)^i^j]] = num[j];
        for (j = 1; j < pre[i].size(); j++) pre[i][j] += pre[i][j-1];
    }

    int k;
    for (i = 0; i < q; i++) {
        scanf("%s %d",s,&k);
        int x = 0;
        for (j = 0; j < n; j++) {
            if (s[j] == '1') x |= (1 << j);
        }
        int p = upper_bound(wu.begin(),wu.end(),mp(k,(int) 1e9))-wu.begin()-1;
        printf("%d\n",((p == -1) ? 0:pre[x][p]));
    }

    return 0;
}