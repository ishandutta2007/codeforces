/*input
8
abacabca
1 2 3 4 4 3 2 1
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 7000
#define INF 0x3f3f3f3f

struct N{
    int from , to , cap , flow , cost;
};
struct MCMF{
    int s , t;
    int a[MAX] , d[MAX] , p[MAX] , inq[MAX];
    vector<int> g[MAX];
    vector<N> e;
    void ADDE(int f , int t , int c , int cost){
        g[f].pb(e.size());
        e.pb(N{f , t , c , 0 , cost});
        g[t].pb(e.size());
        e.pb(N{t , f , 0 , 0 , -cost});
    }
    int Bellmanford(int &flow , int &cost){
        MEM(d , INF) , MEM(inq , 0);
        queue<int> qu;
        a[s] = INF , d[s] = 0 , qu.push(s);
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
        // DB4("flow = " , flow , "cost =" , cost);
        return cost;
    }
} dc;
int n , x[MAX] , p[MAX];
int id[MAX] , in[MAX][30] , out[MAX];
string ss;
int32_t main(){
    IOS;
    cin >> n >> ss;
    REP(i , 1 , n + 1) p[i] = ss[i - 1] - 'a';
    REP(i , 1 , n + 1) cin >> x[i];
    int s = 0 , t = 1 , po = 2;

    REP(i , 1 , n + 1) id[i] = po ++;
    REP(i , 1 , (n / 2) + 1){
        out[i] = po ++;
        REP(j , 0 , 26){
            in[i][j] = po ++;
            dc.ADDE(in[i][j] , out[i] , 1 , 0);
        }
        dc.ADDE(out[i] , t , 2 , 0);
    }

    REP(i , 1 , n + 1){
        int res = min(i , n + 1 - i);
        dc.ADDE(s , id[i] , 1 , 0);
        REP(j , 1 , (n / 2) + 1){
            if(res == j){
                dc.ADDE(id[i] , in[j][p[i]] , 1 , -x[i]);
            }
            else {
                dc.ADDE(id[i] , in[j][p[i]] , 1 , 0);
            }
        }
    }

    cout << -dc.FLOW(s , t) << endl;
    return 0;
}