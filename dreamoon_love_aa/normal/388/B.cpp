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
const int SIZE = 1011;
int e[SIZE][SIZE],id;
void add(int x,int y){
    e[x][y]=e[y][x]=1;
}
int go(int st,int ed,int num){
    if(num==1){
        add(st,ed);
        return 1;
    }
    if(num==2){
        add(st,id);
        add(id++,ed);
        add(st,id);
        add(id++,ed);
        return 2;
    }
    if(num&1){
        int len=go(st,ed,num-1);
        add(st,id);
        for(int i=1;i<len;i++){
            if(i!=len-1){
                add(id,id+1);
                id++;
            }
            else{
                add(id,ed);
                id++;
            }
        }
        return len;
    }
    else{
        int mid=id++;
        int len=go(st,mid,num/2);
        len+=go(mid,ed,2);
        return len;
    }
}
int main(){
    DRI(K);
    id=3;
    go(1,2,K);
    printf("%d\n",id-1);
    REPP(i,1,id){
        REPP(j,1,id){
            if(e[i][j])putchar('Y');
            else putchar('N');
        }
        puts("");
    }
    return 0;
}