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

const int SIZE = 1<<20;
struct Data{
    string s,head,tail;
    LL v;
    Data(string _s="",string _head="",string _tail="",LL _v=0):s(_s),head(_head),tail(_tail),v(_v){
        if(SZ(s)>=4){
            head=s.substr(0,3);
            tail=s.substr(SZ(s)-3);
            for(int i=0;i+4<=SZ(s);i++){
                if(s.substr(i,4)=="haha")v++;
            }
            s="";
        }
    }
    Data operator+(const Data& b)const{
        if(s!=""&&b.s!=""){
            return Data(s+b.s);
        }else{
            Data ret;
            if(s==""){
                ret.head=head;
            }else{
                ret.head=(s+b.head).substr(0,3);
            }
            if(b.s==""){
                ret.tail=b.tail;
            }else{
                ret.tail=(tail+b.s).substr(SZ(tail)+SZ(b.s)-3);
            }
            ret.v=v+b.v;
            string tmp;
            if(s!="")tmp=s;
            else tmp=tail;
            if(b.s!="")tmp+=b.s;
            else tmp+=b.head;
            for(int i=0;i+4<=SZ(tmp);i++){
                if(tmp.substr(i,4)=="haha")ret.v++;
            }
            return ret;
        }
    }
}d[50];
int id;
int get(map<string,int>&to,string s){
    //DEBUG("add",s);
    if(to.count(s)){return to[s];}
    return to[s]=id++;
}
void solve() {
    id=0;
    int n;
    R(n);
    map<string,int>to;
    REP(i,n){
        string name,eq;
        R(name,eq);
        int me=get(to,name);
        if(eq==":="){
            //DEBUG("here");
            string tmp;
            R(tmp);
            d[me]=Data(tmp);
        }else{
            string v1,add,v2;
            R(v1,add,v2);
            d[me]=d[get(to,v1)]+d[get(to,v2)];
        }
        if(i==n-1){
            W(d[me].v);
        }
    }
}
int main(){
    CASET {
        solve();
    }
    return 0;
}