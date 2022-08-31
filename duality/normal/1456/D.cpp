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

int x[5001],t[5001];
vpii clone[5001],pos[5001];
vpii com(vpii v) {
    int i,r = -2e9,l = -1;
    vpii v2;
    for (i = 0; i < v.size(); i++) v[i].first = max(v[i].first,(int) -1.1e9),v[i].second = min(v[i].second,(int) 1.1e9);
    sort(v.begin(),v.end());
    for (i = 0; i < v.size(); i++) {
        if (v[i].first > r+1) {
            if (i > 0) v2.pb(mp(l,r));
            l = v[i].first;
        }
        r = max(r,v[i].second);
    }
    if (r != -2e9) v2.pb(mp(l,r));
    return v2;
}
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 1; i <= n; i++) scanf("%d %d",&t[i],&x[i]);

    int j;
    clone[0].pb(mp(0,0)),pos[0].pb(mp(0,0));
    for (i = 0; i < n; i++) {
        int tt = t[i+1]-t[i],dd = abs(x[i+1]-x[i]);
        for (j = 0; j < clone[i].size(); j++) {
            if (dd <= tt) {
                clone[i+1].pb(clone[i][j]);
                int l = x[i],r = x[i+1];
                if (l > r) swap(l,r);
                l -= (tt-dd)/2,r += (tt-dd)/2;
                clone[i+1].pb(mp(l,r));
                pos[i+1].pb(mp(x[i+1]-(tt-dd),x[i+1]+(tt-dd)));
            }
            if ((clone[i][j].first <= x[i+1]) && (x[i+1] <= clone[i][j].second)) pos[i+1].pb(mp(x[i]-tt,x[i]+tt));
        }
        for (j = 0; j < pos[i].size(); j++) {
            int l = pos[i][j].first,r = pos[i][j].second;
            int d = 0;
            if (x[i+1] > r) d = x[i+1]-r;
            else if (x[i+1] < l) d = l-x[i+1];
            if (d <= tt) pos[i+1].pb(mp(x[i+1]-(tt-d),x[i+1]+(tt-d)));
            l = max(l,x[i+1]-tt),r = min(r,x[i+1]+tt);
            if (l <= r) {
                int s = l,e = r;
                int c = (tt-abs(x[i+1]-l))/2;
                s = min(s,min(l,x[i+1])-c);
                e = max(e,max(l,x[i+1])+c);
                c = (tt-abs(x[i+1]-r))/2;
                s = min(s,min(r,x[i+1])-c);
                e = max(e,max(r,x[i+1])+c);
                clone[i+1].pb(mp(s,e));
            }
        }
        pos[i+1] = com(pos[i+1]);
        clone[i+1] = com(clone[i+1]);
        /*cout<<"pos: ";
        for (j=0;j<pos[i+1].size();j++)cout<<pos[i+1][j].first<<","<<pos[i+1][j].second<<" ";
        cout<<endl;
        cout<<"clone: ";
        for (j=0;j<clone[i+1].size();j++)cout<<clone[i+1][j].first<<","<<clone[i+1][j].second<<" ";
        cout<<endl<<endl;*/
        if (pos[i+1].empty() && clone[i+1].empty()) break;
    }
    if (i < n) printf("NO\n");
    else printf("YES\n");

    return 0;
}