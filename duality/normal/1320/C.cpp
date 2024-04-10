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

pii a[200000],b[200000];
struct mons { int x,y,z; };
bool comp(mons a,mons b) {
    return a.x < b.x;
}
vector<mons> v;
int tree[1 << 19],lazy[1 << 19];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = -b[s].second;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = max(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int prop(int s,int e,int i) {
    tree[i] += lazy[i];
    if (s != e) lazy[2*i+1] += lazy[i],lazy[2*i+2] += lazy[i];
    lazy[i] = 0;
    return 0;
}
int update(int s,int e,int as,int ae,int i,int num) {
    prop(s,e,i);
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        lazy[i] += num;
        prop(s,e,i);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num),update(mid+1,e,as,ae,2*i+2,num);
    tree[i] = max(tree[2*i+1],tree[2*i+2]);
    return 0;
}
int main() {
    int i;
    int n,m,p,x,y,z;
    scanf("%d %d %d",&n,&m,&p);
    for (i = 0; i < n; i++) scanf("%d %d",&a[i].first,&a[i].second);
    for (i = 0; i < m; i++) scanf("%d %d",&b[i].first,&b[i].second);
    for (i = 0; i < p; i++) scanf("%d %d %d",&x,&y,&z),v.pb((mons){x,y,z});
    sort(a,a+n),sort(b,b+m);
    sort(v.begin(),v.end(),comp);

    int j = 0;
    int ans = -2.1e9;
    build(0,m-1,0);
    for (i = 0; i < n; i++) {
        while ((j < p) && (v[j].x < a[i].first)) {
            int pp = upper_bound(b,b+m,mp(v[j].y,(int) 2e9))-b;
            update(0,m-1,pp,m-1,0,v[j].z);
            j++;
        }
        prop(0,m-1,0);
        ans = max(ans,tree[0]-a[i].second);
    }
    printf("%d\n",ans);

    return 0;
}