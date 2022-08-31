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
#define x first
#define y second

pii p[200000];
int lx,rx,ly,ry;
LLI A[200000];
vpii a,b;
struct line { int m,b; };
int bad(line a,line b,line c) {
    return (LLI) (b.b-a.b)*(b.m-c.m) >= (LLI) (c.b-b.b)*(a.m-b.m);
}
vector<line> tree[1 << 19];
int pos[1 << 19];
int build(int s,int e,int i) {
    if (s == e) {
        tree[i].clear(),pos[i] = 0;
        tree[i].pb((line){b[s].x-lx,ry-b[s].y});
        return 0;
    }

    int j = 0,k = 0,mid = (s+e) / 2;
    build(s,mid,2*i+1),build(mid+1,e,2*i+2);
    tree[i] = tree[2*i+2],pos[i] = 0;
    for (line l: tree[2*i+1]) {
        while ((tree[i].size() >= 2) && bad(tree[i][tree[i].size()-2],tree[i].back(),l)) tree[i].pop_back();
        tree[i].pb(l);
    }
    return 0;
}
LLI query(int s,int e,int i,pii p) {
    if ((b[e].x < p.x) || (b[s].y > p.y)) return 9e18;
    else if ((b[s].x >= p.x) && (b[e].y <= p.y)) {
        while ((pos[i]+1 < tree[i].size()) && ((LLI) tree[i][pos[i]].m*(p.y-ly)+(LLI) tree[i][pos[i]].b*(rx-p.x) \
            >= (LLI) tree[i][pos[i]+1].m*(p.y-ly)+(LLI) tree[i][pos[i]+1].b*(rx-p.x))) pos[i]++;
        return (LLI) tree[i][pos[i]].m*(p.y-ly)+(LLI) tree[i][pos[i]].b*(rx-p.x);
    }

    int mid = (s+e) / 2;
    return min(query(s,mid,2*i+1,p),query(mid+1,e,2*i+2,p));
}
int l[200000],r[200000];
LLI tree2[4][1 << 19];
int build2(int s,int e,int i) {
    if (s == e) {
        tree2[0][i] = (LLI) -(ry-ly)*p[s].x;
        tree2[1][i] = (LLI) (rx-lx)*(r[s]-p[0].y)-(LLI) (ry-ly)*p[s].x;
        tree2[2][i] = (LLI) (rx-lx)*(p[0].y-l[s])-(LLI) (ry-ly)*p[s].x;
        tree2[3][i] = (LLI) (rx-lx)*(r[s]-l[s])-(LLI) (ry-ly)*p[s].x;
        return 0;
    }

    int mid = (s+e) / 2;
    build2(s,mid,2*i+1),build2(mid+1,e,2*i+2);
    tree2[0][i] = min(tree2[0][2*i+1],tree2[0][2*i+2]);
    tree2[1][i] = min(tree2[1][2*i+1],tree2[1][2*i+2]);
    tree2[2][i] = min(tree2[2][2*i+1],tree2[2][2*i+2]);
    tree2[3][i] = min(tree2[3][2*i+1],tree2[3][2*i+2]);
    return 0;
}
LLI query2(int s,int e,int qs,int qe,int i,int t) {
    if ((s > qe) || (e < qs)) return 9e18;
    else if ((s >= qs) && (e <= qe)) return tree2[t][i];

    int mid = (s+e) / 2;
    return min(query2(s,mid,qs,qe,2*i+1,t),query2(mid+1,e,qs,qe,2*i+2,t));
}
int main() {
    int i;
    int t,n;
    scanf("%d",&t);
    while (t--) {
        scanf("%d",&n);
        for (i = 0; i < n; i++) scanf("%d %d",&p[i].x,&p[i].y);

        LLI ans = 1e18;
        int tt;
        for (tt = 0; tt < 2; tt++) {
            sort(p,p+n);
            lx = rx = p[0].x,ly = ry = p[0].y;
            for (i = 0; i < n; i++) {
                lx = min(lx,p[i].x),rx = max(rx,p[i].x);
                ly = min(ly,p[i].y),ry = max(ry,p[i].y);
                A[i] = (LLI) (rx-lx)*(ry-ly);
            }
            ans = min(ans,A[n-1]);
            lx = rx = p[n-1].x,ly = ry = p[n-1].y;
            for (i = n-1; i >= 0; i--) {
                lx = min(lx,p[i].x),rx = max(rx,p[i].x);
                ly = min(ly,p[i].y),ry = max(ry,p[i].y);
                if (i > 0) ans = min(ans,A[i-1]+(LLI) (rx-lx)*(ry-ly));
            }
            a.clear(),b.clear();
            int c = p[0].y;
            for (i = 0; i < n; i++) {
                if (p[i].y > c) a.pb(mp(p[i].x,c)),c = p[i].y;
            }
            c = p[n-1].y;
            for (i = n-1; i >= 0; i--) {
                if (p[i].y < c) b.pb(mp(p[i].x,c)),c = p[i].y;
            }
            reverse(b.begin(),b.end());
            if (!a.empty() && !b.empty()) {
                build(0,b.size()-1,0);
                for (pii p: a) ans = min(ans,query(0,b.size()-1,0,p));
            }
            for (i = 0; i < n; i++) p[i] = mp(-p[i].y,p[i].x);
        }
        sort(p,p+n);
        lx = rx = p[0].x,ly = ry = p[0].y;
        for (i = 0; i < n; i++) {
            lx = min(lx,p[i].x),rx = max(rx,p[i].x);
            ly = min(ly,p[i].y),ry = max(ry,p[i].y);
        }
        int l2 = p[0].y,r2 = p[0].y;
        for (i = 0; i < n; i++) {
            l[i] = l2,r[i] = r2;
            l2 = min(l2,p[i].y),r2 = max(r2,p[i].y);
            if ((l2 == ly) || (r2 == ry)) break;
        }
        int c = i+1;
        build2(0,c-1,0);
        l2 = r2 = p[0].y;
        for (i = n-1; i >= 0; i--) {
            int s = 0,e = c;
            while (s < e) {
                int m = (s+e) / 2;
                if ((l2 <= l[m]) && (r2 >= r[m])) s = m+1;
                else e = m;
            }
            ans = min(ans,(LLI) (ry-ly)*p[i].x+(LLI) (rx-lx)*(r2-l2)+query2(0,c-1,0,s-1,0,0)),e = c;
            int x = s;
            while (s < e) {
                int m = (s+e) / 2;
                if ((l2 <= l[m]) || (r2 >= r[m])) s = m+1;
                else e = m;
            }
            if (x < s) {
                if (l2 <= l[s-1]) ans = min(ans,(LLI) (ry-ly)*p[i].x+(LLI) (rx-lx)*(p[0].y-l2)+query2(0,c-1,x,s-1,0,1));
                else ans = min(ans,(LLI) (ry-ly)*p[i].x+(LLI) (rx-lx)*(r2-p[0].y)+query2(0,c-1,x,s-1,0,2));
            }
            ans = min(ans,(LLI) (ry-ly)*p[i].x+query2(0,c-1,s,c-1,0,3));
            l2 = min(l2,p[i].y),r2 = max(r2,p[i].y);
            if ((l2 == ly) || (r2 == ry)) break;
        }
        printf("%I64d\n",ans);
    }

    return 0;
}