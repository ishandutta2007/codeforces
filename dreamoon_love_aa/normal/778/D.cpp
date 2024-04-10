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
int n,m;
char s[55][55];
void ch(VPII& ret,int x,int y,int dir){
    if(!dir){
        if(s[x][y]=='L')return;
        ch(ret,x,y+1,1);
        ret.PB(MP(x,y));
        s[x][y]=s[x+1][y]='L';
        s[x][y+1]=s[x+1][y+1]='R';
    }
    else{
        if(s[x][y]=='U')return;
        ch(ret,x+1,y,0);
        ret.PB(MP(x,y));
        s[x][y]=s[x][y+1]='U';
        s[x+1][y]=s[x+1][y+1]='D';
    }
}
void get(VPII& ret){
    if(m%2==0){
        REP(i,n)for(int j=0;j<m;j+=2){
            ch(ret,i,j,0);
        }
    }
    else{
        for(int i=0;i<n;i+=2)REP(j,m){
            ch(ret,i,j,1);
        }
    }
}
int main(){
    RII(n,m);
    VPII step1,step2;
    REP(i,n)RS(s[i]);
    get(step1);
    REP(i,n)RS(s[i]);
    get(step2);
    reverse(ALL(step2));
    printf("%d\n",SZ(step1)+SZ(step2));
    REP(i,SZ(step1))printf("%d %d\n",step1[i].F+1,step1[i].S+1);
    REP(i,SZ(step2))printf("%d %d\n",step2[i].F+1,step2[i].S+1);
    return 0;
}