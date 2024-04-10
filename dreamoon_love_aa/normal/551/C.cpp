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
int b[SIZE];
int main(){
    DRII(n,m);
    REP(i,n)RI(a[i]);
    LL ll=1,rr=1e15;
    while(ll<rr){
        LL mm=(ll+rr)>>1;
        int need=0;
        memcpy(b,a,sizeof(int)*n);
        int it=n-1;
        while(it>=0){
            if(b[it]){
                need++;
                if(it+2>mm){
                    need=m+1;
                    break;
                }
                LL now=mm-(it+1);
                while(it>=0&&now>0){
                    LL r=min((LL)b[it],now);
                    b[it]-=r;
                    now-=r;
                    if(b[it]==0)it--;
                }
            }
            else it--;
        }
        if(need>m)ll=mm+1;
        else rr=mm;
    }
    cout<<ll<<endl;
    return 0;
}