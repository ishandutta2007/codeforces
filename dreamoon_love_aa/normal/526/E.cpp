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
const int SIZE = 2e6+10;
int a[SIZE];
int num[SIZE],nxt[SIZE];
int main(){
    DRII(n,q);
    REP(i,n){
        RI(a[i]);
        a[i+n]=a[i];
    }
    for(int tt=1;tt<=q;tt++){
        LL b;
        scanf("%I64d",&b);
        int rr=-1;
        LL now=0;
        REP(i,n){
            while(rr+1<2*n&&now+a[rr+1]<=b)now+=a[++rr];
            nxt[i]=rr+1;
            num[i]=1;
            now-=a[i];
        }
        int an=n;
        for(int i=n-1;i>=0;i--){
            if(nxt[i]<n){
                num[i]+=num[nxt[i]];
                nxt[i]=nxt[nxt[i]];
            }
            if(nxt[i]>=i+n)an=min(an,num[i]);
        }
        printf("%d\n",an);
    }
    return 0;
}