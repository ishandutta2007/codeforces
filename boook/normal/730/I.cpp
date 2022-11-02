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
#define MAX 5000
#define INF 0x3f3f3f3f

struct N{
    int from , to , cap , flow , cost;
};
struct MCMF{
    int s , t;
    int a[MAX] , d[MAX] , p[MAX] , inq[MAX];
    vector<int> g[MAX];
    vector<N> e;
    int ADDE(int f , int t , int c , int cost){
        g[f].pb(e.size());
        e.pb(N{f , t , c , 0 , cost});
        g[t].pb(e.size());
        e.pb(N{t , f , 0 , 0 , -cost});
        return e.size() - 2;
    }
    int Bellmanford(int &flow , int &cost){
        MEM(d , INF) , MEM(inq , 0);
        queue<int> qu;
        d[s] = 0 , a[s] = INF , qu.push(s);
        while(qu.size()){
            int now = qu.front(); qu.pop();
            inq[now] = 0;
            for(auto i : g[now]){
                N to = e[i];
                if(to.cap > to.flow && d[to.to] > d[now] + to.cost){
                    a[to.to] = min(a[now] , to.cap - to.flow);
                    d[to.to] = d[now] + to.cost;
                    p[to.to] = i;
                    if(inq[to.to] == 0){
                        inq[to.to] = 1;
                        qu.push(to.to);
                    }
                }
            }            
        }
        if(d[t] == INF) return 0;
        flow += a[t];
        cost += a[t] * d[t];
        for(int i = t ; i != s ; i = e[p[i]].from){
            e[p[i] ^ 0].flow += a[t];
            e[p[i] ^ 1].flow -= a[t];
        }
        return 1;
    }
    void FLOW(int s , int t){
        this -> s = s , this -> t = t;
        int flow = 0 , cost = 0;
        while(Bellmanford(flow , cost));
        // DB4("flow = " , flow , "cost = " , cost);
    }
} dc;
int n , m , k , a[MAX] , b[MAX] , ae[MAX] , be[MAX];
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    REP(i , 1 , n + 1) cin >> a[i];
    REP(i , 1 , n + 1) cin >> b[i];
    int s = 0 , t1 = n + 1 , t2 = n + 2 , t = n + 3;

    REP(i , 1 , n + 1){
        dc.ADDE(s , i , 1 , 0);
        ae[i] = dc.ADDE(i , t1 , 1 , -a[i]);
        be[i] = dc.ADDE(i , t2 , 1 , -b[i]);
    }
    dc.ADDE(t1 , t , m , 0);
    dc.ADDE(t2 , t , k , 0);
    dc.FLOW(s , t);
    vector<int> v1 , v2;
    int cnt = 0;
    REP(i , 1 , n + 1){
        if(dc.e[ae[i]].flow) v1.pb(i) , cnt += a[i];
        if(dc.e[be[i]].flow) v2.pb(i) , cnt += b[i];
    }
    cout << cnt << endl;
    for(auto to : v1) cout << to << " "; cout << endl;

    for(auto to : v2) cout << to << " " ; cout << endl;
    return 0;
}