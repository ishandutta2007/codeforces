#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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
using namespace std;
vector<int>d[2010];
int main(){
    long long sum=0;
    DRII(n,k);
    REPP(i,1,n){
        REPP(j,i+1,n+1){
            DRI(x);
            if(x>=0){sum+=x;d[i].PB(x);d[j].PB(x);}
        }
    }
    if(k==1||k==n-1)cout<<sum*2/n<<endl;
    else if(k==2){
        long long an=0;
        REPP(i,1,n+1){
            REP(j,SZ(d[i]))
                REPP(j2,j+1,SZ(d[i]))an+=d[i][j]+d[i][j2];
        }
        cout<<an/(n*(n-1)/2)<<endl;
    }
    else while(1);
    return 0;
}