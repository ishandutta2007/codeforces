#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int MOD2 = 1e9+9;
const int SIZE = 1e6+10;
char s[SIZE];
VPII pp[SIZE];
int n,m;
bool get(int l,PII X){
    if(X.F<0)X.F+=MOD;
    if(X.S<0)X.S+=MOD2;
    return binary_search(ALL(pp[l]),X);
}
int main(){
    RII(n,m);
    REP(i,n){
        RS(s);
        int l=LEN(s);
        LL v1=0,v2=0;
        REP(j,l){
            v1*=3;
            v2*=3;
            v1+=s[j]-'a';
            v2+=s[j]-'a';
            v1%=MOD;
            v2%=MOD2;
        }
        pp[l].PB(MP(v1,v2));
    }
    REP(i,SIZE)sort(ALL(pp[i]));
    REP(k,m){
        RS(s);
        int l=LEN(s);
        LL v1=0;
        LL v2=0;
        REP(j,l){
            v1*=3;
            v2*=3;
            v1+=s[j]-'a';
            v2+=s[j]-'a';
            v1%=MOD;
            v2%=MOD2;
        }
        LL t1=1,t2=1;
        bool suc=0;
        for(int i=l-1;i>=0;i--){
            if(s[i]=='a'){
                if(get(l,MP((v1+t1)%MOD,(v2+t2)%MOD2))
                 ||get(l,MP((v1+t1*2)%MOD,(v2+t2*2)%MOD2))){
                    suc=1;
                    break;
                }
            }
            else if(s[i]=='b'){
                if(get(l,MP((v1+t1)%MOD,(v2+t2)%MOD2))
                 ||get(l,MP((v1-t1)%MOD,(v2-t2)%MOD2))){
                    suc=1;
                    break;
                }
            }
            else{
                if(get(l,MP((v1-2*t1)%MOD,(v2-2*t2)%MOD2))
                 ||get(l,MP((v1-t1)%MOD,(v2-t2)%MOD2))){
                    suc=1;
                    break;
                }
            }
            t1=t1*3%MOD;
            t2=t2*3%MOD2;
        }
        if(!suc)puts("NO");
        else puts("YES");
    }
    return 0;
}