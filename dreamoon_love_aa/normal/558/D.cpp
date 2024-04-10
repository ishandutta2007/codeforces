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
// template end here
LL L[SIZE],R[SIZE];
LL r[SIZE];
int rn;
int dp[2][SIZE];
int ty[SIZE];
int get(LL v){
    return lower_bound(r,r+rn,v)-r;
}
int main(){
    DRII(h,q);
    int cnt=0;
    REP(i,q){
        int lv,ans;
        LL LL,RR;
        cin>>lv>>LL>>RR>>ans;
        RR++;
        while(lv<h){
            lv++;
            LL<<=1;RR<<=1;
        }
        L[i]=LL;
        R[i]=RR;
        ty[i]=ans;
        r[rn++]=L[i];
        r[rn++]=R[i];
        cnt+=ans;
    }
    r[rn++]=1LL<<(h-1);
    r[rn++]=1LL<<h;
    sort(r,r+rn);
    rn=unique(r,r+rn)-r;
    REP(i,q){
        dp[ty[i]][get(L[i])]++;
        dp[ty[i]][get(R[i])]--;
    }
    LL pos=0,st;
    REP(i,rn-1){
        REP(j,2)dp[j][i+1]+=dp[j][i];
        if(dp[1][i]==cnt&&!dp[0][i]){
            pos+=r[i+1]-r[i];
            st=r[i];
        }
    }
    if(pos>1)puts("Data not sufficient!");
    else if(pos==1)printf("%I64d\n",st);
    else puts("Game cheated!");
    return 0;
}