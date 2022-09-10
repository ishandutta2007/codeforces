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
string bfs[SIZE];
int v[SIZE];
#include<unordered_set>
unordered_set<LL>AA;
bool add(string s){
    int first2=1;
    for(int i=SZ(s)-1;i>=0;i--){
        if(s[i]=='2'||s[i]=='7'){
            if(first2)s[i]='2',first2=0;
            else s[i]='1';
        }
        else if(s[i]!='0'&&s[i]!='5')s[i]='1';
    }
    if(AA.count(atoll(s.c_str())))return 0;
    AA.insert(atoll(s.c_str()));
    return 1;
}
bool is25(const string &s){
    if(SZ(s)==1)return 0;
    if(s.back()=='5'){
        char c=s[SZ(s)-2];
        return c=='2'||c=='7';
    }
    else if(s.back()=='0'){
        char c=s[SZ(s)-2];
        return c=='0'||c=='5';
    }
    return 0;
}
int main()  {
    string s;
    R(s);
    add(s);
    bfs[0]=s;
    int rr=1;
    REP(i,rr){
        if(is25(bfs[i])){
            W(v[i]);
            return 0;
        }
        string now=bfs[i];
        REPP(j,1,SZ(now)){
            swap(now[j],now[j-1]);
            if(now[0]!='0'&&add(now)){
                v[rr]=v[i]+1;
                bfs[rr++]=now;
            }
            swap(now[j],now[j-1]);
        }
    }
    W(-1);
    return 0;
}