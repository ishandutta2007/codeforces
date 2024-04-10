/*{{{*/
#include <bits/stdc++.h>
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
 #define DEBUG(...) {printf("# ");printf(__VA_ARGS__);puts("");}
#else
 #define DEBUG(...)
#endif
int MOD = 1e9+7;
void ADD(LL& x,LL v){x=(x+v)%MOD;if(x<0)x+=MOD;}
/*}}}*/
const int SIZE = 1e6+10;
PII match(string gg,string target){
    PII ret=MP(0,0);
    map<char,int>cc[2];
    REP(i,4){
        if(gg[i]==target[i])ret.F++;
        else {
            cc[0][gg[i]]++;
            cc[1][target[i]]++;
        }
    }
    for(auto x:cc[1]){
        ret.S+=min(x.S,cc[0][x.F]);
    }
    return ret;
}
vector<string>now;
void init(){
    REP(i,10000){
        string me=to_string(i);
        while(SZ(me)<4)me="0"+me;
        string tmp=me;
        SORT_UNIQUE(tmp);
        if(SZ(tmp)==4)now.PB(me);
    }
}
map<PII,vector<string>>AA;
void build(string gg){
    AA.clear();
    for(auto s:now)
        AA[match(gg,s)].PB(s);
}
void query(string gg){
    build(gg);
    W(gg);
    fflush(stdout);
    PII ret;
    int x,y;
    R(x,y);
    ret=MP(x,y);
    if(x==4){
        exit(0);
    }
    now=AA[ret];
    if(SZ(now)==1){
        W(now[0]);
        fflush(stdout);
        exit(0);
    }
}
int main(){
    init();
    query("1234");
    query("5678");
    query("3580");
    REP(cs,10){
        int mi=10000;
        string id;
        REP(i,10000){
            string me=to_string(i);
            while(SZ(me)<4)me="0"+me;
            string tmp=me;
            SORT_UNIQUE(tmp);
            if(SZ(tmp)!=4)continue;
            build(me);
            int ma=0;
            for(auto &x:AA){
                ma=max(ma,SZ(x.S));
            }
            //W(me,ma);
            if(ma<mi){
                mi=ma;
                id=me;
            }
        }
        query(id);
    }
    return 0;
}