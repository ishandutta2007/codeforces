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
int qq(int x,int y){
    printf("1 %d %d\n",x,y);
    fflush(stdout);
    char s[24];
    RS(s);
    if(s[0]=='T')return 1;
    return 0;
}
int find(int L,int R,int known){
    if(L>R)return -1;
    if(L==R){
        if(!known)return L;
        if(qq(L,known))return L;
        return -1;
    }
    int mm=(L+R)/2;
    int ret=qq(mm,mm+1);
    if(ret)return find(L,mm,known);
    else{
        return find(mm+1,R,known);
    }
}
int main(){
    DRII(n,k);
    int x=find(1,n,0);
    int y=find(1,x-1,x);
    int z=find(x+1,n,x);
    if(y!=-1)printf("2 %d %d\n",x,y);
    else printf("2 %d %d\n",x,z);
    return 0;
}