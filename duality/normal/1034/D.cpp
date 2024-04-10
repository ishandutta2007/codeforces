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

int a[300000],b[300000];
vi sorted;
int tree[1 << 21],lazy[1 << 21],occ[1 << 21];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = lazy[i] = 0;
        occ[i] = sorted[e+1]-sorted[s];
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = lazy[i] = 0;
    occ[i] = sorted[e+1]-sorted[s];
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
    tree[i] = min(tree[2*i+1],tree[2*i+2]),occ[i] = 0;
    if (tree[i] == tree[2*i+1]) occ[i] += occ[2*i+1];
    if (tree[i] == tree[2*i+2]) occ[i] += occ[2*i+2];
    return 0;
}
int L[300000];
LLI pre[300001];
vpii events;
set<int> S;
map<pii,int> M;
vpii vv[300000];
LLI diff[300001];
int main() {
    int i;
    int n,k;
    scanf("%d %d",&n,&k);
    for (i = 0; i < n; i++) {
        scanf("%d %d",&a[i],&b[i]);
        sorted.pb(a[i]),sorted.pb(b[i]);
    }
    sort(sorted.begin(),sorted.end());
    sorted.resize(unique(sorted.begin(),sorted.end())-sorted.begin());
    for (i = 0; i < n; i++) {
        events.pb(mp(a[i],(i+1)));
        events.pb(mp(b[i],-(i+1)));
        a[i] = lower_bound(sorted.begin(),sorted.end(),a[i])-sorted.begin();
        b[i] = lower_bound(sorted.begin(),sorted.end(),b[i])-sorted.begin()-1;
    }

    M[mp(0,1+1e9)] = -1;
    for (i = 0; i < n; i++) {
        pii p = mp(sorted[a[i]],sorted[b[i]+1]);
        auto it = M.lower_bound(mp(p.first,0));
        if ((it == M.end()) || (it->first.first != p.first)) {
            it--;
            M[mp(it->first.first,p.first)] = it->second;
            M[mp(p.first,it->first.second)] = it->second;
            M.erase(it);
        }
        it = M.lower_bound(mp(p.second,0));
        if ((it == M.end()) || (it->first.first != p.second)) {
            it--;
            M[mp(it->first.first,p.second)] = it->second;
            M[mp(p.second,it->first.second)] = it->second;
            M.erase(it);
        }
        it = M.lower_bound(mp(p.first,0));
        while (it->first.first < p.second) {
            vv[i].pb(mp(it->second,it->first.second-it->first.first));
            it = M.erase(it);
        }
        M[p] = i;
    }

    int l = 0,r = sorted.back()-sorted[0];
    while (l < r) {
        int m = (l+r) / 2;

        int j = 0,jj;
        LLI num = 0,c = 0;
        fill(diff,diff+n+1,0);
        for (i = 0; i < n; i++) {
            for (jj = 0; jj < vv[i].size(); jj++) {
                diff[vv[i][jj].first+1] += vv[i][jj].second;
                if (vv[i][jj].first+1 <= j) c += vv[i][jj].second;
                diff[i+1] -= vv[i][jj].second;
            }
            while (c > m) c += diff[++j];
            num += j;
            if (num > k) break;
        }
        if (num <= k) r = m;
        else l = m+1;
    }
    int j = 0;
    LLI num = 0;
    build(0,sorted.size()-2,0);
    for (i = 0; i < n; i++) {
        update(0,sorted.size()-2,a[i],b[i],0,1);
        while (sorted.back()-sorted[0]-((tree[0] == 0) ? occ[0]:0) > l) {
            update(0,sorted.size()-2,a[j],b[j],0,-1);
            j++;
        }
        L[i] = j,num += j,pre[i+1] = pre[i]+j;
    }
    LLI ans = (k-num)*l;
    sort(events.begin(),events.end()),num = 0;
    S.insert(-1),S.insert(n);
    for (i = 0; i < events.size()-1; i++) {
        if (events[i].second > 0) {
            int p = events[i].second-1;
            auto it = S.lower_bound(p);
            int y = *it,x = *(--it);
            int q = lower_bound(L+p,L+y,x+1)-L;
            num -= pre[q]-pre[p],num -= (LLI) (x+1)*(y-q);
            q = lower_bound(L+p,L+y,p+1)-L;
            num += pre[q]-pre[p],num += (LLI) (p+1)*(y-q);
            S.insert(p);
        }
        else {
            int p = -events[i].second-1;
            S.erase(p);
            auto it = S.lower_bound(p);
            int y = *it,x = *(--it);
            int q = lower_bound(L+p,L+y,x+1)-L;
            num += pre[q]-pre[p],num += (LLI) (x+1)*(y-q);
            q = lower_bound(L+p,L+y,p+1)-L;
            num -= pre[q]-pre[p],num -= (LLI) (p+1)*(y-q);
        }
        ans += num*(events[i+1].first-events[i].first);
    }
    printf("%I64d\n",ans);

    return 0;
}