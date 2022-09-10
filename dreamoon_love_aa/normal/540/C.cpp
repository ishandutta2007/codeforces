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
const int SIZE = 510;

struct Union_Find{
    int d[SIZE*SIZE],num[SIZE*SIZE];
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
int n,m;
int get(int x,int y){
    return x*m+y;
}
bool Out(int x,int y){
    return x<0||y<0||x>=n||y>=m;
}
char s[SIZE][SIZE];
int sx,sy,ex,ey;
bool valid(int x,int y){
    if(Out(x,y))return 0;
    if(x==sx&&y==sy)return 1;
    if(x==ex&&y==ey)return 1;
    return s[x][y]=='.';
}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    RII(n,m);
    U.init(n*m);
    REP(i,n)RS(s[i]);
    RII(sx,sy);
    RII(ex,ey);
    sx--;sy--;
    ex--;ey--;
    if(MP(sx,sy)==MP(ex,ey)){
        REP(i,4){
            int nx=sx+dx[i];
            int ny=sy+dy[i];
            if(Out(nx,ny))continue;
            if(s[nx][ny]=='.'){
                puts("YES");
                return 0;
            }
        }
        puts("NO");
    }
    else{
        REP(i,n)REP(j,m){
            if(!valid(i,j))continue;
            REP(k,4){
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(valid(nx,ny))U.uu(get(i,j),get(nx,ny));
            }
        }
        if(U.find(get(sx,sy))!=U.find(get(ex,ey))){
            puts("NO");
            return 0;
        }
        if(s[ex][ey]=='X')puts("YES");
        else{
            int cnt=0;
            REP(i,4){
                int nx=ex+dx[i];
                int ny=ey+dy[i];
                if(Out(nx,ny))continue;
                if(s[nx][ny]=='.'||(nx==sx&&ny==sy))cnt++;
            }
            if(cnt>=2)puts("YES");
            else puts("NO");
        }
    }
    return 0;
}