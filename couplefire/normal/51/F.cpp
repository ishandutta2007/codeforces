#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define ld long double
#define mp make_pair
using namespace std;
 
const int maxn = 2e3 + 1 , inf = 1e9;
int n , m , ans , n_tree , Lev[maxn] , maxi[maxn] , dp1[maxn] , dp2[maxn];
bool mark[maxn] , mark_make[maxn]; 
vector <int> e[maxn] , e_tree[maxn] , ras;
 
void dfs(int v , int p){
	maxi[v] = Lev[v];
	mark[v] = 1;
	for (auto u : e[v]){
		if (u != p){
			if (mark[u] == 0){
				Lev[u] = Lev[v] + 1;
				dfs(u , v);
				maxi[v] = min(maxi[u] , maxi[v]);
			}
			else {
				if (Lev[u] < Lev[v]){
					maxi[v] = min(Lev[u] , maxi[v]);
				}
			}
		}
	}
	ras.push_back(v);
	return ;
}
 
void dfs_make(int v , int id){
	mark_make[v] = 1;
	for (auto u : e[v]){
		if (mark_make[u] == 0){
			if (maxi[u] <= Lev[v]){
				dfs_make(u , id);
			}
			else{
				n_tree++;
				e_tree[id].push_back(n_tree);
				e_tree[n_tree].push_back(id);
				//cout << id << " " << n_tree << endl;
				dfs_make(u , n_tree);
			}
		}
	}
	return;
}
 
void dfs_tree(int v, int p){
	int child = 0;
	dp1[v] = inf;
	dp2[v] = 0;
	for (auto u : e_tree[v]){
		if (u != p){
			dfs_tree(u , v);
			dp2[v] += dp2[u] + 1;
			child ++;
		}
	}
	
	if (child == 0){
		dp1[v] = 0;
		dp2[v] = -1;
	}
 
	else{
		for (auto u : e_tree[v]){
			if (u != p){
				dp1[v] = min(dp1[v] , dp2[v] - (dp2[u] + 1) + dp1[u]);
			}
		}
	}
 
	return ;
}
 
int check(int v){
	int res = 0;
 
	dfs(v , 0);
 
	n_tree = 1;
	dfs_make(v , 1);
	res += ras.size() - n_tree;
 
	int mini = inf;
	for (int i = 1 ; i <= n_tree ; i++){
		dfs_tree(i , 0);
		mini = min(mini , dp1[i]);
	}
 
 
	res += mini;
 
	for (int i = 1 ; i <= n_tree ; i++){
		e_tree[i].clear();
	}
	ras.clear();	
 
 
	return res;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	cin >> n >> m;
 
	for (int i = 1; i <= m ; i++){
		int t1 , t2;
		cin >> t1 >> t2;
 
		e[t1].push_back(t2);
		e[t2].push_back(t1);
	}
 
	for (int i = 1 ; i <= n ; i++){
		if (mark[i] == 0){
			ans += check(i);
			if (i!= 1){
				ans ++;
			}
		}
	}
 
	cout << ans << endl;
 
	return 0;
}