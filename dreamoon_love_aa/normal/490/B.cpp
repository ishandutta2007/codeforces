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
int lt[SIZE],used[SIZE];
vector<int>an;
int main(){
    MS1(lt);
    DRI(n);
    REP(i,n){
        DRII(x,y);
        lt[x]=y;
        used[y]=1;
    }
    int st=-1;
    REPP(i,1,1000001){
        if(lt[i]!=-1&&!used[i]){
            st=i;
            break;
        }
    }
    an.PB(st);
    int now1=0;
    int now2=st;
    while(1){
        if(lt[now1]>0){
            now1=lt[now1];
            an.PB(now1);
        }
        else break;
        if(lt[now2]>0){
            now2=lt[now2];
            an.PB(now2);
        }
        else break;
    }
    REP(i,SZ(an)){
        if(i)printf(" ");
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}