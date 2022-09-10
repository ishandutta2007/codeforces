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
const int SIZE = 2e6+10;
char s[SIZE],tmp[SIZE];
int r[SIZE];
int used[SIZE],tt;
int mul1,mul2,sub1,sub2;
map<PII,int>H;
int main(){
    MS1(r);
    srand(time(NULL));
    mul1=131;
    mul2=((rand()&1023)+128);
    DRII(N,K);
    sub1=sub2=1;
    REPP(i,1,K){
        sub1=(LL)sub1*mul1%MOD;
        sub2=(LL)sub2*mul2%MOD;
    }
    RS(s);
    REP(i,N*K)s[i+N*K]=s[i];
    DRI(G);
    REP(i,G){
        RS(tmp);
        int v1=0,v2=0;
        REP(j,K){
            v1=((LL)v1*mul1+tmp[j])%MOD;
            v2=((LL)v2*mul2+tmp[j])%MOD;            
        }
        H[MP(v1,v2)]=i+1;
    }
    int v1=0,v2=0;

    REP(i,N*K+K-1){
        v1=((LL)v1*mul1+s[i])%MOD;
        v2=((LL)v2*mul2+s[i])%MOD;
        if(i>=K-1){
            if(H.count(MP(v1,v2))){
                r[i-K+1]=H[MP(v1,v2)];
            }
            v1-=s[i-K+1]*(LL)sub1%MOD;
            if(v1<0)v1+=MOD;
            v2-=s[i-K+1]*(LL)sub2%MOD;
            if(v2<0)v2+=MOD;
        }
    }
    REP(i,K){
        tt++;
        bool suc=1;
        REP(j,N){
            if(r[i+j*K]==-1){suc=0;break;}
            if(used[r[i+j*K]]==tt){suc=0;break;}
            used[r[i+j*K]]=tt;
        }
        if(suc){
            puts("YES");
            REP(j,N){
                if(j)printf(" ");
                printf("%d",r[i+j*K]);
            }
            puts("");
            return 0;
        }
    }
    puts("NO");
    return 0;
}