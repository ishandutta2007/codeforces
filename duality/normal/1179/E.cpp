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

int n;
LLI L,al[1000],ar[1000];
map<LLI,LLI> M[1000],M2[1000];
LLI query(int i,LLI x) {
    if (M[i].count(x)) return M[i][x];
    LLI y;
    cout << "? " << i+1 << " " << x << endl;
    cin >> y;
    M[i][x] = y,M2[i][y] = x;
    return y;
}
LLI pos(int i,LLI y) {
    auto it = M2[i].lower_bound(y);
    if ((it != M2[i].end()) && (it->first == y)) return it->second;
    LLI s = 0,e = 1e18;
    if (it != M2[i].end()) e = it->second-1;
    if (it != M2[i].begin()) it--,s = it->second+1;
    while (s < e) {
        LLI m = (s+e) / 2;
        if (query(i,m) < y) s = m+1;
        else e = m;
    }
    return s;
}
int findAns(LLI s,LLI e,LLI l,LLI r,vi v) {
    if (v.size() == 1) {
        al[v[0]] = s,ar[v[0]] = e;
        return 0;
    }

    int i;
    vi ll,mm = v,rr;
    LLI m = (l/(L/n)+r/(L/n))/2 * (L/n),x;
    while (1) {
        swap(mm[0],mm[rand() % mm.size()]);
        x = pos(mm[0],m);
        vi l2,m2,r2;
        for (i = 0; i < mm.size(); i++) {
            LLI y = query(mm[i],x);
            if (y > m) l2.pb(mm[i]);
            else if (y < m) r2.pb(mm[i]);
            else m2.pb(mm[i]);
        }
        if ((ll.size()+l2.size() <= v.size()/2) && (ll.size()+l2.size()+m2.size() >= v.size()/2)) {
            ll.insert(ll.end(),l2.begin(),l2.end());
            rr.insert(rr.end(),r2.begin(),r2.end());
            mm = m2;
            break;
        }
        else {
            if (ll.size()+l2.size() < v.size()/2) ll.insert(ll.end(),l2.begin(),l2.end()),l2.clear();
            else rr.insert(rr.end(),r2.begin(),r2.end()),r2.clear();
            mm.clear();
            mm.insert(mm.end(),l2.begin(),l2.end());
            mm.insert(mm.end(),m2.begin(),m2.end());
            mm.insert(mm.end(),r2.begin(),r2.end());
        }
    }
    while (!mm.empty()) {
        if (ll.size() >= rr.size()) rr.pb(mm.back());
        else ll.pb(mm.back());
        mm.pop_back();
    }
    findAns(s,x,l,m,ll),findAns(x,e,m,r,rr);
    return 0;
}
int main() {
    int i;
    cin >> n >> L;
    vi v;
    for (i = 0; i < n; i++) v.pb(i);
    findAns(0,1e18,0,L,v);
    cout << "!" << endl;
    for (i = 0; i < n; i++) cout << al[i] << " " << ar[i] << endl;
    return 0;
}