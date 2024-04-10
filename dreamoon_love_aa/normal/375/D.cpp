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
const int SIZE = 100000;
int n,m;
vector<int>e[SIZE];
vector<pair<int,int> >qq[SIZE];
int id[SIZE],an[SIZE];
map<int,int>*contain[SIZE];
map<int,int>*seg[SIZE];
bool used[SIZE];
void ins(map<int,int>*ss,int x,int v){
    x=SIZE+1-x;
    while(x<=SIZE){
        int tmp=(*ss)[x];
        if(tmp+v==0)ss->erase(x);
        else (*ss)[x]=tmp+v;
        x+=x&-x;
    }
}
int query(map<int,int>*ss,int x){
    int res=0;
    x=SIZE+1-x;
    while(x){
        if(ss->count(x))res+=(*ss)[x];
        x-=x&-x;
    }
    return res;
}
void merge(int x,int y){
    if(SZ(*contain[x])<SZ(*contain[y])){
        swap(contain[x],contain[y]);
        swap(seg[x],seg[y]);
    }
    for(map<int,int>::iterator it=contain[y]->begin();it!=contain[y]->end();it++){
        if(contain[x]->count(it->F)){
            int tmp=(*contain[x])[it->F];
            (*contain[x])[it->F]+=it->S;
            ins(seg[x],tmp,-1);
            ins(seg[x],tmp+it->S,1);
        }
        else{
            (*contain[x])[it->F]=it->S;
            ins(seg[x],it->S,1);
        }
    }
    delete contain[y];
    delete seg[y];
}
void dfs(int x){
    used[x]=true;
    seg[x]=new map<int,int>;
    contain[x]=new map<int,int>;
    (*contain[x])[id[x]]=1;
    ins(seg[x],1,1);
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(used[y])continue;
        dfs(y);
        merge(x,y);
    }
    REP(i,SZ(qq[x])){
        an[qq[x][i].S]=query(seg[x],qq[x][i].F);
    }
}
int main(){
    RII(n,m);
    REP(i,n)RI(id[i]);
    REPP(i,1,n){
        DRII(x,y);
        x--;y--;
        e[x].PB(y);
        e[y].PB(x);
    }
    REP(i,m){
        DRII(x,y);
        x--;
        qq[x].PB(MP(y,i));
    }
    dfs(0);
    REP(i,m)printf("%d\n",an[i]);
    return 0;
}