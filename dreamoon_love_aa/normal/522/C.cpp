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
// template end here
int a[SIZE];
int cnt[SIZE],x[SIZE],t[SIZE],ma[SIZE];
bool pos[SIZE];
int main(){
    CASET{
        DRII(m,n);
        cnt[0]=0;
        REP(i,n){
            RI(a[i+1]);
            ma[i+1]=0;
            cnt[i+1]=0;
            pos[i+1]=0;
        }
        int need=MOD;
        int sp=0;
        REP(i,m-1){
            RII(x[i],t[i]);
            if(x[i])ma[x[i]]=i;
        }
        REP(k,m-1){
            if(t[k]){
                if(need==MOD){
                    REPP(i,1,n+1){
                        if(ma[i]>=k)continue;
                        if(cnt[0]+cnt[i]>=a[i]){
                            pos[i]=1;
                            need=min(need,a[i]-cnt[i]);
                        }
                    }
                }
                else{
                }
            }
            cnt[x[k]]++;
        }
        if(need==MOD)need=0;
        REPP(i,1,n+1){
            if(pos[i]||cnt[0]-need+cnt[i]>=a[i])putchar('Y');
            else putchar('N');
        }
        puts("");
    }
    return 0;
}