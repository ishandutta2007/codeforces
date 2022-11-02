#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
typedef long long LL;
typedef pair<int , int> PII;
#define REP(i,j)      for(int i=0;i<j;i++)
#define REPNM(i,j,k)  for(int i=j;i<k;i++)
#define RREP(i,j,k)   for(int i=j;i>=k;i--)
#define MEM(i,j)      memset(i,j,sizeof i)
#define DB() if(debug)
#define DBGG(a,b)      if(debug)cout<<a<<" = "<<b<<endl;
#define DB4(a,b,c,d)   if(debug)cout<<a<<" = "<<b<<"\t\t"<<c<<" = "<<d<<endl;
#define HERE()          if(debug)puts("Here");
#define RI(i)        scanf("%d",&i)
#define RII(i,j)     scanf("%d%d",&i,&j)
#define RIII(i,j,k)  scanf("%d%d%d",&i,&j,&k)
#define RLL(i) scanf("%lld",&i)
#define ALL(i) i.begin(),i.end()
#define pb push_back
#define mp make_pair
#define A  first
#define B  second
 
//  / ----------- default code ----------------
#define MAX   300090
#define INF   0x3f3f3f3f
#define debug 1
 
int use[MAX] , scc[MAX] , sccpo;
vector<int> G[MAX] , G2[MAX] , p;

void DFSA(int now){
    if(use[now])return ;
    use[now] = 1;
    REP(i,G[now].size())DFSA(G[now][i]);
    p.pb(now);
}
void DFSB(int now){
    if(scc[now])return;
    scc[now] = sccpo;
    REP(i,G2[now].size())DFSB(G2[now][i]);
}
int E(int a , int b){
    // DBGG(a , b); B
    G[a].pb(b) , G2[b].pb(a);
}

int x[MAX] , n , m;
int sw[MAX][2];

int ADD(int c , int a , int b){
    if(c == 0){
        E(a , b) , E(b , a);
        E(a + m , b + m) , E(b + m , a + m);
    }
    if(c == 1){
        E(a + m , b) , E(b + m , a);
        E(a , b + m) , E(b , a + m);
    }
}

int main()
{
    RII(n , m);
    MEM(sw , -1);
    REPNM(i , 1 , n + 1) RI(x[i]);

    REP(i , m){
        int q , w;
        RI(q);
        REP(j , q){
            RI(w);
            if(sw[w][0] == -1) sw[w][0] = i + 1;
            else sw[w][1] = i + 1;
        }
    }



    REPNM(i , 1 , n + 1){
        if(x[i] == 1) ADD(0 , sw[i][0] , sw[i][1]);
        else ADD(1 , sw[i][0] , sw[i][1]);
    }



    REPNM(i , 1 , m * 2 + 1) DFSA(i);

    RREP(i , p.size() - 1 , 0){
            int now = p[i];
            sccpo++; DFSB(now);
    }
    int ok = 1;
    REPNM(i , 1 , m + 1)
        if(scc[i] == scc[i + m]) ok = 0;
 
    if(ok)puts("YES");
    else puts("NO");

    return 0;
}