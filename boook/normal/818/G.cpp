/*input
5
1 3 5 7 9
*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100090
#define INF 0x3f3f3f3f

int ccnt = 0;
struct N{
    int from , to , cap , flow , cost;
};
struct MCMF{
    int s , t;
    int a[MAX] , d[MAX] , p[MAX] , inq[MAX];
    vector<int> g[MAX];
    vector<N> e;
    int ADDE(int f , int t , int c , int cost){
        ccnt ++;
        g[f].pb(e.size());
        e.pb(N{f , t , c , 0 ,  cost});
        g[t].pb(e.size());
        e.pb(N{t , f , 0 , 0 , -cost});
        return e.size() - 2;
    }
    int Bellmanford(int &flow , int &cost){
        MEM(inq , 0) , MEM(d , INF);
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
    int FLOW(int s , int t){
        this -> s = s , this -> t = t;
        int flow = 0 , cost = 0;
        while(Bellmanford(flow , cost));
        return cost;
    }
} dc;
int n , x[MAX] , idx[MAX][2] , mod[MAX] , m[MAX] , v[MAX];
int32_t main(){
    IOS;
    cin >> n;
    int S = 0 , s = 1 , t = 2 , pos = 3;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) REP(j , 0 , 2) idx[i][j] = pos ++; 
    REP(i , 1 , n + 1) mod[i] = pos ++;


    dc.ADDE(s , S , 4 , 0);
    REP(i , 1 , n + 1) dc.ADDE(S , idx[i][0] , 1 , 0);
    REP(i , 1 , n + 1) dc.ADDE(idx[i][0] , idx[i][1] , 1 , -1);
    REP(i , 1 , n + 1) dc.ADDE(idx[i][0] , idx[i][1] , INF , 0);
    REP(i , 1 , n + 1) dc.ADDE(idx[i][1] , t , 1 , 0);

    RREP(i , n , 1){
        if(v[x[i] + 1] != 0) dc.ADDE(idx[i][1] , idx[v[x[i] + 1]][0] , INF , 0);
        if(v[x[i] - 1] != 0) dc.ADDE(idx[i][1] , idx[v[x[i] - 1]][0] , INF , 0);
        if(v[x[i] + 0] != 0) dc.ADDE(idx[i][1] , idx[v[x[i] + 0]][1] , INF , 0);

        dc.ADDE(idx[i][1] , mod[i] , INF , 0);
        // if(m[x[i] % 7] != 0) dc.ADDE(idx[i][1] , mod[x[i] % 7] , INF , 0);
        if(m[x[i] % 7] != 0) dc.ADDE(idx[i][1] , idx[m[x[i] % 7]][0] , INF , 0);

        m[x[i] % 7] = i;
        v[x[i]] = i;
    }
    // DBGG("pos = " , pos);
    // DBGG("ccnt = " , ccnt);
    cout << -dc.FLOW(s , t) << endl;
    return 0;
}