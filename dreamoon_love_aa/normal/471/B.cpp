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
const int SIZE = 2222;
pair<int,int>pp[SIZE];
vector<int>an[3];
int main(){
    DRI(n);
    REP(i,n){
        DRI(x);
        pp[i]=MP(x,i);
    }
    sort(pp,pp+n);
    REP(i,n)an[0].PB(pp[i].S);
    vector<int>ch;
    REP(i,n-1){
        if(pp[i].F==pp[i+1].F){
            ch.PB(i);
        }
    }
    if(SZ(ch)<2)puts("NO");
    else{
        puts("YES");
        swap(pp[ch[0]],pp[ch[0]+1]);
        REP(i,n)an[1].PB(pp[i].S);
        swap(pp[ch[1]],pp[ch[1]+1]);
        REP(i,n)an[2].PB(pp[i].S);
        REP(i,3){
            REP(j,n){
                if(j)printf(" ");
                printf("%d",an[i][j]+1);
            }
            puts("");
        }
    }
    return 0;
}