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
const int SIZE = 1e6+10;
int x[SIZE],y[SIZE];
char s[SIZE];
void YES(){
    puts("YES");
    exit(0);
}
int main(){
    DRI(n);
    RII(x[0],y[0]);
    REPP(i,1,n+1){
        RS(s+i);
        RII(x[i],y[i]);
    }
    char rc=' ',lc=' ';
    int ll=-MOD,rr=MOD;
    REPP(i,1,n+1){
        if(y[i]==y[0]){
            if(x[i]>x[0]&&x[i]<rr){
                rc=s[i];
                rr=x[i];
            }
            if(x[i]<x[0]&&x[i]>ll){
                lc=s[i];
                ll=x[i];
            }
        }
    }
    if(rc=='R'||rc=='Q'||lc=='R'||lc=='Q')YES();
    
    rc=' ',lc=' ';
    ll=-MOD,rr=MOD;
    REPP(i,1,n+1){
        if(x[i]==x[0]){
            if(y[i]>y[0]&&y[i]<rr){
                rc=s[i];
                rr=y[i];
            }
            if(y[i]<y[0]&&y[i]>ll){
                lc=s[i];
                ll=y[i];
            }
        }
    }
    if(rc=='R'||rc=='Q'||lc=='R'||lc=='Q')YES();

    lc=rc=' ';
    ll=-MOD,rr=MOD;
    REPP(i,1,n+1){
        if(x[i]+y[i]==x[0]+y[0]){
            if(y[i]>y[0]&&y[i]<rr){
                rc=s[i];
                rr=y[i];
            }
            if(y[i]<y[0]&&y[i]>ll){
                lc=s[i];
                ll=y[i];
            }
        }
    }
    if(rc=='Q'||rc=='B'||lc=='Q'||lc=='B')YES();

    lc=rc=' ';
    ll=-MOD,rr=MOD;
    REPP(i,1,n+1){
        if(x[i]-y[i]==x[0]-y[0]){
            if(y[i]>y[0]&&y[i]<rr){
                rc=s[i];
                rr=y[i];
            }
            if(y[i]<y[0]&&y[i]>ll){
                lc=s[i];
                ll=y[i];
            }
        }
    }
    if(rc=='Q'||rc=='B'||lc=='Q'||lc=='B')YES();
    return 0*puts("NO");
}