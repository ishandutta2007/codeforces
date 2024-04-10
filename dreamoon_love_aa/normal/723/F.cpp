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
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
PII e[SIZE];
struct Union_Find{
    int d[SIZE],num[SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]<=num[y]){
            num[y]+=num[x];
            d[x]=y;
        }
        else{
            num[x]+=num[y];
            d[y]=x;
        }
        return 1;
    }
}U;
VPII an;
int d[SIZE][2];
int main(){
    DRII(n,m);
    REP(i,m){
        RII(e[i].F,e[i].S);
        if(e[i].F>e[i].S)swap(e[i].F,e[i].S);
    }
    DRII(s,t);
    DRII(d_s,d_t);
    if(s>t){
        swap(s,t);
        swap(d_s,d_t);
    }
    U.init(n+1);
    bool cc=0;
    REP(i,m){
        if(e[i].F==s&&e[i].S==t)cc=1;
        if(e[i].F==s)continue;
        if(e[i].F==t)continue;
        if(e[i].S==s)continue;
        if(e[i].S==t)continue;
        if(U.uu(e[i].F,e[i].S))an.PB(e[i]);
    }
    REPP(i,1,n+1){
        if(i!=s&&i!=t&&U.find(i)==i)d[i][0]=d[i][1]=-1;
    }
    REP(i,m){
        if(e[i].F==s&&e[i].S==t)continue;
        if(e[i].F==s||e[i].S==s){
            int y=e[i].F+e[i].S-s;
            if(d[U.find(y)][0]==-1){
                d[U.find(y)][0]=y;
            }
        }
        if(e[i].F==t||e[i].S==t){
            int y=e[i].F+e[i].S-t;
            if(d[U.find(y)][1]==-1){
                d[U.find(y)][1]=y;
            }
        }
        
    }
    VI only[2],both;
    REPP(i,1,n+1){
        if(d[i][0]==-1&&d[i][1]==-1){
            return 0*puts("No");
        }
        if(d[i][0]==-1)only[1].PB(i);
        if(d[i][1]==-1)only[0].PB(i);
        if(d[i][0]>0&&d[i][1]>0)both.PB(i);
    }
    REP(i,SZ(only[0]))an.PB(MP(s,d[only[0][i]][0]));
    REP(i,SZ(only[1]))an.PB(MP(t,d[only[1][i]][1]));
    if(d_s>SZ(only[0])&&d_t>SZ(only[1])&&d_s+d_t>=SZ(only[0])+SZ(only[1])+SZ(both)+1&&SZ(both)){
        int ll=min(SZ(both),d_s-SZ(only[0]));
        REP(i,ll)an.PB(MP(s,d[both[i]][0]));
        REPP(i,ll-1,SZ(both))an.PB(MP(t,d[both[i]][1]));
    }
    else if(cc){
        an.PB(MP(s,t));
        d_s--;
        d_t--;
        if(d_s>=SZ(only[0])&&d_t>=SZ(only[1])&&d_s+d_t>=SZ(only[0])+SZ(only[1])+SZ(both)){
            int ll=min(SZ(both),d_s-SZ(only[0]));
            REP(i,ll)an.PB(MP(s,d[both[i]][0]));
            REPP(i,ll,SZ(both))an.PB(MP(t,d[both[i]][1]));
        }
        else return 0*puts("No");
    }
    else return 0*puts("No");
    puts("Yes");
    REP(i,SZ(an))printf("%d %d\n",an[i].F,an[i].S);
    return 0;
}