#include<bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i ++)
#define mp make_pair
#define pb push_back
#define PII pair<int , int>
#define A first
#define B second
#define MAX 100009

class djs{
public:
	int x[MAX];
	void init(){ REP(i , 0 , MAX) x[i] = i; }
	int Find(int now){ return now == x[now] ? now : x[now] = Find(x[now]); }
	void Union(int a , int b){ x[Find(a)] = Find(b); }
	int operator[](int now){ return Find(x[now]); }
} ds;
int n , m , k , ans[MAX] , a[MAX][2];
vector<PII> v[MAX];
map<PII , int> cc;
void solve(){
	ds.init();
	REP(i , 1 , m + 1){
		vector<int> sol;
		for(auto to : v[i]){
			ds.Union(to.A , to.B);
			sol.pb(to.A) , sol.pb(to.B);
		}
		sort(sol.begin() , sol.end());
		sol.resize(unique(sol.begin() , sol.end()) - sol.begin());
		if(v[i].size() > 300){
			REP(j , 0 , k){
				int q = a[j][0] , w = a[j][1];
				if(ds[q] == ds[w]) ans[j] ++;
			}
		}
		else {
			REP(ii , 0 , sol.size()){
				REP(jj , ii + 1 , sol.size()){
					if(ds[sol[ii]] == ds[sol[jj]]){
						cc[mp(sol[ii] , sol[jj])] ++;	
					}
				}
			}
		}
		for(auto to : v[i]) ds.x[to.A] = to.A , ds.x[to.B] = to.B;
	}
}
int main(){
	cin >> n >> m;
	REP(i , 0 , m){
		int a , b , c;
		cin >> a >> b >> c;
		if(a > b) swap(a , b);
		v[c].pb(mp(a , b));
	}
	cin >> k;
	REP(i , 0 , k){
		cin >> a[i][0] >> a[i][1];
		if(a[i][0] > a[i][1]) swap(a[i][0] , a[i][1]);
	}
	solve();
	REP(i , 0 , k){
		int q = a[i][0] , w = a[i][1];
		if(cc.find(mp(q , w)) != cc.end())
			ans[i] += cc[mp(q , w)];
		cout << ans[i] << " " ; cout << endl;
	}
  	return 0;
}