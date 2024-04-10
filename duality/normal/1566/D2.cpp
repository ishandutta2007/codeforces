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

int a[90000],num[90001],num2[90001],num3[90001];
vi v;
int used[300][300];
int main() {
    int i,j;
    int t,n,m;
    scanf("%d",&t);
    while (t--) {
        scanf("%d %d",&n,&m);
        for (i = 0; i < n*m; i++) scanf("%d",&a[i]),v.pb(a[i]);
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        for (i = 0; i < n*m; i++) a[i] = lower_bound(v.begin(),v.end(),a[i])-v.begin(),num[a[i]]++;

        int ans = 0;
        for (i = 0; i < v.size(); i++) num2[i] = num[i];
        for (i = 1; i < v.size(); i++) num[i] += num[i-1];
        for (i = 0; i < n*m; i++) {
            int p;
            if (num2[a[i]] <= (((num[a[i]]-1) % m)+1)) p = num[a[i]]-num3[a[i]]-1;
            else {
                if (num3[a[i]] < m-((num[a[i]]-num2[a[i]]) % m)) {
                    int u = num[a[i]]-num2[a[i]];
                    p = u+(m-(u % m))-num3[a[i]]-1;
                }
                else {
                    int x = num3[a[i]]-(m-((num[a[i]]-num2[a[i]]) % m));
                    int u = ((num[a[i]]-1) % m)+1;
                    if (num3[a[i]] < num2[a[i]]-u) p = num[a[i]]-u-x-1;
                    else {
                        p = num[a[i]]-(num3[a[i]]-(num2[a[i]]-u))-1;
                    }
                }
            }
            num3[a[i]]++;
            used[p/m][p % m] = 1;
            for (j = 0; j < (p % m); j++) {
                if (used[p/m][j]) ans++;
            }
        }
        printf("%d\n",ans);
        for (i = 0; i < n; i++) fill(used[i],used[i]+m,0);
        fill(num,num+v.size()+1,0);
        fill(num2,num2+v.size()+1,0);
        fill(num3,num3+v.size()+1,0);
        v.clear();
    }

    return 0;
}