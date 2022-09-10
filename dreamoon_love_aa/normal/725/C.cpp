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
char s[SIZE],an[2][26];
VI cc[128];
int main(){
    RS(s);
    REP(i,27)cc[s[i]].PB(i);
    char id=-1;
    REPP(i,'A','Z'+1){
        if(SZ(cc[i])==2){
            id=i;
            break;
        }
    }
    if(cc[id][0]+1==cc[id][1])puts("Impossible");
    else{
        int ll=cc[id][0];
        int rr=cc[id][1];
        int v=rr-ll;
        an[0][(v-1)/2]=id;
        int x=0,y=(v-1)/2;
        REPP(i,ll+1,rr){
            if(!x)y--;
            else y++;
            if(y<0){
                x=1;
                y=0;
            }
            an[x][y]=s[i];
        }
        REPP(i,rr+1,27){
            if(!x)y--;
            else y++;
            if(y>=13){
                x=0;
                y=12;
            }
            an[x][y]=s[i];
        }
        REP(i,ll){
            if(!x)y--;
            else y++;
            if(y>=13){
                x=0;
                y=12;
            }
            an[x][y]=s[i];
        }
    }
    REP(i,2)puts(an[i]);
    return 0;
}