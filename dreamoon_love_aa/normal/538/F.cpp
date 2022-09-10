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
const int SIZE = 2e5+10;
int BIT[SIZE];
void ins(int x){
    for(;x<SIZE;x+=x&-x)BIT[x]++;
}
int qq(int x){
    int res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res;
}
int an[SIZE],a[SIZE];
VPII Q[SIZE];
int d[SIZE],dn;
int main(){
    DRI(n);
    REP(i,n){
        RI(a[i+1]);
        d[i]=a[i+1];
        if(i&&a[i+1]<a[i])an[1]++;
    }
    sort(d,d+n);
    dn=unique(d,d+n)-d;
    REPP(i,1,n+1)a[i]=(lower_bound(d,d+dn,a[i])-d)+1;
    REPP(i,2,n){
        int now=1;
        int it=2;
        while(it<=n){
            Q[min(it+i-1,n)].PB(MP(now,i));
            Q[it-1].PB(MP(-now,i));
            it+=i;
            now++;
        }
    }
    REPP(i,1,n+1){
        ins(a[i]);
        REP(j,SZ(Q[i])){
            int x=Q[i][j].F;
            int v=a[abs(x)];
            int id=Q[i][j].S;
            if(x<0)an[id]-=qq(v-1);
            else an[id]+=qq(v-1);
        }
    }
    REPP(i,1,n){
        if(i!=1)printf(" ");
        printf("%d",an[i]);
    }
    return 0;
}