#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 30000
#define INF 0x3f3f3f3f

class E
{
    public:
        int from , to , flow , cap , cost;
        E(int fr , int t , int fl , int ca , int co)
        { from = fr , to = t , flow = fl,cap = ca , cost=co; }
};
vector<E> edge;
vector<int> ecnt[MAX];
int d[MAX] , p[MAX] , a[MAX] , inq[MAX];  
void AddE(int from , int to , int cap , int cost)
{
    edge.pb(E(from , to , 0 , cap , cost));
    edge.pb(E(to , from , 0 , 0 , -cost));
    ecnt[from].pb(edge.size() - 2);
    ecnt[to].pb(edge.size() - 1);
}
bool BellmanFord(int s,int t,int& flow,int& cost){
    memset(d,0x3f3f3f3f,sizeof(d));
    memset(inq,0,sizeof(inq));
    d[s] = 0;   a[s] = 0x3f3f3f3f;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int x = q.front(); q.pop();
        inq[x] = 0;
        for(int i=0;i<ecnt[x].size();i++){
            E& e = edge[ecnt[x][i]];
            if(e.cap > e.flow && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                p[e.to] = ecnt[x][i];
                a[e.to] = min(a[x],e.cap-e.flow);
                if(!inq[e.to]){ inq[e.to] = 1; q.push(e.to);}
            }
        }
    }
    if(d[t]==0x3f3f3f3f) return false;
    flow += a[t];
    cost += d[t] * a[t];
    for(int u=t; u!=s ; u=edge[p[u]].from){
        edge[p[u]].flow += a[t];
        edge[p[u]^1].flow -= a[t];
    }
    return true;
}
void MinCMaxF(int s , int t , int &cost , int &flow)
{
    while(BellmanFord(s,t,flow,cost));
}
int n , m , l[MAX] , r[MAX];
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) l[i] = 1 , r[i] = n;
    REP(i , 1 , m + 1){
        int q , w , e , x;
        cin >> q >> w >> e >> x;
        REP(j , w , e + 1){
            if(q == 1) l[j] = max(l[j] , x);
            if(q == 2) r[j] = min(r[j] , x);
        }
    }
    int N = n + 2;
    REP(i , 1 , n + 1){
        AddE(0 , i , 1 , 0);
        REP(j , l[i] , r[i] + 1) AddE(i , N + j , 1 , 0);
    }
    REP(i , 1 , n + 1){
        REP(j , 1 , 55){
            AddE(N + i , n + 1 , 1 , j * j - (j - 1) * (j - 1));
        }
    }
    int x = 0 , y = 0;
    MinCMaxF(0 , n + 1 , x , y);
    if(y != n) cout << -1 << endl;
    else cout << x << endl;
    return 0;
}