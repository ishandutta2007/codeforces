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
char s1[SIZE],s2[SIZE];
int main(){
    DRI(n);
    RS(s1);
    RS(s2);
    int ll=0;
    int rr=n-1;
    for(;ll<n&&s1[ll]==s2[ll];ll++);
    for(;rr>=0&&s1[rr]==s2[rr];rr--);
    if(ll==rr){
        puts("2");
        return 0;
    }
    else{
        bool err[2]={};
        for(int i=1;ll+i<=rr;i++){
            if(s1[ll+i]!=s2[ll+i-1])err[0]=1;
            if(s2[ll+i]!=s1[ll+i-1])err[1]=1;
        }
        int an=0;
        REP(i,2)if(!err[i])an++;
        printf("%d\n",an);
    }
    return 0;
}