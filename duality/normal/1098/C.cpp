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

LLI poss[100001];
int p[100000],d[100000];
priority_queue<pair<int,pii> > H;
int main() {
    int n;
    LLI s;
    cin >> n >> s;

    if ((s < 2*n-1) || (s > (LLI) n*(n+1)/2)) {
        printf("No\n");
        return 0;
    }

    int i;
    int l = 1,r = n-1;
    while (l < r) {
        int m = (l+r) / 2;

        poss[1] = 1;
        for (i = 2; i <= n; i++) {
            int x = (i-1)/m;
            int y = i-1-m*x;
            poss[i] = i+y*poss[x+1]+(m-y)*poss[x];
        }
        if (s >= poss[n]) r = m;
        else l = m+1;
    }
    printVar(l);
    int maxd = 1;
    d[0] = 1,p[0] = -1,s--;
    H.push(mp(-1,mp(0,l)));
    for (i = 1; i < n; i++) {
        while (1) {
            pii u = H.top().second;
            H.pop();
            //cout<<"pop "<<u.first<<endl;

            if (u.second == 0) continue;
            LLI s2 = s-(d[u.first]+1);
            LLI maxd2 = max(maxd,d[u.first]+1);
            LLI c = n-i-1;
            //cout<<s2<<","<<maxd2<<","<<c<<endl;
            //cout <<c*maxd2+c*(c-1)/2<<endl;
            if (c*(maxd2+1)+c*(c-1)/2 < s2) continue;
            s = s2,maxd = maxd2;
            p[i] = u.first,d[i] = d[u.first]+1;
            H.push(mp(-d[u.first],mp(u.first,u.second-1)));
            H.push(mp(-d[i],mp(i,l)));
            //cout<<p[i]<<","<<d[i]<<endl;
            break;
        }
        //cout<<s<<endl;
    }
    printf("Yes\n");
    for (i = 1; i < n; i++) printf("%d ",p[i]+1);
    printf("\n");

    return 0;
}