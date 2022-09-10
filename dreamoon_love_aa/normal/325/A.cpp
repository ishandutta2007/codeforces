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
#define MAX 1000000000
int x[5][2],y[5][2],xx[10],yy[10],mi_x,ma_x,mi_y,ma_y,xn,ynn;
bool in(long long mx,long long x1,long long x2){
    return (mx-x1)*(mx-x2)<=0;
}
int main(){
    mi_x=mi_y=MAX;
    ma_x=ma_y=-MAX;
    DRI(n);
    REP(i,n){
        RII(x[i][0],y[i][0]);
        RII(x[i][1],y[i][1]);
        x[i][0]*=2;
        y[i][0]*=2;
        x[i][1]*=2;
        y[i][1]*=2;
        mi_x=min(mi_x,x[i][0]);
        ma_x=max(ma_x,x[i][1]);
        mi_y=min(mi_y,y[i][0]);
        ma_y=max(ma_y,y[i][1]);
        xx[xn++]=x[i][0];
        xx[xn++]=x[i][1];
        yy[ynn++]=y[i][0];
        yy[ynn++]=y[i][1];
    }
    if(ma_x-mi_x!=ma_y-mi_y){
        puts("NO");
        return 0;
    }
    sort(xx,xx+xn);
    sort(yy,yy+ynn);
    REPP(i,1,xn)REPP(j,1,ynn){
        int mx=(xx[i]+xx[i-1])/2;
        int my=(yy[j]+yy[j-1])/2;
        int k;
        for(k=0;k<n;k++){
            if(in(mx,x[k][0],x[k][1])&&in(my,y[k][0],y[k][1]))break;
        }
        if(k==n){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}