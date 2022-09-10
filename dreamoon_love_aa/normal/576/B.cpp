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
bool used[SIZE],st[SIZE];
vector<int>d[SIZE];
int main(){
    DRI(n);
    REP(i,n)RI(a[i+1]);
    int one=0,two=0;
    REPP(i,1,n+1){
        if(!used[i]){
            used[i]=1;
            st[i]=1;
            d[i].PB(i);
            int me=i;
            while(!used[a[me]]){
                me=a[me];
                used[me]=1;
                d[i].PB(me);
            }
            if(SZ(d[i])==1)one=i;
            else if(SZ(d[i])==2)two=i;
        }
    }
    if(one){
        puts("YES");
        REPP(i,1,n+1){
            if(i!=one)printf("%d %d\n",one,i);
        }
    }
    else if(two){
        bool suc=1;
        REPP(i,1,n+1){
            if(SZ(d[i])%2){
                suc=0;
                break;
            }
        }
        if(suc){
            puts("YES");
            printf("%d %d\n",d[two][0],d[two][1]);
            REPP(i,1,n+1){
                if(SZ(d[i])&&i!=two){
                    REP(j,SZ(d[i]))printf("%d %d\n",d[two][j&1],d[i][j]);
                }
            }
        }
        else puts("NO");
    }
    else puts("NO");
    return 0;
}