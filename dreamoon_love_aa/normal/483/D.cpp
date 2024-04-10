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
const int SIZE = 1e5+10;
// template end here
int l[SIZE],r[SIZE],q[SIZE],cc[SIZE][30],an[SIZE];
int lv[17][SIZE];
int qq(int L,int R){
    int i=0;
    while(L+(1<<(i+1))-1<=R)i++;
    return lv[i][L]&lv[i][R-(1<<i)+1];
}
int main(){
    DRII(n,m);
    REP(i,m){
        RIII(l[i],r[i],q[i]);
        REP(j,30){
            cc[l[i]][j]+=(q[i]>>j)&1;
            cc[r[i]+1][j]-=(q[i]>>j)&1;
        }
    }
    REPP(i,1,n+1){
        int me=0;
        REP(j,30){
            cc[i][j]+=cc[i-1][j];
            if(cc[i][j])me|=1<<j;
        }
        an[i]=me;
    }
    REPP(i,1,n+1)lv[0][i]=an[i];
    REPP(i,1,17){
        for(int j=1;j+(1<<i)-1<=n;j++){
            lv[i][j]=lv[i-1][j]&lv[i-1][j+(1<<(i-1))];
        }
    }
    REP(i,m){
        if(qq(l[i],r[i])!=q[i])return 0*puts("NO");
    }
    puts("YES");
    REP(i,n)printf("%d ",an[i+1]);
    return 0;
}