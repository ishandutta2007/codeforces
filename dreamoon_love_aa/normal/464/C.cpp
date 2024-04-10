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
string str[100010];
LL res[10],len[10];
LL mypow(LL x,LL y){
    LL res=1;
    while(y){
        if(y&1)res=res*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return res;
}
char s[100010];
int main(){
    RS(s);
    DRI(N);
    REP(i,N){
        cin>>str[i];
    }
    REP(i,10){
        res[i]=i;
        len[i]=1;
    }
    for(int i=N-1;i>=0;i--){
        int m=SZ(str[i])-3;
        int me=str[i][0]-'0';
        LL me_len=0;
        LL me_res=0;
        REP(j,m){
            int now=str[i][j+3]-'0';
            me_len+=len[now];
            me_res=me_res*mypow(10,len[now])%MOD;
            me_res=(me_res+res[now])%MOD;
        }
        me_res%=MOD;
        me_len%=MOD-1;
        res[me]=me_res;
        len[me]=me_len;
    }
    LL me_len=0;
    LL me_res=0;
    for(int i=0;s[i];i++){
        int now=s[i]-'0';
        me_len+=len[now];
        me_res=me_res*mypow(10,len[now])%MOD;
        me_res=(me_res+res[now])%MOD;
    }
    cout<<me_res<<endl;
    return 0;
}