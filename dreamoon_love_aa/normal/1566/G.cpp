/*{{{*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB emplace_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("[DEBUG] ");W(__VA_ARGS__);}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;/*}}}*/
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}

const int SIZE = 1<<17;
const LL INF=4e9;
set<PII>e[SIZE];
set<pair<int,PII>>cost4;
multiset<LL>cost3;
LL v3[SIZE];
int n,m;
void init(){
    FOR(i,1,n){
        cost3.insert(INF);
        v3[i]=INF;
    }
}
void add(int u, int v, int w){
    cost3.erase(cost3.find(v3[u]));
    e[u].insert({w,v});
    auto it=e[u].begin();
    if(it!=e[u].end()){
        v3[u]=(it++)->F;
        if(it!=e[u].end()){
            v3[u]+=(it++)->F;
            if(it!=e[u].end()){
                v3[u]+=it->F;
            }else v3[u]=INF;
        }else v3[u]=INF;
    }else v3[u]=INF;
    cost3.insert(v3[u]);
}
map<PII,int>ew;
void add_edge(int u, int v, int w){
    ew[{u,v}]=w;
    ew[{v,u}]=w;
    add(u, v, w);
    add(v, u, w);
}
void remove(int u, int v){
    cost3.erase(cost3.find(v3[u]));
    e[u].erase({ew[{u,v}],v});
    ew.erase(MP(u,v));
    auto it=e[u].begin();
    if(it!=e[u].end()){
        v3[u]=(it++)->F;
        if(it!=e[u].end()){
            v3[u]+=(it++)->F;
            if(it!=e[u].end()){
                v3[u]+=it->F;
            }else v3[u]=INF;
        }else v3[u]=INF;
    }else v3[u]=INF;
    cost3.insert(v3[u]);
}
void remove_edge(int u, int v){
    cost4.erase(MP(ew[{u,v}],MP(u,v)));
    remove(u, v);
    remove(v, u);
}
const int AA = 3;
// u is in the prev 3 number in e[v]
bool good(int v, int u){
    auto it=e[v].begin();
    REP(i,AA){
        if(it==e[v].end())return 0;
        if(it->S==u)return 1;
        it++;
    }
    return 0;
}
void add_cost4(int u, int v){
    if(u>v)swap(u,v);
    cost4.insert(MP(ew[{u,v}],MP(u,v)));
}
void recalc(int u){
    auto it=e[u].begin();
    REP(i,AA){
        if(it==e[u].end())break;
        int v=it->S;
        if(good(v,u)){
            add_cost4(v,u);
        }
        it++;
    }
    if(it!=e[u].end()){
        int v=it->S;
        if(u>v)swap(u,v);
        cost4.erase(MP(ew[{u,v}],MP(u,v)));
    }
}
void recalc(int u, int v){
    recalc(u);
    recalc(v);
}
pair<int,PII> tmp[SIZE];
inline bool valid(PII &x, PII &y){
    return x.F!=y.F&&x.F!=y.S&&x.S!=y.F&&x.S!=y.S;
}
void print(){
    LL an=INF;
    if(!cost3.empty())an=*cost3.begin();
    int tn=0;
    bool done=0;
    for(auto it=cost4.begin();it!=cost4.end()&&!done;){
        tmp[tn]=*it;
        if(tmp[tn].F != ew[tmp[tn].S]) {
            it++;
            cost4.erase(prev(it));
            continue;
        }
        REP(j,tn){
            if(valid(tmp[tn].S,tmp[j].S)){
                an=min(an,(LL)tmp[tn].F+tmp[j].F);
                if(!j){
                    done=1;
                    break;
                }
            }
        }
        tn++;
        it++;
    }
    W(an);
}
void solve() {
    R(n,m);
    init();
    REP(i,m){
        int u,v,w;
        R(u,v,w);
        add_edge(u,v,w);
        recalc(u,v);
    }
    print();
    int q;
    R(q);
    while(q--){
        int ty,u,v;
        R(ty,u,v);
        if(ty==1){
            int w;
            R(w);
            add_edge(u,v,w);
            recalc(u,v);
        }else{
            remove_edge(u,v);
            recalc(u,v);
        }
        print();
    }
}
int main(){
    solve();
    return 0;
}