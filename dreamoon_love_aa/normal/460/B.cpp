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
#define F first
#define S second
typedef long long LL;
using namespace std;
int digit_sum(int x){
    int res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}
int main(){
    DRIII(a,b,c);
    vector<int>an;
    for(int i=1;i<=81;i++){
        LL res=1;
        REP(j,a)res*=i;
        res=res*b+c;
        if(res>0&&res<1e9&&digit_sum(res)==i)an.PB(res);
    }
    sort(ALL(an));
    printf("%d\n",SZ(an));
    REP(i,SZ(an)){
        if(i)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}