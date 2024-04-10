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
#define PB push_back
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
void _R(LL &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const LL &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }
void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
#ifdef HOME
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 150010;
bool is_leaf[SIZE];
int par[SIZE];
int c[SIZE],lv[SIZE];
int cnt[SIZE];
int AA[SIZE][3][26];
int at_least[SIZE];
int from[SIZE],from_order[SIZE];
int n,q; 
bool same_lv(){
    int v=-1;
    REP(i,n){
        if(is_leaf[i]){
            if(v==-1)v=lv[i];
            else if(v!=lv[i])return 0;
        }
    }
    return 1;
}
int fail_cnt;

void push_sub(int id,int order,int v){
    int pre=AA[id][2][v];
    AA[id][order][v]--;
    AA[id][2][v]=max(AA[id][0][v],AA[id][1][v]);
    if(AA[id][2][v]==pre)return;
    at_least[id]--;
    if(at_least[id]==lv[n-1]-lv[id]){
        fail_cnt--;
    }
    if(id){
        push_sub(from[id],from_order[id],v);
    }
}
void push(int id,int order,int v){
    int pre=AA[id][2][v];
    AA[id][order][v]++;
    AA[id][2][v]=max(AA[id][0][v],AA[id][1][v]);
    if(AA[id][2][v]==pre)return;
    at_least[id]++;
    if(at_least[id]==lv[n-1]-lv[id]+1){
        fail_cnt++;
    }
    if(id){
        push(from[id],from_order[id],v);
    }
}
void update(int id,int v){
    if(c[id]==v)return;
    if(c[id]!=-1){
        push_sub(from[id],from_order[id],c[id]);
        c[id]=-1;
    }
    if(v!=-1){
        push(from[id],from_order[id],v);
        c[id]=v;
    }
}
int main(){
    R(n,q);
    REP(i,n)is_leaf[i]=1;
    REPP(i,1,n){
        string cc;
        int x;
        R(x,cc);
        x--;
        from_order[i]=cnt[x];
        par[i]=x;
        cnt[x]++;
        lv[i]=lv[x]+1;
        is_leaf[x]=0;
        if(cc[0]=='?')c[i]=-1;
        else c[i]=cc[0]-'a';
    }
    FOR(i,1,n-1){
        if(cnt[par[i]]==2)from[i]=par[i];
        else {
            from[i]=from[par[i]];
            from_order[i]=from_order[par[i]];
        }
    }
    if(!same_lv()){
        REP(i,q){
            W("Fou");
        }
        return 0;
    }
    cnt[0]=2;
    for(int i=n-1;i>=0;i--){
        if(cnt[i]==2){
            REP(j,26){
                AA[i][2][j]=max(AA[i][0][j],AA[i][1][j]);
                at_least[i]+=AA[i][2][j];
            }
            if(at_least[i]>lv[n-1]-lv[i]){
                fail_cnt++;
            }
            if(i){
                int lt=from[i];
                int lt_order=from_order[i];
                REP(j,26){
                    AA[lt][lt_order][j]+=AA[i][2][j];
                }
            }
        }
        if(!i)break;
        if(c[i]!=-1){
            int lt=from[i];
            int lt_order=from_order[i];
            AA[lt][lt_order][c[i]]++;
        }
    }
    /*
    REP(i,n){
        if(cnt[i]==2){
            W(i,":");
            REP(j,3)W(VI(AA[i][j],AA[i][j]+26));
        }
    }
    */
    while(q--){
        int x;
        string cc;
        R(x,cc);
        x--;
        if(cc[0]=='?')update(x,-1);
        else update(x,cc[0]-'a');
        /*
        REP(i,n){
            if(cnt[i]==2){
                W(i,":");
                REP(j,3)W(VI(AA[i][j],AA[i][j]+26));
            }
        }
        */
        if(fail_cnt){
            W("Fou");
        }
        else{
            LL an=0;
            REP(i,26){
                //_W((AA[0][2][i]+lv[n-1]-at_least[i]));
                //_W(",");
                an+=(AA[0][2][i]+lv[n-1]-at_least[0])*(i+1);
            }
            //W("");
            W("Shi",an);
        }
    }
    return 0;
}