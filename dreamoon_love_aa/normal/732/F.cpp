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
const int SIZE = 4e5+10;

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
VI e[SIZE];
int input[SIZE][2];
bool used[SIZE];
int odr[SIZE],bk[SIZE],id;
set<PII>bridge,res;
void dfs(int x,int lt){
    odr[x]=id++;
    bk[x]=1e9;
    used[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        if(used[y]){
            bk[x]=min(bk[x],odr[y]);
        }
        else{
            dfs(y,x);
            if(bk[y]>odr[x]){
                if(x<y)
                    bridge.insert(MP(x,y));
                else
                    bridge.insert(MP(y,x));
            }
            bk[x]=min(bk[x],bk[y]);
        }
    }
}
bool lin[SIZE];
void dfs_final(int x,int lt){
    used[x]=1;
    lin[x]=1;
    REP(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        if(used[y]){
            if(lin[y])res.insert(MP(y,x));
        }
        else{
            dfs_final(y,x);
            res.insert(MP(y,x));
        }
    }
    lin[x]=0;
}
int main(){
    DRII(n,m);
    REP(i,m){
        RII(input[i][0],input[i][1]);
        e[input[i][0]].PB(input[i][1]);
        e[input[i][1]].PB(input[i][0]);
    }
    dfs(1,1);
    U.init(n+1);
    REP(i,m){
        if(input[i][0]<input[i][1]){
            if(!bridge.count(MP(input[i][0],input[i][1])))
                U.uu(input[i][0],input[i][1]);
        }
        else{
            if(!bridge.count(MP(input[i][1],input[i][0])))
                U.uu(input[i][0],input[i][1]);
        }
    }
    int ma=0,root=0;
    REPP(i,1,n+1){
        if(U.d[i]==i){
            if(U.num[i]>ma){
                ma=U.num[i];
                root=i;
            }
        }
    }
    printf("%d\n",U.num[root]);
    MS0(used);
    dfs_final(root,root);
    REP(i,m){
        if(res.count(MP(input[i][0],input[i][1])))
            printf("%d %d\n",input[i][0],input[i][1]);
        else
            printf("%d %d\n",input[i][1],input[i][0]);
    }
    return 0;
}