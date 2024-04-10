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

int a[200000];
LLI tree[1 << 19],lazy[1 << 19];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i] = a[s];
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = tree[2*i+1] + tree[2*i+2];
    return 0;
}
int prop(int s,int e,int i) {
    tree[i] += (e-s+1)*lazy[i];
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
    tree[i] = tree[2*i+1] + tree[2*i+2];
    return 0;
}
LLI query(int s,int e,int qs,int qe,int i) {
    prop(s,e,i);
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) return tree[i];

    int mid = (s+e) / 2;
    return query(s,mid,qs,qe,2*i+1)+query(mid+1,e,qs,qe,2*i+2);
}
vector<pair<int,pii> > in;
int query2(int s,int e,int qs,int qe,int i) {
    prop(s,e,i);
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) {
        in.pb(mp(i,mp(s,e)));
        return 0;
    }

    int mid = (s+e) / 2;
    query2(s,mid,qs,qe,2*i+1),query2(mid+1,e,qs,qe,2*i+2);
    return 0;
}
map<int,int> M,M2;
int main() {
    int i;
    int n,q;
    int t,x,y;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) {
        scanf("%d",&a[i]);
        if ((i == 0) || (a[i] < a[i-1])) M[i] = a[i];
    }
    M[-1] = 2e9;
    for (auto it = M.begin(); it != M.end(); it++) M2[it->second] = it->first;
    build(0,n-1,0);
    for (i = 0; i < q; i++) {
        scanf("%d %d %d",&t,&x,&y),x--;
        if (t == 1) {
            auto it = M.upper_bound(x);
            it--;
            int l = -1;
            while (it->second <= y) {
                update(0,n-1,it->first,(l == -1) ? x:l-1,0,y-it->second);
                M2.erase(it->second);
                if (l == -1) {
                    if ((y > it->second) && (x < n-1) && !M.count(x+1)) M[x+1] = it->second,M2[it->second] = x+1;
                }
                l = it->first,it = M.erase(it),it--;
            }
            if (l != -1) M[l] = y,M2[y] = l;
        }
        else {
            int ans = 0;
            while (x < n) {
                auto it = M2.upper_bound(y);
                if (it != M2.begin()) {
                    it--;
                    x = max(x,it->second);
                    query2(0,n-1,x,n-1,0);
                    int j,l = x;
                    for (j = 0; j < in.size(); j++) {
                        if (y >= tree[in[j].first]) y -= tree[in[j].first],l = in[j].second.second;
                        else {
                            int u = in[j].first;
                            int s = in[j].second.first,e = in[j].second.second;
                            while (s <= e) {
                                prop(s,e,u);
                                if (s == e) {
                                    if (y >= tree[u]) y -= tree[u],l = s;
                                    break;
                                }
                                else {
                                    int mid = (s+e) / 2;
                                    prop(s,mid,2*u+1);
                                    if (y >= tree[2*u+1]) y -= tree[2*u+1],l = mid,s = mid+1,u = 2*u+2;
                                    else e = mid,u = 2*u+1;
                                }
                            }
                            break;
                        }
                    }
                    in.clear();
                    ans += l-x+1,x = l+1;
                    assert(y >= 0);
                }
                else x = n;
            }
            printf("%d\n",ans);
        }
    }

    return 0;
}