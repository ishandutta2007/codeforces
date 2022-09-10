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
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define F first
#define S second
typedef int64_t LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
const int TEN = 10;
int get_bit(int x,int v){
    return (x>>v)&1;
}
int main(){
    DRI(n);
    int d[TEN];
    REP(i,TEN)d[i]=1;
    REP(i,n){
        char s[12];
        RS(s);
        DRI(x);
        if(s[0]=='|'){
            REP(i,TEN){
                if(get_bit(x,i)){
                    d[i]=2;
                }
            }
        }
        else if(s[0]=='&'){
            REP(i,TEN){
                if(!get_bit(x,i)){
                    d[i]=0;
                }
            }
        }
        else{ // ^
            REP(i,TEN){
                if(get_bit(x,i)){
                    d[i]^=2;
                }
            }
        }
    }
    vector<pair<char,int>>an;
    int v=0;
    REP(i,TEN){
        if(d[i]==3)v^=1<<i;
    }
    an.PB(MP('^',v));
    v=0;
    REP(i,TEN){
        if(d[i]==2){
            v^=1<<i;
        }
    }
    an.PB(MP('|',v));
    v=0;
    REP(i,TEN){
        if(d[i]!=0){
            v^=1<<i;
        }
    }
    an.PB(MP('&',v));
    printf("%d\n",SZ(an));
    REP(i,SZ(an)){
        printf("%c %d\n",an[i].F,an[i].S);
    }
    return 0;
}