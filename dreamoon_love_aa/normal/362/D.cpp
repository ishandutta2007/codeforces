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
int n,m,p,q,d[SIZE];
vector<int>e[SIZE];
long long C[SIZE];
int find(int x){
    if(x!=d[x])return d[x]=find(d[x]);
    return x;
}
void uu(int x,int y,int v){
    x=find(x);
    y=find(y);
    if(x!=y){
        d[x]=y;
        C[y]+=C[x];
    }
    C[y]+=v;
}
struct data{
    int id;
    long long v;
    data(int _id=0,long long _v=0):id(_id),v(_v){}
    bool operator<(const data& b)const{return v>b.v;}
};
int main(){
    int xx=0,yy=1;
    RII(n,m);
    RII(p,q);
    REP(i,n){
        d[i]=i;
    }
    REP(i,m){
        DRIII(x,y,v);
        x--;y--;
        xx=x;
        yy=y;
        uu(x,y,v);
    }
    vector<pair<int,long long> >R;
    REP(i,n){
        if(d[i]==i)R.PB(MP(i,C[i]));
    }
    if(q==n){
        if(m==0&&p==0)
            puts("YES");
        else
            puts("NO");
        return 0;
    }
    if(SZ(R)<q||SZ(R)-p>q){
        puts("NO");
        return 0;
    }
    puts("YES");
    int mm=SZ(R)-q;
    priority_queue<data>heap;
    REP(i,SZ(R))heap.push(data(R[i].F,R[i].S));
    long long res=0;
    REP(i,mm){
        data x=heap.top();heap.pop();
        data y=heap.top();heap.pop();
        data z=data(x.id,min((long long)1e9,x.v+y.v+1)+x.v+y.v);
        printf("%d %d\n",x.id+1,y.id+1);
        xx=x.id,yy=y.id;
        heap.push(z);
    }
    REP(i,p-mm)printf("%d %d\n",xx+1,yy+1);
    return 0;
}