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

int main(){
    DRIII(a,b,c);
    DRI(m);
    LL an1=0,an2=0;
    VI d[2];
    REP(i,m){
        DRI(v);
        char s[12];
        RS(s);
        if(s[0]=='U')d[0].PB(v);
        else d[1].PB(v);
    }
    REP(i,2)sort(ALL(d[i]));
    int dl[2]={};
    REP(i,min(SZ(d[0]),a)){
        dl[0]++;
        an1++;
        an2+=d[0][i];
    }
    REP(i,min(SZ(d[1]),b)){
        dl[1]++;
        an1++;
        an2+=d[1][i];
    }
    REP(i,c){
        if(dl[0]==SZ(d[0])&&dl[1]==SZ(d[1]))break;
        if(dl[0]==SZ(d[0])||(dl[1]!=SZ(d[1])&&d[1][dl[1]]<d[0][dl[0]])){
            an1++;
            an2+=d[1][dl[1]++];
        }
        else{
            an1++;
            an2+=d[0][dl[0]++];
        }
    }
    cout<<an1<<" "<<an2<<endl;
    return 0;
}