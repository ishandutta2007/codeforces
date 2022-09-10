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
const int SIZE = 2010;
PII V[SIZE][SIZE],H[SIZE][SIZE],st[SIZE],ed[SIZE];
int l[SIZE];
LL dp[SIZE][SIZE];
VI cross[SIZE],emp;
int off[SIZE];
bool in(int x,int L,int R){
    return x>=L&&x<=R;
}
int main(){
    DRIII(N,M,K);
    REPP(k,1,K+1){
        DRI(len);
        l[k]=len;
        int lt_x=-1,lt_y;
        REPP(i,1,len+1){
            DRIII(x,y,w);
            dp[k][i]=w+dp[k][i-1];
            if(lt_x!=-1){
                if(lt_x==x){
                    V[x][max(y,lt_y)]=MP(k,i);
                }
                else{
                    H[max(x,lt_x)][y]=MP(k,i);
                }
            }
            else st[k]=MP(x,y);
            ed[k]=MP(x,y);
            lt_x=x,lt_y=y;
        }
    }
    DRI(Q);
    while(Q--){
        char s[12];
        RS(s);
        if(s[0]=='S'){
            DRI(id);
            off[id]^=1;
        }
        else{
            DRII(x1,y1);
            DRII(x2,y2);
            REPP(i,1,K+1)cross[i]=emp;
            REPP(i,x1,x2+1){
                if(V[i][y1].F)cross[V[i][y1].F].PB(V[i][y1].S);
                if(V[i][y2+1].F)cross[V[i][y2+1].F].PB(V[i][y2+1].S);
            }
            REPP(j,y1,y2+1){
                if(H[x1][j].F)cross[H[x1][j].F].PB(H[x1][j].S);
                if(H[x2+1][j].F)cross[H[x2+1][j].F].PB(H[x2+1][j].S);
            }
            LL an=0;
            REPP(i,1,K+1){
                if(!off[i]){
                    int mul;
                    sort(ALL(cross[i]));
                    if(in(st[i].F,x1,x2)&&in(st[i].S,y1,y2))mul=1;
                    else mul=-1;
                    REP(j,SZ(cross[i])){
                        if(mul==1){
                            an+=dp[i][cross[i][j]-1];
                        }
                        else{
                            an-=dp[i][cross[i][j]-1];
                        }
                        mul*=-1;
                    }
                    if(in(ed[i].F,x1,x2)&&in(ed[i].S,y1,y2))an+=dp[i][l[i]];
                }
            }
            printf("%I64d\n",an);
        }
    }
    return 0;
}