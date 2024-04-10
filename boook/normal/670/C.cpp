#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned long long LL;
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
#define RLLLL(i,j) scanf("%I64d%I64d",&i,&j)
#define ALL(i) i.begin(),i.end()
#define pb push_back
#define mp make_pair
#define A  first
#define B  second

/// ----------- default code ----------------
#define MAX   500900
#define MAXM  28
#define INF   0x3f3f3f3f
#define debug 1

class AC_good{
    int ch[MAX][MAXM] , sz;
    int last[MAX] , f[MAX];
    int v[MAX];
    AC_good(){
        sz = 1;
        MEM(ch[0] , 0);
    }
    int idx(char now){return now - 'a';}
    void Insert(string s , int y){
        int u = 0;
        REP(i,s.size()){
            int now = idx(s[i]);
            if(!ch[u][now]) MEM(ch[sz] , 0) , ch[u][now] = sz++;
            u = ch[u][now];
        }
        v[u] = y;
    }
    void Build_fail(){
        queue<int> qu;
        f[0] = 0;
        REP(i,MAXM){
            int to = ch[0][i];
            if(to){
                qu.push(to);
                last[to] = f[to] = 0;
            }
        }
        while(qu.size()){
            int now = qu.front(); qu.pop();
            REP(i,MAXM){
                int to = ch[now][i];
                if(!to)continue;
                qu.push(to);
                int ff = f[now];
                while(ff && !ch[now][i]) ff = f[ff];
                f[to] = ch[ff][i];
                last[to]  = v[f[to]] ? f[to] : last[f[to]];
            }
        }
    }
    void print(int now){
        if(now){
//            REP(i,v[now].size())
        }
    }
};
int t , n ;
PII x[MAX];
int main()
{
    while(~RI(t)){
        int q , qc;
        cc_hash_table<int,int> ma;
        REP(i,t) RI(q) , ma[q]++;
        RI(n);
        PII ans = mp(-1,-1);
        int po = -1;
        REP(i,n) RI(x[i].A);
        REP(i,n) RI(x[i].B);
        REP(i,n){
            PII qw = mp(ma[x[i].A] , ma[x[i].B]);
            if(qw > ans) ans = qw , po = i;
        }
        printf("%d\n",po+1);
    }
    return 0;
}