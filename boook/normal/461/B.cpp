#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
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
//#define RLL(i) scanf("%I64d",&i)
#define RLL(i) scanf("%I64d",&i)
#define ALL(i) i.begin(),i.end()
#define pb push_back
#define mp make_pair
#define A  first
#define B  second

//  / ----------- default code ----------------
#define MAX   100900
#define INF   0x3f3f3f3f
#define debug 1
#define MOD 1000000007

vector<LL> v[MAX];
LL color[MAX] , b[MAX] , w[MAX];
LL SUM(LL now){
    return (b[now] + w[now]) % MOD;
}
LL mypow(LL a , LL b){
    LL res = a , ans = 1;
    while(b > 0){
        if(b&1)ans = ans * res %MOD;
        res = res * res % MOD;
        b >>= 1;
    }
    return ans%MOD;
}
LL DIV(LL a , LL b){
    a = (a * (mypow(b , MOD - 2) % MOD)) % MOD;
//    return a/b;
    return a;
}
void DFS(LL now){
//    DBGG("now" , now);
    if(v[now].empty()){
        if(color[now]) b[now] = 1 , w[now] = 0;
        else b[now] = 0 , w[now] = 1;
//        printf("b[%d] = %d \t w[%d] = %d\n", now , b[now] , now , w[now]);
        return ;
    }
    else if(!color[now]){ /// white
        LL sum = 1;
        REP(i,v[now].size()){
            LL to = v[now][i];
            DFS(to);
            sum = ( sum * SUM(to) ) % MOD;
        }
        w[now] = sum;
        b[now] = 0;
        REP(i,v[now].size()){
            LL h = sum , to = v[now][i];
            h = DIV(h , SUM(to));
            b[now] = ( b[now] + (b[to] * h % MOD) ) % MOD;
        }
    }
    else if(color[now]){
        LL sum = 1;
        REP(i,v[now].size()){
            LL to = v[now][i];
            DFS(to);
            sum = ( sum * SUM(to) ) % MOD;
        }
        b[now] = sum;
        w[now] = 0;
    }
//    printf("b[%d] = %d \t w[%d] = %d\n", now , b[now] , now , w[now]);
}
int main(){
    LL t , qc;
    RLL(t);
    REPNM(i,1,t){
        RLL(qc) , v[qc].pb(i);
    }
    REP(i,t) RLL(color[i]);
    DFS(0);
    printf("%I64d\n",b[0]);

    return 0;
}