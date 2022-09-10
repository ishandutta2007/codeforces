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
int n,m,k;
int get(int x,int y){
    return x*m+y;
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
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool Out(int x,int y){
    return x<0||y<0||x>=n||y>=m;
}
char s[55][55];
int main(){
    RIII(n,m,k);
    U.init(n*m+1);
    REP(i,n){
        RS(s[i]);
    }
    REP(i,n)REP(j,m){
        if(s[i][j]!='.')continue;
        REP(k2,4){
            int nx=i+dx[k2];
            int ny=j+dy[k2];
            if(Out(nx,ny))continue;
            if(s[nx][ny]=='.'){
                U.uu(get(i,j),get(nx,ny));
            }
        }
        if(!i||!j||i==n-1||j==m-1)U.uu(get(i,j),n*m);
    }
    VPII pp;
    REP(i,n*m){
        if(U.d[i]==i&&s[i/m][i%m]=='.'&&U.find(i)!=U.find(n*m)){
            pp.PB(MP(U.num[i],i));
        }
    }
    int an=0;
    sort(ALL(pp));
    REP(it,SZ(pp)-k){
        an+=pp[it].F;
        int x=pp[it].S;
        REP(i,n)REP(j,m){
            if(U.find(get(i,j))==x)s[i][j]='*';
        }
    }
    printf("%d\n",an);
    REP(i,n)puts(s[i]);
    return 0;
}