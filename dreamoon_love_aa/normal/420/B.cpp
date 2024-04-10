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
set<int>H;
const int SIZE = 1e5+5;
char c[SIZE][4];
int id[SIZE],cnt[SIZE],last[SIZE],ban[SIZE];
int BIT[SIZE];
void ins(int x,int v){
    while(x){
        BIT[x]+=v;
        x-=x&-x;
    }
}
int qq(int x){
    int res=0;
    if(!x)return 0;
    while(x<SIZE){
        res+=BIT[x];
        x+=x&-x;
    }
    return res;
}
int main(){
    DRII(n,m);
    MS0(last);
    REPP(i,1,m+1){
        RS(c[i]);
        RI(id[i]);
        if(c[i][0]=='-'){
            if(!last[id[i]]){
                ins(i,1);
            }
            else{
                ins(i,1);
                ins(last[id[i]],-1);
            }
        }
        last[id[i]]=i;
    }
    REPP(i,1,n+1){
        if(last[i]&&c[last[i]][0]=='+'){
            ins(SIZE-1,1);
            ins(last[i],-1);
        }
    }
    REPP(i,1,m+1){
        if(c[i][0]=='+'){
            int tmp=qq(i);
            if(tmp)ban[id[i]]=1;
            else{
                if(i!=1&&id[i-1]!=id[i])ban[id[i]]=1;
            }
        }
        else{
            int tmp=qq(i+1);
            if(tmp)ban[id[i]]=1;
            else{
                if(i!=m&&id[i+1]!=id[i])ban[id[i]]=1;
            }
        }
    }
    vector<int>res;
    REPP(i,1,n+1)
        if(!ban[i])res.PB(i);
    printf("%d\n",SZ(res));
    REP(i,SZ(res)){
        if(i)putchar(' ');
        printf("%d",res[i]);
    }
    puts("");
    return 0;
}