#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f

int n , nok[MAX] , g[MAX];
vector<int> v[MAX];
void DFS(int now , int fa){
	if(v[now].size() <= 2){
		nok[now] = 1;
		for(auto to : v[now]){
			if(to != fa) DFS(to , now);
		}
	}
}
int32_t main(){
	cin >> n;
	REP(i , 1 , n){
		int q , w;
		cin >> q >> w;
		v[q].pb(w) , v[w].pb(q);
	}
	REP(i , 1 , n + 1){
		if(v[i].size() == 1) DFS(i , -1);
	}
	REP(i , 1 , n + 1){
		for(auto to : v[i]){
			if(nok[to] == 1) g[i] ++;
		}
	}
	int ok = 1;
	REP(i , 1 , n + 1){
		if(nok[i] == 0){
			int cnt = 0;
			for(auto to : v[i]){
				if(nok[to] == 0){
					if(v[to].size() - 1 >= 3 || v[to].size() - 1 - g[to] >= 1) cnt ++;
				}
			}
			if(cnt > 2) ok = 0;
		}
	}
	cout << ((ok == 1) ? "Yes" : "No") << endl;
    return 0;
}