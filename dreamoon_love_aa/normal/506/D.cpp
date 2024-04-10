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
#define PII pair<int,int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2e5+10;
map<PII,int>to;
struct Union_Find{
    int d[SIZE];
    void init(int n){
        REP(i,n)d[i]=i;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        d[x]=y;
        return 1;
    }
}U;
int id,p[SIZE];
int get(int x,int y){
    if(to.count(MP(x,y)))return to[MP(x,y)];
    p[id]=x;
    return to[MP(x,y)]=id++;
}
vector<int>g[SIZE];
int d[SIZE],dn;
bool compare(int x,int y){
    return SZ(g[x])>SZ(g[y]);
}
map<PII,int>qq;
int an[SIZE],qx[SIZE],qy[SIZE];
bool dup[SIZE];
int main(){
    DRII(n,m);
    U.init(m*2);
    REP(i,m){
        DRIII(x,y,v);
        x=get(x,v);
        y=get(y,v);
        U.uu(x,y);
    }
    REP(i,id){
        g[U.find(i)].PB(p[i]);
    }
    REP(i,id){
        if(SZ(g[i])){
            sort(ALL(g[i]));
            d[dn++]=i;
        }
    }
    sort(d,d+dn,compare);
    DRI(q);
    REP(i,q){
        RII(qx[i],qy[i]);
        if(qq.count(MP(min(qx[i],qy[i]),max(qx[i],qy[i])))){
            dup[i]=1;
            an[i]=-qq[MP(min(qx[i],qy[i]),max(qx[i],qy[i]))]-1;
        }
        else qq[MP(min(qx[i],qy[i]),max(qx[i],qy[i]))]=i;
    }
    REP(i,min(100,dn)){
        int me=d[i];
        REP(j,q){
            if(dup[j])continue;
            if(binary_search(ALL(g[me]),qx[j])&&binary_search(ALL(g[me]),qy[j]))an[j]++;
        }
    }
    REPP(i,100,dn){
        int me=d[i];
        REP(j,SZ(g[me]))REPP(k,j+1,SZ(g[me])){
            if(qq.count(MP(g[me][j],g[me][k]))){
                an[qq[MP(g[me][j],g[me][k])]]++;
            }
        }
    }
    REP(i,q){
        if(an[i]<0)printf("%d\n",an[-an[i]-1]);
        else printf("%d\n",an[i]);
    }
    return 0;
}