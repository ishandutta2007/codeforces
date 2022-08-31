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

int a[200000];
pii p[200000];
pii poss[6000000];
set<int> bad;
vpii v2;
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),p[i] = mp(a[i],i);
    sort(p,p+n);

    int c = 0;
    for (i = 0; i < n-1; i++) {
        if (p[i].first == p[i+1].first) bad.insert(p[i].first),c++;
    }
    if (bad.size() >= 2) {
        int u = *bad.begin();
        bad.erase(bad.begin());
        int v = *bad.begin();
        vi pos1,pos2;
        for (i = 0; i < n; i++) {
            if (p[i].first == u) pos1.pb(p[i].second);
            if (p[i].first == v) pos2.pb(p[i].second);
        }
        printf("YES\n%d %d %d %d\n",pos1[0]+1,pos2[0]+1,pos1[1]+1,pos2[1]+1);
        return 0;
    }
    else if ((bad.size() == 1) && (c >= 3)) {
        int u = *bad.begin();
        vi pos1;
        for (i = 0; i < n; i++) {
            if (p[i].first == u) pos1.pb(p[i].second);
        }
        printf("YES\n%d %d %d %d\n",pos1[0]+1,pos1[1]+1,pos1[2]+1,pos1[3]+1);
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (!bad.count(p[i].first)) v2.pb(p[i]);
    }
    int j;
    for (i = 0; i < 6000000; i++) poss[i] = mp(-1,-1);
    for (i = 0; i < v2.size(); i++) {
        for (j = i+1; j < v2.size(); j++) {
            if (poss[v2[i].first+v2[j].first] != mp(-1,-1)) {
                printf("YES\n%d %d",poss[v2[i].first+v2[j].first].first+1,poss[v2[i].first+v2[j].first].second+1);
                printf(" %d %d\n",v2[i].second+1,v2[j].second+1);
                return 0;
            }
            else poss[v2[i].first+v2[j].first] = mp(v2[i].second,v2[j].second);
        }
    }
    if (bad.size() == 1) {
        int u = *bad.begin();
        vi pos1;
        for (i = 0; i < n; i++) {
            if (p[i].first == u) pos1.pb(p[i].second);
        }
        if (poss[2*u] != mp(-1,-1)) {
            printf("YES\n%d %d",poss[2*u].first+1,poss[2*u].second+1);
            printf(" %d %d\n",pos1[0]+1,pos1[1]+1);
            return 0;
        }
        for (i = 0; i < v2.size(); i++) {
            if (poss[v2[i].first+u] != mp(-1,-1)) {
                printf("YES\n%d %d",poss[v2[i].first+u].first+1,poss[v2[i].first+u].second+1);
                printf(" %d %d\n",v2[i].second+1,pos1[0]+1);
                return 0;
            }
        }
    }
    printf("NO\n");

    return 0;
}