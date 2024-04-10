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
const int SIZE = 3e5+10;
set<int>e[SIZE];
int used[SIZE];
int bfs[SIZE],from[SIZE],v[SIZE],p[SIZE],cnt[SIZE],an[SIZE];
VI res[SIZE+SIZE];
bool solve(int n){
    bfs[0]=1;
    int rr=1;
    cnt[0]=1;
    used[1]=1;
    REP(i,rr){
        int x=bfs[i];
        for(auto it=e[x].begin();it!=e[x].end();it++){
            int y=*it;
            if(used[y])continue;
            used[y]=1;
            from[y]=x;
            bfs[rr++]=y;
            v[y]=v[x]+1;
            cnt[v[y]]++;
        }
    }
    int now=bfs[n-1];
    p[0]=1;
    while(now!=1){
        p[v[now]]=now;
        now=from[now];
    }
    an[1]=SIZE;
    REPP(i,2,n+1){
        if(v[i]!=1){
            if(i==p[v[i]]||e[i].count(p[v[i]]))an[i]=SIZE+v[i];
            else an[i]=SIZE-v[i];
        }
    }
    if(!p[2]){
        int one=0;
        REPP(i,2,n+1){
            if(SZ(e[i])==n-1)an[i]=SIZE;
            else{
                if(!one){
                    one=i;
                    an[i]=SIZE+1;
                }
                else{
                    if(e[i].count(one))
                        an[i]=SIZE+1;
                    else
                        an[i]=SIZE-1;
                }
            }
        }
    }
    else{
        REPP(i,2,n+1){
            if(v[i]==1){
                if(e[i].count(p[2])){
                    an[i]=SIZE+1;
                }
                else if(!e[i].count(p[1])){
                    an[i]=SIZE-1;
                }
                else an[i]=SIZE;
            }
        }
    }
    REPP(i,1,n+1){
        res[an[i]].PB(i);
    }
    REPP(i,1,n+1){
        int me=an[i];
        int sum=0;
        REPP(j,-1,2){
            sum+=SZ(res[me+j]);
            REP(k,SZ(res[me+j])){
                int you=res[me+j][k];
                if(you==i)continue;
                if(!e[i].count(you))return 0;
            }
        }
        if(sum-1!=SZ(e[i]))return 0;
    }
    puts("YES");
    REPP(i,1,n+1)printf("%d ",an[i]);
    return 1;
}
int main(){
    DRII(n,m);
    if(n*(n-1LL)/2==m){
        puts("YES");
        REPP(i,1,n+1)printf("1 ");
        return 0;
    }
    REP(i,m){
        DRII(x,y);
        e[x].insert(y);
        e[y].insert(x);
    }
    if(!solve(n))puts("NO");
    return 0;
}