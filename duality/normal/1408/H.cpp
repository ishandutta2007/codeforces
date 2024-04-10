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

int a[500000],ll[500001],rr[500001];
vpii v;
priority_queue<int,vi,greater<int> > H;
int main() {
    int i;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        int z = 0;
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d",&a[i]),z += (a[i] == 0);

        int p = 0;
        for (i = 0; i < n; i++) {
            if (a[i] != 0) {
                if (p <= z/2) ll[a[i]] = max(ll[a[i]],p);
                else rr[a[i]] = max(rr[a[i]],min(z-p,z/2));
            }
            else p++;
        }
        for (i = 1; i <= n; i++) {
            if (ll[i]+rr[i] >= z/2) ll[i] = z/2,rr[i] = 0;
            v.pb(mp(ll[i],rr[i])),ll[i] = rr[i] = 0;
        }
        int j = 0;
        sort(v.begin(),v.end());
        for (i = 0; i < z/2; i++) {
            while ((j < v.size()) && (v[j].first <= i)) j++;
            if (j >= v.size()) break;
            else j++;
        }
        p = i,j = v.size()-1;
        for (i = p-1; i >= 0; i--) {
            while ((j >= 0) && (v[j].first > i)) H.push(v[j].second),j--;
            H.pop();
        }
        while (j >= 0) H.push(v[j].second),j--;
        for (i = 0; i < z/2-p; i++) {
            while (!H.empty() && (H.top() <= i)) H.pop();
            if (H.empty()) break;
            else H.pop();
        }
        printf("%d\n",p+i);
        v.clear();
        while (!H.empty()) H.pop();
    }

    return 0;
}