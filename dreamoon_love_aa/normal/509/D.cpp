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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
LL w[111][111];
LL r[111],c[111];
int main(){
    DRII(n,m);
    int x,y,mi=MOD;
    REP(i,n)REP(j,m){
        cin>>w[i][j];
        if(w[i][j]<mi){
            mi=w[i][j];
            x=i;
            y=j;
        }
    }
    REP(i,n)r[i]=w[i][y];
    REP(j,m)c[j]=w[x][j]-w[x][y];
    LL gg=0;
    REP(i,n)REP(j,m){
        if(w[i][j]>r[i]+c[j]){
            puts("NO");
            return 0;
        }
        if(w[i][j]!=r[i]+c[j]){
            if(!gg)gg=r[i]+c[j]-w[i][j];
            else gg=__gcd(r[i]+c[j]-w[i][j],gg);
        }
    }
    if(gg){
        REP(i,n)REP(j,m){
            if(w[i][j]!=(r[i]+c[j])%gg){
                puts("NO");
                return 0;
            }
        }
    }
    else gg=2e9+7;
    puts("YES");
    cout<<gg<<endl;
    REP(i,n){
        if(i)printf(" ");
        cout<<r[i];
    }
    puts("");
    REP(i,m){
        if(i)printf(" ");
        cout<<c[i];
    }
    puts("");
    return 0;
}