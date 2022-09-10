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
VI e[SIZE];
int a[SIZE];
bool compare(int x,int y){
    return SZ(e[x])<SZ(e[y]);
}
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
bool kerker[SIZE],can[SIZE];
int main(){
    DRIII(N,M,K);
    int ban_one=0;
    REP(i,M){
        DRII(x,y);
        x--;y--;
        e[x].PB(y);
        e[y].PB(x);
        if(x==0||y==0)ban_one++;
    }
    REP(i,N)sort(ALL(e[i]));
    if(N-1-ban_one<K)return 0*puts("impossible");
    REP(i,N)a[i]=i;
    sort(a+1,a+N,compare);
    U.init(N);
    REPP(i,1,min(50,N)){
        if(i>1&&SZ(e[a[i]])+SZ(e[a[i-1]])>=N)break;
        int me=a[i];
        if(i>1)U.uu(me,a[i-1]);
        int it=0;
        REP(j,N){
            if(j==me)continue;
            if(it<SZ(e[me])&&e[me][it]==j){
                it++;
                continue;
            }
            kerker[j]=1;
            if(j)U.uu(me,j);
        }
    }
    REPP(i,1,N){
        if(!kerker[i]){
            int me=i;
            int it=0;
            REP(j,N){
                if(j==me)continue;
                if(it<SZ(e[me])&&e[me][it]==j){
                    it++;
                    continue;
                }
                if(j)U.uu(me,j);
            }
        }
    }
    {
        int me=0;
        int it=0;
        REP(j,N){
            if(j==me)continue;
            if(it<SZ(e[me])&&e[me][it]==j){
                it++;
                continue;
            }
            can[U.find(j)]=1;
        }
    }
    int ha=0;
    REPP(i,1,N){
        if(U.find(i)==i){
            ha++;
            if(!can[i])return 0*puts("impossible");
        }
    }
    if(ha>K)puts("impossible");
    else puts("possible");
    return 0;
}