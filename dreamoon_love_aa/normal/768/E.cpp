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
int ret[61];
int main(){
ret[1]=1;
ret[2]=1;
ret[3]=2;
ret[4]=2;
ret[5]=2;
ret[6]=3;
ret[7]=3;
ret[8]=3;
ret[9]=3;
ret[10]=4;
ret[11]=4;
ret[12]=4;
ret[13]=4;
ret[14]=4;
ret[15]=5;
ret[16]=5;
ret[17]=5;
ret[18]=5;
ret[19]=5;
ret[20]=5;
ret[21]=6;
ret[22]=6;
ret[23]=6;
ret[24]=6;
ret[25]=6;
ret[26]=6;
ret[27]=6;
ret[28]=7;
ret[29]=7;
ret[30]=7;
ret[31]=7;
ret[32]=7;
ret[33]=7;
ret[34]=7;
ret[35]=7;
ret[36]=8;
ret[37]=8;
ret[38]=8;
ret[39]=8;
ret[40]=8;
ret[41]=8;
ret[42]=8;
ret[43]=8;
ret[44]=8;
ret[45]=9;
ret[46]=9;
ret[47]=9;
ret[48]=9;
ret[49]=9;
ret[50]=9;
ret[51]=9;
ret[52]=9;
ret[53]=9;
ret[54]=9;
ret[55]=10;
ret[56]=10;
ret[57]=10;
ret[58]=10;
ret[59]=10;
ret[60]=10;

    DRI(n);
    int ker=0;
    REP(i,n){
        DRI(x);
        ker^=ret[x];
    }
    puts(ker?"NO":"YES");    
    return 0;
}