/*input
7 2
1 2 2 4 2 1 2
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
#define MAX 1000
#define INF 0x3f3f3f3f

struct N{ int from , to , cap , flow , cost; };
struct MCMF{
    int s , t;
    int a[MAX] , d[MAX] , p[MAX] , inq[MAX];
    vector<int> g[MAX];
    vector<N> e;
    int ADDE(int f , int t , int c , int cost){
        g[f].pb(e.size());
        e.pb(N{f , t , c , 0 ,  cost});
        g[t].pb(e.size());
        e.pb(N{t , f , 0 , 0 , -cost});
        return int(e.size()) - 2;
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
        // DB4("flow = " , flow , "cost = " , cost);
        return cost;
    }
} dc;
int n , m , x[MAX] , v[MAX];
int ss , s , t , in[MAX] , ot[MAX] , pos;
int from[MAX] , atoz[MAX];
vector<PII> ans;
int32_t main(){
	IOS;
	cin >> n >> m;
	REP(i , 1 , n + 1) cin >> x[i];
	REP(i , 1 , n + 1){
		int val = x[i];
		while(val) v[i] += val % 2 , val >>= 1;
	}

	REP(i , 1 , n + 1) in[i] = pos ++ , ot[i] = pos ++;
	ss = pos ++;
	s = pos ++ , t = pos ++;

	// REP(i , 1 , n + 1) cout << v[i] << " "; cout << endl;

	int smlval = -100;
	dc.ADDE(ss , s , m , 0);
	dc.ADDE(s , t , m , 0);
	REP(i , 1 , n + 1) dc.ADDE(s , in[i] , 1 , v[i]);
	REP(i , 1 , n + 1) dc.ADDE(ot[i] , t , 1 , 0);

	REP(i , 1 , n + 1) dc.ADDE(in[i] , ot[i] , 1 , smlval);

	REP(i , 1 , n + 1) REP(j , i + 1 , n + 1){
		// int val = x[i] ^ x[j] , cnt = 0;
		// while(val) cnt += val % 2 , val >>= 1;
		if(x[i] == x[j]) 
			 dc.ADDE(ot[i] , in[j] , 1 , 0);
		else dc.ADDE(ot[i] , in[j] , 1 , v[j]);
	}

	int ansval = dc.FLOW(ss , t) - smlval * n;

	// cout << "---" << endl;
	for(auto to : dc.e) if(to.cap != 0 && to.flow != 0 && to.cost != smlval){
		if(to.from != ss && to.to != t){
			int v1 = to.from / 2 + 1 , v2 = to.to / 2 + 1;
			if(to.from == s) v1 = 0;
			from[v2] = v1;
			// DB4(to.from / 2 + 1 , to.to / 2 + 1 , to.cost , "");
		}
	}
	// cout << "---" << endl;
	// DBGG("n = " , n);
	// REP(i , 1 , n + 1) cout << from[i] << " " ; cout << endl;
	int queuepos = 0;
	REP(i , 1 , n + 1){
		if(from[i] == 0){
			atoz[i] = queuepos++;
			ans.pb(atoz[i] , i);
			ans.pb(-1 , atoz[i]);
		}
		else{
			atoz[i] = atoz[from[i]];
			if(x[i] != x[from[i]]) ans.pb(atoz[i] , i);
			ans.pb(-1 , atoz[i]);
		}
	}
	cout << ans.size() << " " << ansval << endl;
	for(auto to : ans){
		if(to.A == -1) cout << "print(" << (char)('a' + to.B) << ")" << endl;
		else cout << (char)('a' + to.A) << "=" << x[to.B] << endl;
	}
    return 0;
}