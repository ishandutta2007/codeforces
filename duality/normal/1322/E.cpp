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

int n,a[500000];
pii v[500000];
vpii pos;
set<pii> S;
int lazy1[1 << 20],lazy2[1 << 20];
int build(int s,int e,int i) {
    if (s == e) {
        lazy1[i] = 1e9,lazy2[i] = -1;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    lazy1[i] = 1e9,lazy2[i] = -1;
    return 0;
}
int update(int s,int e,int as,int ae,int i,int num,int t) {
    if ((s > ae) || (e < as)) return 0;
    else if ((s >= as) && (e <= ae)) {
        if (t == 0) lazy1[i] = min(lazy1[i],num);
        else lazy2[i] = max(lazy2[i],num);
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,as,ae,2*i+1,num,t),update(mid+1,e,as,ae,2*i+2,num,t);
    return 0;
}
int num[500000];
int query(int s,int e,int i,int m1,int m2) {
    if (s == e) {
        m1 = min(m1,lazy1[i]),m2 = max(m2,lazy2[i]);
        num[s] = max(max(s-m1,m2-e),0);
        return 0;
    }

    int mid = (s+e) / 2;
    m1 = min(m1,lazy1[i]),m2 = max(m2,lazy2[i]);
    query(s,mid,2*i+1,m1,m2),query(mid+1,e,2*i+2,m1,m2);
    return 0;
}
int update(int i) {
    auto it = S.upper_bound(mp(i,1e9));
    if (it != S.begin()) {
        it--;
        if ((it->first <= i) && (i <= it->second)) {
            pii p = *it;
            S.erase(it);
            if (i > p.first) S.insert(mp(p.first,i-1));
            if (i < p.second) S.insert(mp(i+1,p.second));
            return 0;
        }
        it++;
    }
    int l = i,r = i;
    if ((it != S.end()) && (it->first == i+1)) r = it->second,it = S.erase(it);
    if (it != S.begin()) {
        it--;
        if (it->second == i-1) l = it->first,S.erase(it);
    }
    S.insert(mp(l,r));
    update(0,n-1,l,(l+r+1)/2,0,l,0),update(0,n-1,(l+r+2)/2,r+1,0,r+1,1);
    return 0;
}
int query(int i) {
    auto it = S.upper_bound(mp(i,1e9));
    if (it != S.begin()) {
        it--;
        if ((it->first <= i) && (i <= it->second)) return -1;
    }
    return 1;
}
pii tree1[1 << 20],tree2[1 << 20];
int build2(int s,int e,int i) {
    if (s == e) {
        tree1[i] = tree2[i] = mp(1e9,-1);
        if (s & 1) tree2[i] = mp(a[s],a[s]);
        else tree1[i] = mp(a[s],a[s]);
        return 0;
    }

    int mid = (s+e) / 2;
    build2(s,mid,2*i+1),build2(mid+1,e,2*i+2);
    tree1[i] = mp(min(tree1[2*i+1].first,tree1[2*i+2].first),max(tree1[2*i+1].second,tree1[2*i+2].second));
    tree2[i] = mp(min(tree2[2*i+1].first,tree2[2*i+2].first),max(tree2[2*i+1].second,tree2[2*i+2].second));
    return 0;
}
pii query2(int s,int e,int qs,int qe,int i,int t) {
    if ((s > qe) || (e < qs)) return mp(1e9,-1);
    else if ((s >= qs) && (e <= qe)) return t ? tree2[i]:tree1[i];

    int mid = (s+e) / 2;
    pii l = query2(s,mid,qs,qe,2*i+1,t),r = query2(mid+1,e,qs,qe,2*i+2,t);
    return mp(min(l.first,r.first),max(l.second,r.second));
}
int main() {
    int i;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&a[i]),v[i] = mp(a[i],i);
    sort(v,v+n);

    int j;
    build(0,n-1,0),build2(0,n-1,0);
    for (i = 0; i < n; i++) {
        if (v[i].second > 0) pos.pb(mp(query(v[i].second-1),v[i].second-1));
        if (v[i].second < n-1) pos.pb(mp(query(v[i].second),v[i].second));
        if ((i == n-1) || (v[i+1].first != v[i].first)) {
            sort(pos.begin(),pos.end());
            j = 0;
            while (j < pos.size()) {
                if ((j < pos.size()-1) && (pos[j].second == pos[j+1].second)) j += 2;
                else update(pos[j].second),j++;
            }
            pos.clear();
        }
    }
    query(0,n-1,0,1e9,-1);
    int c = 0;
    for (i = 0; i < n; i++) c = max(c,num[i]);
    printf("%d\n",c);
    for (i = 0; i < n; i++) {
        if (num[i] == 0) printf("%d ",a[i]);
        else {
            pii p = query2(0,n-1,i-num[i],i+num[i],0,(i+num[i]) & 1);
            printf("%d ",(a[i+num[i]] > a[i+num[i]-1]) ? p.first:p.second);
        }
    }
    printf("\n");

    return 0;
}