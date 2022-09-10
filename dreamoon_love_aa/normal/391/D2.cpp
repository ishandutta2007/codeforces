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
const int SIZE = 50010;
const int MAX = 1e8+5;
int a[SIZE][3],b[SIZE][3],n,m,dn;
struct data{
    int wh,x,y;
    data(int _wh=0,int _x=0,int _y=0):wh(_wh),x(_x),y(_y){}
    bool operator<(const data& b)const{
        return x<b.x||(x==b.x&&wh<b.wh);
    }
}d[SIZE*4];
void ins(map<int,int>&H,int x,int v){
    x+=MAX;
    while(x<MAX*2){
        H[x]+=v;
        x+=x&-x;
    }
}
int qq(map<int,int>&H,int x){
    x+=MAX;
    int res=0;
    while(x){
        res+=H[x];
        x-=x&-x;
    }
    return res;
}
bool valid(int x){
    dn=0;
    REP(i,n){
        if(a[i][2]>=x*2){
            d[dn++]=data(2,a[i][0],i);
        }
    }
    REP(i,m){
        if(b[i][2]>=x*2){
            d[dn++]=data(0,b[i][0]+x,b[i][1]);
            d[dn++]=data(1,b[i][0]+b[i][2]+1-x,b[i][1]);
        }
    }
    sort(d,d+dn);
    map<int,int>H;
    REP(i,dn){
        if(d[i].wh==0){
            ins(H,d[i].y,1);
        }
        else if(d[i].wh==1){
            ins(H,d[i].y,-1);
        }
        else{
            if(qq(H,a[d[i].y][1]+a[d[i].y][2]-x)-qq(H,a[d[i].y][1]+x-1)>0)return true;
        }
    }
    return false;
}
int main(){
    RII(n,m);
    REP(i,n)REP(j,3)RI(a[i][j]);
    REP(i,m)REP(j,3)RI(b[i][j]);
    int L=0,R=MAX;
    while(L<R){
        int mm=(L+R+1)/2;
        if(valid(mm))L=mm;
        else R=mm-1;
    }
    cout<<L<<endl;
    return 0;
}