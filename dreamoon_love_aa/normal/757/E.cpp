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
const int SIZE = 1000001;

int p[SIZE],dp[SIZE],to[SIZE];
VI pp,sp;
void ADD(int &x,LL v){
    x=(x+v)%MOD;
}
void prime_init(){
    REPP(i,1,SIZE)dp[i]=1;
    REPP(i,2,SIZE){
        if(!p[i]){
            pp.PB(i);
            for(int j=i;j<SIZE;j+=i){
                ADD(dp[j],dp[j]);
                if(!p[j])p[j]=i;
            }
        }
    }
    REPP(i,1,SIZE){
        int now=i;
        VI tmp;
        while(now!=1){
            int v=p[now];
            int cnt=0;
            while(p[now]==v){
                now/=v;
                cnt++;
            }
            tmp.PB(cnt);
        }
        sort(ALL(tmp),greater<int>());
        to[i]=1;
        REP(j,SZ(tmp)){
            REP(k,tmp[j])to[i]*=pp[j];
        }
        if(i!=1&&to[i]==i)sp.PB(i);
    }
}
int tt[SIZE][20];
int main(){
    prime_init();
    tt[1][0]=1;
    REPP(i,1,20)tt[1][i]=2;
    REPP(i,2,SIZE){
        tt[i][0]=1;
        REPP(j,1,20){
            tt[i][j]=tt[i][j-1];
            ADD(tt[i][j],tt[i-1][j]);
        }
    }
    REP(i,SIZE){
        REPP(j,1,20)ADD(tt[i][j],tt[i][j-1]);
    }
    DRI(Q);
    while(Q--){
        DRII(x,y);
        if(!x){
            int an=1;
            while(y!=1){
                int v=p[y];
                while(y%v==0)y/=v;
                an=an*2%MOD;
            }
            printf("%d\n",an);
        }
        else{
            int an=1;
            while(y!=1){
                int v=p[y];
                int cnt=0;
                while(y%v==0)y/=v,cnt++;
                an=an*(LL)tt[x][cnt]%MOD;
            }
            printf("%d\n",an);
        }
    }
    return 0;
}