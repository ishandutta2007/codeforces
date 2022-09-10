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
const int SIZE = 1e6+10;
// template end here
int a[SIZE];
int main(){
    DRI(n);
    REP(i,n){
        RI(a[i]);
    }
    int now=a[0];
    while(now%2==0)now>>=1;
    REPP(i,1,n){
        int me=a[i];
        while(me!=now){
            if(me>now)me>>=1;
            else now>>=1;
        }
    }
    LL an=0;
    map<LL,int>H;
    REP(i,20)H[(LL)now<<i]=i;
    vector<int>d;
    REP(i,n){
        int me=a[i];
        while(!H.count(me)){
            me>>=1;
            an++;
        }
        d.PB(H[me]);
    }
    sort(ALL(d));
    for(int i=0;i<SZ(d)-1-i;i++)an+=d[SZ(d)-1-i]-d[i];
    cout<<an<<endl;
    return 0;
}