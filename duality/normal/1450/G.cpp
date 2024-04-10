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

char s[5000];
vector<char> sorted,ans;
int l[20],r[20],c[20];
int dp[1 << 20],dp2[1 << 20],poss[20];
int main() {
    int i;
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    for (i = 0; i < n; i++) scanf(" %c",&s[i]),sorted.pb(s[i]);
    sort(sorted.begin(),sorted.end());
    sorted.resize(unique(sorted.begin(),sorted.end())-sorted.begin());

    int j;
    fill(l,l+20,-1);
    for (i = 0; i < n; i++) {
        s[i] = lower_bound(sorted.begin(),sorted.end(),s[i])-sorted.begin();
        if (l[s[i]] == -1) l[s[i]] = i;
        r[s[i]] = i,c[s[i]]++;
    }
    dp[0] = dp2[0] = 1;
    for (i = 1; i < (1 << sorted.size()); i++) {
        vpii v;
        int rr = 0,cc = 0;
        for (j = 0; j < sorted.size(); j++) {
            if (i & (1 << j)) v.pb(mp(l[j],j)),rr = max(rr,r[j]),cc += c[j];
        }
        sort(v.begin(),v.end());
        int m = 0;
        for (j = 0; j < v.size(); j++) {
            m |= (1 << v[j].second);
            dp2[i] |= dp2[m] & dp2[i^m];
        }
        if (a*(rr-v[0].first+1) <= b*cc) {
            for (j = 0; j < sorted.size(); j++) {
                if (i & (1 << j)) dp[i] |= dp2[i^(1 << j)];
            }
            dp2[i] |= dp[i];
        }
    }
    for (i = 0; i < sorted.size(); i++) {
        if (dp2[((1 << sorted.size())-1)^(1 << i)]) ans.pb(sorted[i]);
    }
    printf("%d",ans.size());
    for (i = 0; i < ans.size(); i++) printf(" %c",ans[i]);
    printf("\n");

    return 0;
}