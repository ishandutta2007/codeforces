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
const int SIZE = 2e6+10;
char s[SIZE];
char an[SIZE];
int st=0;
int len[SIZE],ss[SIZE];
PII d[SIZE];
int main(){
    DRI(n);
    int ma=0;
    REP(i,n){
        scanf("%s",s+st);
        ss[i]=st;
        len[i]=LEN(s+st);
        st+=len[i];
        DRI(m);
        REP(j,m){
            DRI(x);
            ma=max(ma,x+len[i]-1);
            d[x]=max(d[x],MP(len[i],i));
        }
    }
    int far=0,id=-1,from=-1;
    REPP(i,1,ma+1){
        if(d[i].F+i-1>far){
            from=i;
            far=d[i].F+i-1;
            id=d[i].S;
        }
        if(far<i)an[i]='a';
        else{
            an[i]=s[ss[id]+(i-from)];
        }
    }
    puts(an+1);
    return 0;
}