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

vi vv[101];
bitset<5100> dp[101];
vi getPerm(int n,int k) {
    if (n == 1) return vi(1,0);

    int i,j;
    for (i = 1; i < n; i++) {
        if ((i >= 3) && dp[n-i][k-i-1]) {
            vi v = getPerm(n-i,k-i-1);
            for (j = 0; j < v.size(); j++) v[j] += vv[i+1][0];
            for (j = 1; j < i+1; j++) {
                if (vv[i+1][j] > vv[i+1][0]) v.pb(vv[i+1][j]+n-i-1);
                else v.pb(vv[i+1][j]);
            }
            return v;
        }
        else if ((k >= (i+1)*(i+2)/2-1) && dp[n-i][k-(i+1)*(i+2)/2+1]) {
            vi v = getPerm(n-i,k-(i+1)*(i+2)/2+1);
            if (max_element(v.begin(),v.end())-v.begin() > min_element(v.begin(),v.end())-v.begin()) reverse(v.begin(),v.end());
            for (j = 0; j < i; j++) v.pb(n-i+j);
            return v;
        }
    }
    return vi();
}
int main() {
    int i,j,k;
    dp[1][1] = 1;
    for (i = 2; i <= 100; i++) {
        for (j = 1; j < i; j++) {
            if (j >= 3) dp[i] |= dp[i-j] << (j+1);
            dp[i] |= dp[i-j] << ((j+1)*(j+2)/2-1);
        }
        if (i >= 4) {
            for (j = 0; j < i; j++) vv[i].pb(j);
            while (1) {
                int c = 0;
                random_shuffle(vv[i].begin(),vv[i].end());
                for (j = 0; j < vv[i].size(); j++) {
                    int s = vv[i][j],b = vv[i][j];
                    for (k = j; k < vv[i].size(); k++) {
                        s = min(s,vv[i][k]),b = max(b,vv[i][k]);
                        if (b-s == k-j) c++;
                    }
                }
                if (c == i+1) break;
            }
        }
    }

    int q,n;
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d %d",&n,&k);

        if (!dp[n][k]) printf("NO\n");
        else {
            printf("YES\n");
            vi v = getPerm(n,k);
            for (j = 0; j < n; j++) printf("%d ",v[j]+1);
            printf("\n");
        }
    }

    return 0;
}