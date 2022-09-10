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

int BIT[2][SIZE];
int A[SIZE],B[SIZE];
void ins(int bit[],int x,int v){
    for(;x<SIZE;x+=x&-x)bit[x]+=v;
}
int qq(int bit[],int x){
    int res=0;
    for(;x;x-=x&-x)res+=bit[x];
    return res;
}
int main(){
    DRII(n,k);
    DRIII(a,b,q);
    while(q--){
        DRI(ty);
        if(ty==1){
            DRII(day,v);
            int nv=min(A[day]+v,b)-A[day];
            A[day]+=nv;
            ins(BIT[0],day,nv);

            nv=min(B[day]+v,a)-B[day];
            B[day]+=nv;
            ins(BIT[1],SIZE-day,nv);
        }
        else{
            DRI(p);
            printf("%d\n",qq(BIT[0],p-1)+qq(BIT[1],SIZE-(p+k)));
        }
    }
    return 0;
}