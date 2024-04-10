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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
// template end here
PII xx[SIZE];
int x[SIZE],to[SIZE];
int main(){
    DRII(n,m);
    REP(i,n){
        RI(xx[i].F);
        xx[i].S=i+1;
    }
    sort(xx,xx+n);
    REP(i,n){
        x[i]=xx[i].F;
        to[xx[i].S]=i;
    }
    while(m--){
        bool first=1;
        DRII(id,l);
        if(n==1){
            puts("1");
            continue;
        }
        id=to[id];
        int LR=1;
        int flag=0;
        while(1){
            //printf("[%d,%d,%d]\n",id,l,LR);
            if(LR==1){
                if(id==n-1||x[id]+l<x[id+1]){
                    if(flag)break;
                    LR=-LR;
                    flag=1;
                }
                else{
                    int nxt_id=lower_bound(x+id+1,x+n,x[id]+l+1)-x-1;
                    int l2=x[nxt_id]-x[id];
                    if(!first){
                        int v=l/l2;
                        l%=l2;
                        if(v&1){
                            id=nxt_id;
                        }
                        flag=0;
                    }
                    else{
                        id=nxt_id;
                        first=0;
                        l-=l2;
                    }
                }
            }
            else{
                if(!id||x[id]-l>x[id-1]){
                    if(flag)break;
                    LR=-LR;
                    flag=1;
                }
                else{
                    int nxt_id=lower_bound(x,x+id,x[id]-l)-x;
                    int l2=x[id]-x[nxt_id];
                    if(!first){
                        int v=l/l2;
                        l%=l2;
                        if(v&1){
                            id=nxt_id;
                        }
                        flag=0;
                    }
                    else{
                        id=nxt_id;
                        first=0;
                        l-=l2;
                    }
                    LR=1;
                }
            }
        }
        printf("%d\n",xx[id].S);
    }
    return 0;
}