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

struct diam { int a,w,v,i; };
bool comp(diam a,diam b) {
    if (a.v == b.v) return a.w < b.w;
    else return a.v > b.v;
}
diam dia[200000];
LLI num[200000];
int pos[200000];
LLI small[20][1 << 19],small2[20][1 << 19],big[20][1 << 19];
int build(int s,int e,int i,int t) {
    if (s == e) {
        small[t][i] = (LLI) num[s]*((dia[s].w < (1 << t)) ? dia[s].w:0);
        small2[t][i] = (LLI) num[s]*((dia[s].w < (1 << t)) ? dia[s].v:0);
        big[t][i] = ((num[s] > 0) && (dia[s].w >= (1 << t)) && (dia[s].w < (1 << (t+1)))) ? dia[s].w:2e18;
        return 0;
    }

    int mid = (s+e) / 2;
    build(s,mid,2*i+1,t),build(mid+1,e,2*i+2,t);
    small[t][i] = small[t][2*i+1] + small[t][2*i+2];
    small2[t][i] = small2[t][2*i+1] + small2[t][2*i+2];
    big[t][i] = min(big[t][2*i+1],small[t][2*i+1]+big[t][2*i+2]);
    return 0;
}
int update(int s,int e,int ai,int i,int t) {
    if ((s > ai) || (e < ai)) return 0;
    else if (s == e) {
        small[t][i] = (LLI) num[s]*((dia[s].w < (1 << t)) ? dia[s].w:0);
        small2[t][i] = (LLI) num[s]*((dia[s].w < (1 << t)) ? dia[s].v:0);
        big[t][i] = ((num[s] > 0) && (dia[s].w >= (1 << t)) && (dia[s].w < (1 << (t+1)))) ? dia[s].w:2e18;
        return 0;
    }

    int mid = (s+e) / 2;
    update(s,mid,ai,2*i+1,t),update(mid+1,e,ai,2*i+2,t);
    small[t][i] = small[t][2*i+1] + small[t][2*i+2];
    small2[t][i] = small2[t][2*i+1] + small2[t][2*i+2];
    big[t][i] = min(big[t][2*i+1],small[t][2*i+1]+big[t][2*i+2]);
    return 0;
}
vector<pair<int,pii> > nodes;
int getNodes(int s,int e,int qs,int qe,int i) {
    if ((s > qe) || (e < qs)) return 0;
    else if ((s >= qs) && (e <= qe)) {
        nodes.pb(mp(i,mp(s,e)));
        return 0;
    }

    int mid = (s+e) / 2;
    getNodes(s,mid,qs,qe,2*i+1),getNodes(mid+1,e,qs,qe,2*i+2);
    return 0;
}
pair<plli,int> query(int s,int e,int i,int t,LLI c) {
    if (s == e) return mp(mp(c,0),s);

    int mid = (s+e) / 2;
    if (c >= small[t][2*i+1]) {
        pair<plli,int> r = query(mid+1,e,2*i+2,t,c-small[t][2*i+1]);
        return mp(mp(r.first.first,r.first.second+small2[t][2*i+1]),r.second);
    }
    else return query(s,mid,2*i+1,t,c);
}
pair<plli,int> query2(int s,int e,int i,int t,LLI c) {
    if (s == e) return mp(mp(c-dia[s].w,dia[s].v),s);

    int mid = (s+e) / 2;
    if (c >= big[t][2*i+1]) return query2(s,mid,2*i+1,t,c);
    else {
        pair<plli,int> r = query2(mid+1,e,2*i+2,t,c-small[t][2*i+1]);
        return mp(mp(r.first.first,r.first.second+small2[t][2*i+1]),r.second);
    }
}
int main() {
    int i,j;
    int n,q;
    int t,k,d;
    LLI c;
    scanf("%d %d",&n,&q);
    for (i = 0; i < n; i++) scanf("%d %d %d",&dia[i].a,&dia[i].w,&dia[i].v),dia[i].i = i;
    sort(dia,dia+n,comp);
    for (i = 0; i < n; i++) num[i] = dia[i].a,pos[dia[i].i] = i;
    for (i = 0; i < 20; i++) build(0,n-1,0,i);
    for (i = 0; i < q; i++) {
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d %d",&k,&d),d--;
            num[pos[d]] += k;
            for (j = 0; j < 20; j++) update(0,n-1,pos[d],0,j);
        }
        else if (t == 2) {
            scanf("%d %d",&k,&d),d--;
            num[pos[d]] -= k;
            for (j = 0; j < 20; j++) update(0,n-1,pos[d],0,j);
        }
        else {
            scanf("%I64d",&c);
            int p = 0;
            LLI ans = 0;
            for (j = 19; j >= 0; j--) {
                if (p == n) break;
                getNodes(0,n-1,p,n-1,0);
                for (k = 0; k < nodes.size(); k++) {
                    int u = nodes[k].first;
                    if (big[j][u] <= c) {
                        pair<plli,int> q = query2(nodes[k].second.first,nodes[k].second.second,u,j,c);
                        c = q.first.first,ans += q.first.second,p = q.second+1;
                        break;
                    }
                    else {
                        if (small[j][u] <= c) {
                            c -= small[j][u],p = nodes[k].second.second+1;
                            ans += small2[j][u];
                        }
                        else {
                            pair<plli,int> q = query(nodes[k].second.first,nodes[k].second.second,u,j,c);
                            c = q.first.first,ans += q.first.second,p = q.second;
                            LLI x = min(c/dia[p].w,num[p]);
                            ans += x*dia[p].v,c -= x*dia[p].w,p++;
                            break;
                        }
                    }
                }
                nodes.clear();
            }
            printf("%I64d\n",ans);
        }
    }

    return 0;
}