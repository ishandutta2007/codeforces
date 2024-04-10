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
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
map<LL,int>dp;
map<LL,pair<int,int> >re;
set<pair<int,int> >H;
pair<int,int>an1,an2;
void go(LL a1,int b1,int v){
    if(H.count(MP(a1,b1)))return;
    H.insert(MP(a1,b1));
    if(dp.count(a1*b1)){
        if(dp[a1*b1]>v){
            dp[a1*b1]=v;
            re[a1*b1]=MP(a1,b1);
        }
    }
    else{
        dp[a1*b1]=v;
        re[a1*b1]=MP(a1,b1);
    }
    if(a1%2==0)go(a1/2,b1,v+1);
    if(b1%2==0)go(a1,b1/2,v+1);
    if(a1%3==0)go(a1/3*2,b1,v+1);
    if(b1%3==0)go(a1,b1/3*2,v+1);
}
int an=MOD;
void go2(LL a1,int b1,int v){
    if(H.count(MP(a1,b1)))return;
    H.insert(MP(a1,b1));
    if(dp.count(a1*b1)){
        if(an>v+dp[a1*b1]){
            an=v+dp[a1*b1];
            an1=re[a1*b1];
            an2=MP(a1,b1);
        }
    }
    if(a1%2==0)go2(a1/2,b1,v+1);
    if(b1%2==0)go2(a1,b1/2,v+1);
    if(a1%3==0)go2(a1/3*2,b1,v+1);
    if(b1%3==0)go2(a1,b1/3*2,v+1);
}
int main(){
    DRII(a1,b1);
    DRII(a2,b2);
    go(a1,b1,0);
    H.clear();
    go2(a2,b2,0);
    if(an==MOD)an=-1;
    cout<<an<<endl;
    if(an!=-1){
        printf("%d %d\n",an1.F,an1.S);
        printf("%d %d\n",an2.F,an2.S);
    }
    return 0;
}