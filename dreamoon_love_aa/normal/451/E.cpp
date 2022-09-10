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
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
LL inv[25];
LL a[26];
LL mypow(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1){
            res=res*x%MOD;
        }
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
LL C(LL n,int x){
    LL res=1;
    REP(i,x){
        res*=(n-i)%MOD;
        res%=MOD;
        res*=inv[i+1];
        res%=MOD;
    }
    return res;
}
LL an;
void dfs(int id,int n,int ng,LL m){
    if(m<0)return ;
    if(id==n){
        an+=C(m+n-1,n-1)*ng;
        return;
    }
    dfs(id+1,n,ng,m);
    dfs(id+1,n,-ng,m-a[id]-1);
}
int main(){
    REPP(i,1,25){
        inv[i]=mypow(i,MOD-2);
    }
    int n;
    LL s;
    cin>>n>>s;
    REP(i,n)cin>>a[i];
    dfs(0,n,1,s);
    an%=MOD;
    if(an<0)an+=MOD;
    cout<<an<<endl;
    return 0;
}