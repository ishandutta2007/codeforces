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
int a[SIZE];
LL dp[SIZE];
int n,A,B;
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int my_gcd(int x,int y){
    if(!x||!y)return x+y;
    return __gcd(x,y);
}
LL an;
void solve(int p,int n){
    dp[0]=0;
    LL now=0;
    bool suc=1;
    REPP(i,1,n+1){
        dp[i]=dp[i-1];
        if(suc){
            if(a[i]%p==0)now-=A;
            else if((a[i]-1)%p==0||(a[i]+1)%p==0)now+=B-A;
            else suc=0;
            if(suc)mii(dp[i],now);
        }
        //printf("dp[%d]=%I64d\n",i,dp[i]);
        mii(an,A*(LL)n+dp[i]);
    }
    now=0;
    for(int i=n;i>1;i--){
        if(a[i]%p==0)now-=A;
        else if((a[i]-1)%p==0||(a[i]+1)%p==0)now+=B-A;
        else break;
        mii(an,dp[i-1]+now+A*(LL)n);
    }
}
int main(){
    RIII(n,A,B);
    an=(n-1LL)*A;
    REP(i,n){
        RI(a[i+1]);
    }
    VI pp;
    {
        REPP(k,-1,2){
            int tmp=a[1]+k;
            for(int i=2;i*i<=tmp;i++){
                if(tmp%i==0){
                    while(tmp%i==0)tmp/=i;
                    pp.PB(i);
                }
            }
            if(tmp!=1){
                pp.PB(tmp);
            }
        }
    }
    {
        REPP(k,-1,2){
            int tmp=a[n]+k;
            for(int i=2;i*i<=tmp;i++){
                if(tmp%i==0){
                    while(tmp%i==0)tmp/=i;
                    pp.PB(i);
                }
            }
            if(tmp!=1){
                pp.PB(tmp);
            }
        }
    }
    sort(ALL(pp));
    pp.resize(unique(ALL(pp))-pp.begin());
    REP(k,SZ(pp)){
        int p=pp[k];
        solve(p,n);
    }
    cout<<an;
    return 0;
}