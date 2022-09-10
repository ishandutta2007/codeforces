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
int v[SIZE];
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
int x[SIZE];
int main(){
    DRIII(n,k,a);
    DRI(m);
    REP(i,m){
        RI(x[i+1]);
        v[x[i+1]]=1;
    }
    U.init(n+1);
    REPP(i,1,n){
        if(!v[i]&&!v[i+1])U.uu(i,i+1);
    }
    int now=0;
    REPP(i,1,n+1){
        if(!v[i]&&U.find(i)==i)now+=(U.num[i]+1)/(a+1);
    }
    if(now>=k)puts("-1");
    else{
        for(int i=m;i>0;i--){
            v[x[i]]=0;
            int me=1;
            if(!v[x[i]-1]&&x[i]>1){
                int v=U.num[U.find(x[i]-1)];
                me+=v;
                now-=(v+1)/(a+1);
                U.uu(x[i],x[i]-1);
            }
            if(!v[x[i]+1]&&x[i]<n){
                int v=U.num[U.find(x[i]+1)];
                me+=v;
                now-=(v+1)/(a+1);
                U.uu(x[i],x[i]+1);
            }
            now+=(me+1)/(a+1);
            if(now>=k)return 0*printf("%d\n",i);
        }
    }
    return 0;
}