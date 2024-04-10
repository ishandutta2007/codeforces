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

struct point { int x,y,z,i; };
bool comp(point a,point b) {
    if (a.x == b.x) {
        if (a.y == b.y) return a.z < b.z;
        else return a.y < b.y;
    }
    else return a.x < b.x;
}
vector<pair<pii,pii> > v;
int done[50000];
point p[50000];
int main() {
    int i;
    int n;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z),p[i].i = i;
    sort(p,p+n,comp);

    for (i = 0; i < n; i++) v.pb(mp(mp(p[i].x,p[i].y),mp(p[i].z,p[i].i)));
    sort(v.begin(),v.end());
    for (i = 0; i < n-1; i++) {
        if (!done[v[i].second.second] && !done[v[i+1].second.second] && (v[i].first == v[i+1].first)) {
            done[v[i].second.second] = done[v[i+1].second.second] = 1;
            printf("%d %d\n",v[i].second.second+1,v[i+1].second.second+1);
        }
    }
    v.clear();
    for (i = 0; i < n; i++) {
        if (!done[p[i].i]) v.pb(mp(mp(p[i].x,p[i].z),mp(p[i].y,p[i].i)));
    }
    sort(v.begin(),v.end());
    for (i = 0; i < n-1; i++) {
        if (!done[v[i].second.second] && !done[v[i+1].second.second] && (v[i].first == v[i+1].first)) {
            done[v[i].second.second] = done[v[i+1].second.second] = 1;
            printf("%d %d\n",v[i].second.second+1,v[i+1].second.second+1);
        }
    }
    v.clear();
    for (i = 0; i < n; i++) {
        if (!done[p[i].i]) v.pb(mp(mp(p[i].y,p[i].z),mp(p[i].x,p[i].i)));
    }
    sort(v.begin(),v.end());
    for (i = 0; i < n-1; i++) {
        if (!done[v[i].second.second] && !done[v[i+1].second.second] && (v[i].first == v[i+1].first)) {
            done[v[i].second.second] = done[v[i+1].second.second] = 1;
            printf("%d %d\n",v[i].second.second+1,v[i+1].second.second+1);
        }
    }
    v.clear();
    for (i = 0; i < n; i++) {
        if (!done[p[i].i]) v.pb(mp(mp(p[i].x,p[i].y),mp(p[i].z,p[i].i)));
    }
    sort(v.begin(),v.end());
    for (i = 0; i < n-1; i++) {
        if (!done[v[i].second.second] && !done[v[i+1].second.second] && (v[i].first.first == v[i+1].first.first)) {
            done[v[i].second.second] = done[v[i+1].second.second] = 1;
            printf("%d %d\n",v[i].second.second+1,v[i+1].second.second+1);
        }
    }
    v.clear();
    for (i = 0; i < n; i++) {
        if (!done[p[i].i]) v.pb(mp(mp(p[i].y,p[i].x),mp(p[i].z,p[i].i)));
    }
    sort(v.begin(),v.end());
    for (i = 0; i < n-1; i++) {
        if (!done[v[i].second.second] && !done[v[i+1].second.second] && (v[i].first.first == v[i+1].first.first)) {
            done[v[i].second.second] = done[v[i+1].second.second] = 1;
            printf("%d %d\n",v[i].second.second+1,v[i+1].second.second+1);
        }
    }
    v.clear();
    for (i = 0; i < n; i++) {
        if (!done[p[i].i]) v.pb(mp(mp(p[i].z,p[i].x),mp(p[i].y,p[i].i)));
    }
    sort(v.begin(),v.end());
    for (i = 0; i < n-1; i++) {
        if (!done[v[i].second.second] && !done[v[i+1].second.second] && (v[i].first.first == v[i+1].first.first)) {
            done[v[i].second.second] = done[v[i+1].second.second] = 1;
            printf("%d %d\n",v[i].second.second+1,v[i+1].second.second+1);
        }
    }
    v.clear();
    for (i = 0; i < n; i++) {
        if (!done[p[i].i]) v.pb(mp(mp(p[i].x,p[i].y),mp(p[i].z,p[i].i)));
    }
    sort(v.begin(),v.end());
    for (i = 0; i < n-1; i++) {
        if (!done[v[i].second.second] && !done[v[i+1].second.second]) {
            done[v[i].second.second] = done[v[i+1].second.second] = 1;
            printf("%d %d\n",v[i].second.second+1,v[i+1].second.second+1);
        }
    }
    v.clear();

    return 0;
}