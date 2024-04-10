#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
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
typedef long long LL;
using namespace std;
const int SIZE = 1e5+5;
int a[SIZE],used[SIZE],d[SIZE],num[SIZE];
long long an;
vector<int>e[SIZE];
vector<pair<int,int> >pp;
int find(int x){
    if(x==d[x])return x;
    return d[x]=find(d[x]);
}
void uu(int x,int y,long long v){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(num[x]<num[y]){
        d[x]=y;
        an+=(LL)num[x]*num[y]*v;
        num[y]+=num[x];
    }
    else{
        d[y]=x;
        an+=(LL)num[x]*num[y]*v;
        num[x]+=num[y];
    }
}
int main(){
    DRII(n,m);
    REPP(i,1,n+1){
        RI(a[i]);
        pp.PB(MP(a[i],i));
    }
    sort(ALL(pp));
    REPP(i,1,n+1)d[i]=i,num[i]=1;
    while(m--){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    for(int i=SZ(pp)-1;i>=0;i--){
        int x=pp[i].S;
        REP(j,SZ(e[x])){
            int y=e[x][j];
            if(used[y]){
                uu(x,y,pp[i].F);
            }
        }
        used[x]=1;
    }
    printf("%.12f\n",1.*an/((LL)n*(n-1)/2));
    return 0;
}