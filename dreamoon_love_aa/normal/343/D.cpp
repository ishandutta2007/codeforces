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
#define SIZE 1000010
struct SegTree1{
    int LEFT,RIGHT,yy,rr,v;
    int d[SIZE<<2];
    void init(int l,int r){
        LEFT=l;
        RIGHT=r;
    }
    void __insert(int LL,int RR,int id){
        if(RR<yy||LL>rr)return;
        if(yy<=LL&&RR<=rr){
            d[id]=v;
            return;
        }
        int mm=(LL+RR)>>1;
        __insert(LL,mm,id*2);
        __insert(mm+1,RR,id*2+1);
    }
    void insert(int _yy,int _rr,int _v){
        yy=_yy;
        rr=_rr;
        v=_v;
        __insert(LEFT,RIGHT,1);
    }
    int query(int x){
        yy=LEFT,rr=RIGHT;
        int id=1,res=d[1];
        while(yy<rr){
            int mm=(yy+rr)>>1;
            if(x<=mm){
                id=id*2;
                res=max(res,d[id]);
                rr=mm;
            }
            else{
                id=id*2+1;
                res=max(res,d[id]);
                yy=mm+1;
            }
        }
        return res;
    }
}tree1;
struct segTree2{
    int LEFT,RIGHT,x,v,yy,rr;
    int d[SIZE<<2];
    void init(int l,int r){
        LEFT=l;
        RIGHT=r;
    }
    void __insert(int LL,int RR,int id){
        d[id]=v;
        if(LL==RR)return;
        int mm=(LL+RR)>>1;
        if(x<=mm)__insert(LL,mm,id*2);
        else __insert(mm+1,RR,id*2+1);
    }
    void insert(int _x,int _v){
        x=_x;
        v=_v;
        __insert(LEFT,RIGHT,1);
    }
    int __query(int LL,int RR,int id){
        if(RR<yy|rr<LL)return 0;
        if(yy<=LL&&RR<=rr)return d[id];
        int mm=(LL+RR)>>1;
        return max(__query(LL,mm,id*2),__query(mm+1,RR,id*2+1));
    }
    int query(int _yy,int _rr){
        yy=_yy;
        rr=_rr;
        return __query(LEFT,RIGHT,1);
    }
}tree2;
vector<int>e[SIZE];
int vn,yy[SIZE],rr[SIZE],used[SIZE];
void dfs(int x){
    used[x]=1;
    yy[x]=vn++;
    REP(i,SZ(e[x])){
        if(used[e[x][i]]==0){
            dfs(e[x][i]);
        }
    }
    rr[x]=vn++;
}
int main(){
    DRI(n);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs(1);
    DRI(q);
    tree1.init(0,vn-1);
    tree2.init(0,vn-1);
    int now_time=0;
    while(q--){
        now_time++;
        DRII(ty,x);
        if(ty==1){
            tree1.insert(yy[x],rr[x],now_time);
        }
        else if(ty==2){
            tree2.insert(yy[x],now_time);
        }
        else if(ty==3){
            int t1=tree1.query(yy[x]);
            int t2=tree2.query(yy[x],rr[x]);
            if(t1==t2&&t2==0)puts("0");
            else if(t1>t2)puts("1");
            else puts("0");

        }
    }
    return 0;
}