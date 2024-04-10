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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e7+10;
int p[SIZE];
int cnt[SIZE];
vector<int>pp;
LL an;
void prime_init(int n){
    for(int i=2;i<=n;i++){
        if(!p[i]){
            pp.PB(i);
            for(int j=i;j<=n;j+=i){
                if(!p[j]){
                    p[j]=i;
                    cnt[p[j]]++;
                }
            }
        }
    }
}
bool is_prime(int x){
    return p[x]==x;
}
LL dp[SIZE];
int main(){
    DRI(n);
    if(n<=3)return 0*puts("0");
    an=(n-1LL)*(n-2)*3;
    prime_init(n);
    {
        LL cc=0;
        REP(i,SZ(pp)){
            if(pp[i]*2>n){
                cc++;
            }
        }
        an-=(cc*(cc-1)+cc*(n-1-cc)*2)*3;
    }
    REP(i,SZ(pp)){
        for(int j=0;j<i&&pp[i]*pp[j]<=n;j++){
            an-=(LL)(cnt[pp[i]])*cnt[pp[j]]*2;
        }
        an-=(LL)(cnt[pp[i]]-1)*cnt[pp[i]];
    }
    for(int i=n;i>1;i--){
        dp[i]=(LL)(n/i)*(n/i-1);
        for(int j=i+i;j<=n;j+=i){
            dp[i]-=dp[j];
        }
        an-=dp[i];
    }
    cout<<an/2<<endl;
    return 0;
}