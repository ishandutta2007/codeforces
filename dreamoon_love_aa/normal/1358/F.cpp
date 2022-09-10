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
const LL INF = 10000LL * 10000 * 10000 + 1;
LL C(LL x,LL y){
    if(y<0||y>x)return 0;
    if(y*2>x)y=x-y;
    LL ret=1;
    FOR(i,1,y){
        ret*=(x-y+i);
        ret/=i;
        if(ret>INF)return INF;
    }
    return ret;
}
const int REVERSE = 0;
const LL REPLACE_SUM = 1;
void print(LL need,string base,VPLL& steps){
    if(need > 200 * 1000) {
        W("BIG");
        W(need);
    }
    else {
        W("SMALL");
        reverse(ALL(steps));
        REP(i,SZ(steps)){
            if(steps[i].F==REVERSE)base+='R';
            else{
                base+=string(steps[i].S,'P');
            }
        }
        W(SZ(base));
        W(base);
    }
    exit(0);
}
LL mul(LL x,LL y){
    if(!x||!y)return 0;
    if(x>INF/y)return INF;
    return x*y;
}
void check(const VL& A, VL B,string base){
    LL need=0;
    VPLL steps;
    while(1){
        if(B[0]==A[0]){
            if(A==B){
                print(need,base,steps);
            }
        }
        if(B.back()==A[0]){
            bool err=0;
            REP(i,SZ(A)){
                if(A[i]!=B[SZ(B)-1-i]){
                    err=1;
                    break;
                }
            }
            if(!err){
                steps.PB(REVERSE,0LL);
                print(need,base,steps);
            }
        }
        if(B.back()==B[0]){
            return;
        }
        if(B.back()<B[0]){
            steps.PB(REVERSE,0LL);
            reverse(ALL(B));
        }
        if(B.back()<=A.back())return;
        LL bb=1;
        if(A[0]==B[0])bb=A.back();
        if(SZ(B)<=30){
            LL ll=0,rr=(B.back()-1)/B[0];
            while(ll<rr){
                LL mm=(ll+rr+1)/2;
                VL tmp=B;
                bool err=0;
                REPP(j,1,SZ(tmp)){
                    REP(i,j){
                        tmp[j]-=mul(tmp[i],C(j-i+mm-1,mm-1));
                        if(tmp[j]<=0){
                            err=1;
                            break;
                        }
                    }
                    if(err)break;
                }
                if(err||tmp.back()<bb)rr=mm-1;
                else ll=mm;
            }
            if(!ll)return;
            need+=ll;
            steps.PB(REPLACE_SUM,ll);
            REPP(j,1,SZ(B)){
                REP(i,j){
                    B[j]-=mul(B[i],C(j-i+ll-1,ll-1));
                    if(B[j]<=0)return;
                }
            }
        }
        else{
            need++;
            steps.PB(REPLACE_SUM,1LL);
            for(int i=SZ(B)-1;i>0;i--){
                B[i]-=B[i-1];
                if(B[i]<=0)return;
            }
            if(B.back()<bb)return;
        }
    }
}
int main(){
    int n;
    R(n);
    VL A(n),B(n);
    REP(i,n)R(A[i]);
    REP(i,n)R(B[i]);
    if(n==1){
        if(A[0]==B[0]){
            W("SMALL");
            W(0);
            W("");
        }
        else{
            W("IMPOSSIBLE");
        }
        return 0;
    }
    check(A,B,"");
    reverse(ALL(A));
    check(A,B,"R");
    W("IMPOSSIBLE");
    return 0;
}