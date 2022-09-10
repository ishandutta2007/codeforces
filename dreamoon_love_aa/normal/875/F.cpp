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
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int SIZE = 1e6+10;
struct Union_Find{
    int d[SIZE],num[SIZE],v[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1,v[i]=0;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    int uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return x;
        if(num[x]<=num[y]){
            num[y]+=num[x];
            v[y]+=v[x];
            d[x]=y;
            return y;
        }
        else{
            num[x]+=num[y];
            v[x]+=v[y];
            d[y]=x;
            return x;
        }
        return -1;
    }
}U;
VPII e[SIZE];
int main(){
    vector<pair<int,PII>>kerker;
    DRII(n,m);
    REP(i,m){
        DRIII(x,y,v);
        x--;y--;
        kerker.PB(MP(v,MP(x,y)));
    }
    sort(ALL(kerker));
    reverse(ALL(kerker));
    U.init(n);
    LL an=0;
    REP(i,m){
        int x=kerker[i].S.F;
        int y=kerker[i].S.S;
        int id=U.uu(x,y);
        if(U.num[id]>U.v[id]){
            U.v[id]++;
            an+=kerker[i].F;
        }
    }
    cout<<an<<endl;
    return 0;
}