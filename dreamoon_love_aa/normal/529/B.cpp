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
const int SIZE = 1e5+10;
int d[SIZE],w[SIZE],h[SIZE];
int main(){
    DRI(n);
    int st=0;
    REP(i,n){
        RII(w[i],h[i]);
        st=max(st,min(w[i],h[i]));
    }
    int an=2e9;
    REPP(H,st,1001){
        int ww=0;
        int lie=0;
        int dn=0;
        REP(i,n){
            if(w[i]>H){
                ww+=w[i];
            }
            else if(h[i]>H){
                ww+=h[i];
                lie++;
            }
            else{
                ww+=w[i];
                d[dn++]=h[i]-w[i];
            }
        }
        if(lie*2>n)continue;
        sort(d,d+dn);
        int j=0;
        while(j<dn&&(lie+1)*2<=n){
            if(d[j]<0)ww+=d[j],lie++;
            else break;
            j++;
        }
        an=min(an,ww*H);
    }
    printf("%d\n",an);
    return 0;
}