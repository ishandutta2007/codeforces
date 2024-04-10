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
bitset<59>p;
vector<int>pp;
int a[111],o[111];
int used[111];
int d[111];
int coo[111];
int an[111];
int n;
int mi;
void dfs(int x,int m){
    if(x==SZ(pp)){
        int bb=min(n,18);
        memcpy(coo+n-bb,d+n-bb,sizeof(int)*bb);
        sort(coo+n-bb,coo+n);
        int now=0;
        REP(i,bb)now+=abs(coo[n-i-1]-a[n-i-1]);
        if(now<mi){
            memcpy(an,coo,sizeof(int)*n);
            mi=now;
        }
        return;
    }
    dfs(x+1,m);
    int tmp=d[n-1-m];
    if(m<n){
        for(;;){
            d[n-1-m]*=pp[x];
            if(d[n-1-m]>59)break;
            dfs(x+1,m+1);
        }
        d[n-1-m]=tmp;
    }
    REP(i,m){
        tmp=d[n-1-i];
        for(;;){
            d[n-1-i]*=pp[x];
            if(d[n-1-i]>59)break;
            dfs(x+1,m);
        }
        d[n-1-i]=tmp;
    }
}
int main(){
    mi=1e9;
    REPP(i,2,59){
        if(!p[i])
            for(int j=i+i;j<59;j+=i)p[j]=1;
    }
    REPP(i,2,59)
        if(!p[i])pp.PB(i);
    RI(n);
    REP(i,n){
        RI(a[i]);
        o[i]=a[i];
    }
    REP(i,n)coo[i]=d[i]=1;
    sort(a,a+n);
    dfs(0,0);
    REP(i,n){
        if(i)putchar(' ');
        REP(j,n){
            if(o[i]==a[j]&&!used[j]){
                used[j]=1;
                printf("%d",an[j]);
                break;
            }
        }
    }
    puts("");
    return 0;
}