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

char S[500001];
int N;
int l[1000010];
int r[1000010];
int del[1000010];
vi v;
int main() {
    int i;
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%s",S);

        N = strlen(S);
        int c = N+1;
        for (i = 0; i < N; i++) {
            if (S[i] == '0') r[c]++,v.pb(c),c++;
            else l[c]++,c--,v.pb(c);
        }
        sort(v.begin(),v.end());
        for (i = 0; i < v.size(); i++) del[v[i]]++;
        c = N+1;
        string ans;
        int s = v[0],e = v.back();
        for (i = 0; i < N; i++) {
            if ((r[c] > 1) || ((r[c] == 1) && (l[c+1] > 0))) ans += '0';
            else if ((r[c] == 1) && (l[c+1] == 0)) {
                while (del[s] == 0) s++;
                while (del[e] == 0) e--;
                //cout<<s-(N+1)<<","<<e-(N+1)<<endl;
                if (s < c) ans += '1';
                else ans += '0';
            }
            else ans += '1';
            if (ans.back() == '0') r[c]--,del[c]--,c++;
            else l[c]--,c--,del[c]--;
        }
        cout << ans << endl;
        for (i = 0; i < v.size(); i++) del[v[i]] = 0;
        v.clear();
    }

    return 0;
}