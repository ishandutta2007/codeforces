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
int n[1111],t[1111];
int r[3][1111];
int main(){
    DRI(K);
    RIII(n[0],n[1],n[2]);
    RIII(t[0],t[1],t[2]);
    int an=0;
    REP(i,K){
        int mi[3]={1e9,1e9,1e9};
        REP(j,n[0]){
            mi[0]=min(r[0][j],mi[0]);
        }
        REP(j,n[1]){
            mi[1]=min(r[1][j]-t[0],mi[1]);
        }
        REP(j,n[2]){
            mi[2]=min(r[2][j]-t[0]-t[1],mi[2]);
        }
        int st=max(max(mi[0],mi[1]),mi[2]);
        REP(j,n[0]){
            if(r[0][j]<=st){
                r[0][j]=st+t[0];
                break;
            }
        }
        REP(j,n[1]){
            if(r[1][j]<=st+t[0]){
                r[1][j]=st+t[0]+t[1];
                break;
            }
        }
        REP(j,n[2]){
            if(r[2][j]<=st+t[0]+t[1]){
                r[2][j]=st+t[0]+t[1]+t[2];
                break;
            }
        }
        an=max(an,st+t[0]+t[1]+t[2]);
    }
    cout<<an<<endl;
    return 0;
}