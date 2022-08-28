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
#pragma GCC optimize("Ofast")

int n;
LLI l[50000],r[50000];
int o[50000];
vplli vv,vv2,vv3;
int parent[250000];
int find(int n) {
    if (parent[n] != n) parent[n] = find(parent[n]);
    return parent[n];
}
int merge(int a,int b) {
    //cout<<"merge "<<a<<","<<b<<endl;
    a = find(a),b = find(b);
    if (a != b) parent[a] = b;
    return 0;
}
unordered_map<LLI,int> M;
vector<map<plli,int> > in;
vi all;
int add(int p) {
    int i;
    LLI u = 1;
    LLI l = 0,r = (1LL << n)-1;
    for (i = n-1; i >= 0; i--) {
        LLI m = (l+r) / 2;
        if (vv3[p].second <= m) u = 2*u,r = m;
        else if (vv3[p].first > m) u = 2*u+1,l = m+1;
        else break;
    }
    int d = i;
    //cout<<vv3[p].first<<";"<<vv3[p].second<<endl;
    //cout<<l<<","<<r<<","<<u<<endl;
    if (!M.count(u)) M[u] = in.size(),in.pb(map<plli,int>()),all.pb(0);
    all[M[u]] = 1;
    for (auto &[nn,p2]: in[M[u]]) merge(p2,p);
    in[M[u]].clear(),in[M[u]].insert(mp(vv3[p],p));
    u >>= 1,d++;
    while (u > 0) {
        if (!M.count(u)) M[u] = in.size(),in.pb(map<plli,int>()),all.pb(0);
        if (all[M[u]]) merge(in[M[u]].begin()->second,p);
        else {
            //cout<<"insert "<<vv3[p].first<<","<<vv3[p].second<<" into "<<u<<endl;
            map<plli,int> &MM = in[M[u]];
            LLI l = vv3[p].first,r = vv3[p].second;
            l &= ~(1LL << d),r &= ~(1LL << d);
            assert(l <= r);
            if (MM.empty()) MM.insert(mp(mp(l,r),p));
            else {
                auto it = MM.upper_bound(mp(l,1e18));
                if (it != MM.begin()) {
                    it--;
                    if (it->first.second >= l) merge(it->second,p),l = min(l,it->first.first),r = max(r,it->first.second),MM.erase(it);
                }
                it = MM.upper_bound(mp(r,1e18));
                if (it != MM.begin()) {
                    it--;
                    if (it->first.second >= l) merge(it->second,p),l = min(l,it->first.first),r = max(r,it->first.second),MM.erase(it);
                }
                it = MM.lower_bound(mp(l,0LL));
                while ((it != MM.end()) && (it->first.second <= r)) {
                    merge(it->second,p);
                    it = MM.erase(it);
                }
                MM.insert(mp(mp(l,r),p));
            }
        }
        u >>= 1,d++;
    }
    return 0;
}
int add2(LLI s,LLI e) {
    //cout<<"add2 "<<s<<","<<e<<endl;
    int p = lower_bound(vv3.begin(),vv3.end(),mp(s,0LL))-vv3.begin();
    while ((p < vv3.size()) && (vv3[p].second <= e)) add(p++);
    return 0;
}
int main() {
    int i;
    int m;
    char s[6];
    LLI a,b;
    scanf("%d %d",&n,&m);
    for (i = 0; i < m; i++) {
        scanf("%s %lld %lld",s,&a,&b);
        if (s[0] == 'b') l[i] = a,r[i] = b,o[i] = 1,vv.pb(mp(a,b));
        else l[i] = a,r[i] = b,o[i] = 2;
    }
    for (i = 0; i < 250000; i++) parent[i] = i;

    int j;
    a = 0;
    sort(vv.begin(),vv.end());
    vv2 = vv;
    for (i = 0; i < vv.size(); i++) {
        if (a < vv[i].first) vv2.pb(mp(a,vv[i].first-1));
        a = vv[i].second+1;
    }
    if (a < (1LL << n)) vv2.pb(mp(a,(1LL << n)-1));
    for (i = 0; i < vv2.size(); i++) {
        for (j = n-1; j >= 0; j--) {
            if ((vv2[i].first^vv2[i].second) & (1LL << j)) break;
        }
        if (j == -1) vv3.pb(vv2[i]);
        else {
            a = vv2[i].first,b = vv2[i].second;
            a |= (1LL << j)-1,b &= ~((1LL << j)-1);
            vv3.pb(mp(vv2[i].first,a));
            vv3.pb(mp(b,vv2[i].second));
        }
    }
    sort(vv3.begin(),vv3.end());

    a = 0;
    vi ans;
    for (i = 0; i < vv.size(); i++) {
        if (a < vv[i].first) add2(a,vv[i].first-1);
        a = vv[i].second+1;
    }
    if (a < (1LL << n)) add2(a,(1LL << n)-1);
    for (i = m-1; i >= 0; i--) {
        if (o[i] == 1) add2(l[i],r[i]);
        else {
            int x = upper_bound(vv3.begin(),vv3.end(),mp(l[i],(LLI) 1e18))-vv3.begin()-1;
            int y = upper_bound(vv3.begin(),vv3.end(),mp(r[i],(LLI) 1e18))-vv3.begin()-1;
            if (find(x) == find(y)) ans.pb(1);
            else ans.pb(0);
        }
    }
    reverse(ans.begin(),ans.end());
    for (int a: ans) printf("%d\n",a);

    return 0;
}