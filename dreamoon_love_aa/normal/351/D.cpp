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
#define SIZE 100011
int b[SIZE],an[SIZE];
vector<pair<int,int> >qq[SIZE];
deque<int>index[SIZE];
int d[SIZE],h[SIZE];
void inc(int x,int v){
    while(x<SIZE){
        d[x]+=v;
        x+=x&-x;
    }
}
int query(int x){
    int res=0;
    while(x){
        res+=d[x];
        x-=x&-x;
    }
    return res;
}
int d2[SIZE<<2];
void insert(int L,int R,int id,int lol,int rr,int v){
    if(R<lol||L>rr)return;
    if(L>=lol&&R<=rr){
        d2[id]+=v;
        return;
    }
    int mm=(L+R)>>1;
    insert(L,mm,id*2,lol,rr,v);
    insert(mm+1,R,id*2+1,lol,rr,v);
}
int pos(int L,int R,int id,int x){
    int res=d2[id];
    if(L==R)return res;
    int mm=(L+R)>>1;
    if(x<=mm)return res+pos(L,mm,id*2,x);
    return res+pos(mm+1,R,id*2+1,x);

}
int main(){
    DRI(m);
    REPP(i,1,m+1)RI(b[i]);
    DRI(Q);
    REP(i,Q){
        DRII(x,y);
        qq[x].PB(MP(y,i));
    }
    for(int i=m;i>=1;i--){
        if(SZ(index[b[i]])){
            inc(index[b[i]].back(),-1);
            int dif=index[b[i]].back()-i;
            insert(1,m,1,i,i+dif-1,1);
            index[b[i]].push_back(i);
            int last=-1;
            while(index[b[i]][0]-index[b[i]][1]!=dif){
                last=index[b[i]][0]-1;
                index[b[i]].pop_front();
            }
            if(last!=-1){
                insert(1,m,1,last+1,h[b[i]],-1);
                h[b[i]]=last;
            }
        }
        else{
            h[b[i]]=m;
            index[b[i]].push_back(i);
            insert(1,m,1,i,m,1);
        }
        inc(i,1);
        REP(j,SZ(qq[i])){
            int res=query(qq[i][j].F);
            an[qq[i][j].S]=res+(pos(1,m,1,qq[i][j].F)==0);
        }
    }
    REP(i,Q)printf("%d\n",an[i]);
    return 0;
}