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
const int SIZE = 1e6+10;
string ask(VPII &AA){
    W("Q",SZ(AA),AA);
    fflush(stdout);
    string res;
    R(res);
    return res;
}
void final_answer(vector<VI>&answer){
    W("A",SZ(answer[0]),SZ(answer[1]),SZ(answer[2]));
    REP(i,3)W(answer[i]);
    fflush(stdout);
}
bool same[SIZE],same2[SIZE];
int u[SIZE],tt;
int record[SIZE];
int main(){
    CASET{
        int n; R(n);
        {
            VPII AA;
            for(int i=1;i<n;i+=2){
                AA.PB({i,i+1});
            }
            if(SZ(AA)){
                string res=ask(AA);
                for(int i=1;i<n;i+=2){
                    same[i]=(res[i/2]=='1');
                }
            }
        }
        {
            VPII AA;
            for(int i=2;i<n;i+=2){
                AA.PB({i,i+1});
            }
            if(SZ(AA)){
                string res=ask(AA);
                for(int i=2;i<n;i+=2){
                    same[i]=(res[i/2-1]=='1');
                }
            }
        }
        VPII range;
        for(int i=1,j;i<=n;i=j+1){
            for(j=i;j<n&&same[j];j++);
            range.PB({i,j});
        }
        {
            tt++;
            VPII AA;
            REP(i,SZ(range)){
                if(i+2>=SZ(range))break;
                if(u[range[i].F]==tt)continue;
                AA.PB({range[i].F,range[i+2].F});
                u[range[i].F]=u[range[i+2].F]=tt;
            }
            if(SZ(AA)){
                string res=ask(AA);
                REP(i,SZ(AA)){
                    same2[AA[i].S]=(res[i]=='1');
                }
            }
        }
        {
            tt++;
            VPII AA;
            REPP(i,2,SZ(range)){
                if(i+2>=SZ(range))break;
                if(u[range[i].F]==tt)continue;
                AA.PB({range[i].F,range[i+2].F});
                u[range[i].F]=u[range[i+2].F]=tt;
            }
            if(SZ(AA)){
                string res=ask(AA);
                REP(i,SZ(AA)){
                    same2[AA[i].S]=(res[i]=='1');
                }
            }
        }
        vector<VI> answer(3);
        if(SZ(range)==1){
            FOR(i,1,n)answer[0].PB(i);
        }
        else{
            FOR(i,range[0].F,range[0].S){
                record[i]=0;
                answer[0].PB(i);
            }
            FOR(i,range[1].F,range[1].S){
                record[i]=1;
                answer[1].PB(i);
            }
            REPP(i,2,SZ(range)){
                int v=record[range[i-2].F];
                if(!same2[range[i].F])v=3-record[range[i-2].F]-record[range[i-1].F];
                FOR(j,range[i].F,range[i].S){
                    record[j]=v;
                    answer[v].PB(j);
                }
            }
        }
        final_answer(answer);
    }
    return 0;
}