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
    map<char,int>H;
    H['f']=1;
    H['e']=2;
    H['d']=3;
    H['a']=4;
    H['b']=5;
    H['c']=6;
    char s[128];
    RS(s);
    int it=0;
    LL v=0;
    for(;s[it]>='0'&&s[it]<='9';it++){
        v*=10;
        v+=s[it]-'0';
    }
    LL an=H[s[it]];
    if(v%4==1){
        an+=v/4*12+v-1;
    }
    else if(v%4==2){
        an+=v/4*12+6+v-1;
    }
    else if(v%4==3){
        an+=v/4*12+v-3;
    }
    else if(v%4==0){
        an+=(v-1)/4*12+6+v-3;
    }
    cout<<an;
    return 0;
}