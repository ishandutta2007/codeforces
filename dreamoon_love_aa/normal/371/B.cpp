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
map<int,int>H1,H2;
const int SIZE = 11111;
int bfs[SIZE];
void f(int x,int p,int bfs[],int &j,map<int,int>&H){
    if(x%p==0){
        if(H.count(x/p)==0){
            H[x/p]=H[x]+1;
            bfs[j++]=x/p;
        }
    }
}
int main(){
    DRII(a,b);
    bfs[0]=a;
    H1[a]=0;
    for(int i=0,j=1;i<j;i++){
        int x=bfs[i];
        f(x,2,bfs,j,H1);
        f(x,3,bfs,j,H1);
        f(x,5,bfs,j,H1);
    }
    bfs[0]=b;
    H2[b]=0;
    for(int i=0,j=1;i<j;i++){
        int x=bfs[i];
        f(x,2,bfs,j,H2);
        f(x,3,bfs,j,H2);
        f(x,5,bfs,j,H2);
    }
    int mi=-1;
    for(map<int,int>::iterator it =H1.begin();it!=H1.end();it++){
        if(H2.count(it->first)){
            if(mi==-1||mi>it->second+H2[it->first]){
                mi=it->second+H2[it->first];
            }
        }
    }
    printf("%d\n",mi);
    return 0;
}