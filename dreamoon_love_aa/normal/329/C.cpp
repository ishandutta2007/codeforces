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
#define SIZE 100010
struct EDGE{
    int x,y;
    EDGE(int _x=0,int _y=0){x=_x;y=_y;}
}e[7*7];
int en,ex[8][8],qq[SIZE],qn;
vector<int>ee[SIZE];
bool hh(int x,int y){
    REP(i,SZ(ee[x])){
        if(ee[x][i]==y)return 1;
    }
    return 0;
}
int main(){
    DRII(n,m);
    if(n<=7){
        REPP(i,1,n+1)REPP(j,i+1,n+1)e[en++]=EDGE(i,j);
        REP(i,m){
            DRII(x,y);
            ex[x][y]=ex[y][x]=1;
        }
        REP(i,1<<en){
            int j,cnt=0,deg[8]={};
            for(j=0;j<en;j++){
                if(((i>>j)&1)){
                    cnt++;
                    if(ex[e[j].x][e[j].y])break;
                    deg[e[j].x]++;
                    deg[e[j].y]++;
                }
            }
            if(j==en&&cnt==m){
                int k;
                for(k=1;k<=n;k++){
                    if(deg[k]>2)break;
                }
                if(k>n){
                    for(k=0;k<en;k++){
                        if((i>>k)&1)printf("%d %d\n",e[k].x,e[k].y);
                    }
                    return 0;
                }
            }
        }
        puts("-1");
    }
    else{
        REP(i,m){
            DRII(x,y);
            ee[x].PB(y);
            ee[y].PB(x);
        }
        REP(i,n)qq[i]=i+1;
        while(1){
            random_shuffle(qq,qq+n);
            qq[n]=qq[0];
            int i=0;
            for(i=0;i<m;i++){
                if(hh(qq[i],qq[i+1]))break;
            }
            if(i==m){
                REP(i,m)printf("%d %d\n",qq[i],qq[i+1]);
                return 0;
            }
        }
    }
    return 0;
}