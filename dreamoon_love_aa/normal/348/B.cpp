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
const long long INF = (long long)1e18;
vector<int>e[SIZE];
int n,num[SIZE];
long long a[SIZE],gg[SIZE],res,ma[SIZE];
long long lcm(long long x,long long y){
    if(x==INF||y==INF)return INF;
    x=x/__gcd(x,y);
    if(x>INF/y)return INF;
    return x*y;
}
void dfs0(int x,int last){
    if(SZ(e[x])==1&&e[x][0]==last){
        gg[x]=1;
        return;
    }
    num[x]=0;
    gg[x]=1;
    REP(i,SZ(e[x])){
        if(last==e[x][i])continue;
        dfs0(e[x][i],x);
        a[x]+=a[e[x][i]];
        num[x]++;
        gg[x]=lcm(gg[x],gg[e[x][i]]);
    }
    gg[x]=min(INF,gg[x]*num[x]);
}
bool dfs(int x,int last,long long v){
    if(a[x]<v)return false;
    REP(i,SZ(e[x])){
        if(last==e[x][i])continue;
        if(!dfs(e[x][i],x,v/num[x]))return false;
    }
    return true;
}
int main(){
    RI(n);
    REPP(i,1,n+1)scanf("%I64d",&a[i]);
    REPP(i,1,n){
        DRII(x,y);
        e[x].PB(y);
        e[y].PB(x);
    }
    dfs0(1,0);
    if(gg[1]==INF){
        cout<<a[1]<<endl;
    }
    else{
        long long ll=0,rr=INF/gg[1];
        while(ll<rr){
            long long mm=(ll+rr+1)>>1;
            long long NOW=mm*gg[1];
            if(dfs(1,0,NOW))ll=mm;
            else rr=mm-1;
        }
        cout<<a[1]-ll*gg[1]<<endl;
    }
    return 0;
}