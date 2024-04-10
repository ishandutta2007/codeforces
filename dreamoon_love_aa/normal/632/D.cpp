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
int cnt[SIZE],a[SIZE];
int main(){
    DRII(n,m);
    REP(i,n){
        RI(a[i]);
        if(a[i]<=m)cnt[a[i]]++;
    }
    for(int i=m/2;i>0;i--){
        for(int j=i+i;j<=m;j+=i)cnt[j]+=cnt[i];
    }
    int ma=0,id=1;
    for(int i=m;i>0;i--){
        if(cnt[i]>=ma){
            ma=cnt[i];
            id=i;
        }
    }
    printf("%d %d\n",id,ma);
    REP(i,n)
        if(id%a[i]==0)printf("%d ",i+1);
    return 0;
}