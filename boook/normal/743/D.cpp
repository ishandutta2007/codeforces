#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long LL;
//typedef pair<int , int> PII;
typedef pair<LL , LL> PII;
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
#define MAX   400900
//#define INF   0x3f3f3f3f
#define INF   120000000000000000LL
#define debug 1
#define MOD 1000000007

LL t , val[MAX];
vector<LL> v[MAX];
LL ans;

PII DFS(LL now , LL pa){   /// maxans , sumans
    priority_queue<LL , vector<LL> , greater<LL> > pq;
    LL total = 0 , maxans = -INF;
    REP(i,v[now].size()){
        LL to = v[now][i];
        if(to == pa)continue;
        PII q = DFS(to , now);
        pq.push(q.A);
        total += q.B;
        maxans = max(maxans , q.A);
        while(pq.size() > 2) pq.pop();
    }
    if(pq.size() == 2){
        LL qq = pq.top(); pq.pop();
        LL ww = pq.top(); pq.pop();
        ans = max(ans , qq + ww);
    }
    PII aaa;
    aaa.A = max(maxans , val[now] + total);
    aaa.B = total + val[now];
//    DBGG("now",now);
//    DB4("ans.A",aaa.A,"ans.B",aaa.B);
    return aaa;
}
int main(){
    while(cin >> t){
        REP(i,t) RLL(val[i]);
        LL q , w;
        REP(i,t-1)
            RLL(q) , RLL(w) , q-- , w-- , v[q].pb(w) , v[w].pb(q);
        ans = -INF;
        DFS(0,-1);
        if(ans == -INF)puts("Impossible");
        else printf("%I64d\n",ans);
        /////////INFFFFFFFFFF
    }
    return 0;
}