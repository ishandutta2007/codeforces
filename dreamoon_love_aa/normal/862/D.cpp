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
const int SIZE = 1e6+10;
int n,one;
int ask(string s){
    printf("? %s\n",s.c_str());
    fflush(stdout);
    DRI(v);
    return v;
}
void answer(int x,int y){
    x++;y++;
    printf("! %d %d\n",x,y);
    fflush(stdout);
    exit(0);
}
int get_one(int L,int R){
    string tmp="";
    REP(i,n){
        if(i<L||i>R)tmp+="0";
        else tmp+="1";
    }
    int v=ask(tmp);
    return ((R-L+1)-(v-one))/2;
}
void qq(int L,int R,int num){
    int mm=(L+R)/2;
    int v=get_one(L,mm);
    if(v==0){
        if(num==R-mm)answer(L,R);
        qq(mm+1,R,num);
    }
    else if(v==mm-L+1){
        if(num==v)answer(R,L);
        qq(mm+1,R,num-v);
    }
    else{
        qq(L,mm,v);
    }
}
int main(){
    RI(n);
    {
        string tmp;
        REP(i,n)tmp+="0";
        one=ask(tmp);
    }
    qq(0,n-1,one);
    return 0;
}