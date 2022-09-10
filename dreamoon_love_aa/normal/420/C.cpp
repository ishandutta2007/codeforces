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
const int SIZE = 3e5+5;
map<int,int>H[SIZE];
int deg[SIZE],deg2[SIZE];
int main(){
    DRII(n,p);
    REP(i,n){
        DRII(x,y);
        H[x][y]++;
        H[y][x]++;
        deg[x]++;
        deg[y]++;
    }
    REPP(i,1,n+1)deg2[i]=deg[i];
    sort(deg+1,deg+n+1);
    long long an=0;
    REPP(i,1,n+1){
        int lb=lower_bound(deg+1,deg+n+1,p-deg2[i])-deg;
        if(deg2[i]*2>=p)an--;
        an+=n+1-lb;
        for(map<int,int>::iterator it=H[i].begin();it!=H[i].end();it++){
            if(deg2[i]+deg2[it->F]-it->S<p&&deg2[i]+deg2[it->F]>=p)an--;
        }
    }
    cout<<an/2<<endl;
    return 0;
}