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
const int SIZE = 1<<19;
int d[SIZE],used[SIZE],tt;
#include<time.h>
const double TIME_LIMIT = 0.95;
clock_t time_start;
void time_cut_start(){time_start = clock();}
bool check_time_cut(){return 1. * (clock()-time_start) / CLOCKS_PER_SEC < TIME_LIMIT;}
int main(){
    time_cut_start();
    srand(time(NULL));
    DRII(n,x);
    if(n==1)return 0*printf("YES\n%d\n",x);
    REP(i,SIZE)d[i]=i;
    while(check_time_cut()){
        random_shuffle(d,d+SIZE);
        int me=0;
        tt++;
        REP(i,n-1){
            me^=d[i];
            used[d[i]]=tt;
        }
        if((me^x)>=SIZE||used[me^x]==tt)continue;
        puts("YES");
        REP(i,n-1)printf("%d ",d[i]);
        printf("%d\n",me^x);
        return 0;
    }
    puts("NO");
    return 0;
}