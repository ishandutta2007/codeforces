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
#define MAX 
#define INF 0x3f3f3f3f

int n;
map<int , int> a , b;
vector<int> c , d;
set<int> cc;
vector<PII> vv;
set<int> use;
void DFS(int now){
	// DBGG("DFS = " , now);
	if(use.find(now) != use.end()) return ;
	use.insert(now);
	if(a.find(now) != a.end()) DFS(a[now]);
	d.pb(now);
}
int32_t main(){
	cin >> n;
	REP(i , 0 , n){
		int q , w;
		cin >> q >> w;
		a[q] = w , b[w] = q;
		vv.pb(mp(q , w));
	}
	if(n % 2 == 0){
		int now = 0;
		while(a.find(now) != a.end()){
			now = a[now];
			c.pb(now);
		}
		now = 0;
		while(b.find(now) != b.end()){
			now = b[now];
			d.pb(now);
		}
		int cpo = 0;
		int dpo = d.size() - 1;
		while(dpo >= 0 && cpo < c.size()){
			if(dpo >= 0) cout << d[dpo --] << " ";
			if(cpo < c.size()) cout << c[cpo ++] << " ";
		}
		cout << endl;
	}
	else {
		int now = 0;
		cc.insert(0);
		while(a.find(now) != a.end()){
			now = a[now];
			if(now) c.pb(now) , cc.insert(now);
			else break;
		}
		REP(i , 0 , vv.size()){
			if(cc.find(vv[i].A) != cc.end()) continue;
			if(use.find(vv[i].A) == use.end()) DFS(vv[i].A);
		}
		// for(auto to : c) cout << to << " " ;cout << endl;
		// for(auto to : d) cout << to << " " ;cout << endl;


		int cpo = 0;
		int dpo = d.size() - 1;
		while(dpo >= 0 || cpo < c.size()){
			if(dpo >= 0) cout << d[dpo --] << " ";
			if(cpo < c.size()) cout << c[cpo ++] << " ";
		}
		cout << endl;
	}
	
    return 0;
}