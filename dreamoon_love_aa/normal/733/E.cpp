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
char s[SIZE];
LL an[SIZE];
int main(){
    DRI(n);
    RS(s);
    int rr=0,num=0;
    LL v=1,v2=1;
    REP(i,n){
        num++;
        v-=i; 
        while(rr<n&&num>0){
            if(s[rr]=='D'){
                v+=2*rr;
                num--;
            }
            rr++;
        }
        if(num)break;
        an[i]=v;
        v-=i;
    }
    REP(i,n){
        if(s[i]=='U')s[i]='D';
        else s[i]='U';
    }
    reverse(s,s+n);
    rr=0,num=0;
    v=1,v2=1;
    REP(i,n){
        num++;
        v-=i; 
        while(rr<n&&num>0){
            if(s[rr]=='D'){
                v+=2*rr;
                num--;
            }
            rr++;
        }
        if(num)break;
        an[n-1-i]=v;
        v-=i;
    }
    REP(i,n)printf("%I64d ",an[i]);
    return 0;
}