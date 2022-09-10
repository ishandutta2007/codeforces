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
const int SIZE = 1e6+10;
void ADD(LL& x,LL v){
    x=(x+v)%MOD;
    if(x<0)x+=MOD;
}
LL d[SIZE],num[SIZE],two[SIZE];
int main(){
    two[0]=1;
    REPP(i,1,SIZE)two[i]=two[i-1]*2%MOD;
    DRI(n);
    REP(i,n){
        DRI(x);
        d[x]++;
    }
    LL an=0;
    for(int i=SIZE-1;i>1;i--){
        int cnt=0;
        for(int j=i;j<SIZE;j+=i){
            ADD(num[i],-num[j]);
            cnt+=d[j];
        }
        if(cnt)ADD(num[i],cnt*two[cnt-1]);
        ADD(an,num[i]*i);
    }
    cout<<an;
    return 0;
}