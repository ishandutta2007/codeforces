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
int d[301],dis[301][310],A[31][310][310],a[31][310];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int main(){
    DRII(n,T);
    REP(i,n){
        RI(d[i]);
        d[i]--;
    }
    REP(i,n){
        REP(j,d[i]+1){
            int ma=0;
            REPP(k,j,d[i]+1)ma=max(ma,dis[j][k]);
            maa(dis[j][d[i]],ma+1);
        }
    }
    for(int len=1;len<300;len++){
        for(int i=0;i+len<300;i++){
            maa(dis[i][i+len],dis[i][i+len-1]);
            maa(dis[i][i+len],dis[i+1][i+len]);
        }
    }
    REP(i,300)REP(j,300)A[0][i][j]=dis[i][j];
    int now=0;
    while(T){
        if(T&1){
            REP(i,300){
                REPP(j,i,300){
                    maa(a[now+1][j],a[now][i]+A[now][i][j]);
                }
            }
        }
        else REP(i,300)a[now+1][i]=a[now][i];
        REP(i,300)REPP(j,i,300)REPP(k,j,300){
            maa(A[now+1][i][k],A[now][i][j]+A[now][j][k]);
        }
        T>>=1;
        now++;
    }
    int an=0;
    REP(i,300)an=max(an,a[now][i]);
    cout<<an;
    return 0;
}