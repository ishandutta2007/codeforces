#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>

using namespace std;

typedef long long ll;
const ll max_n = 3 * 1e5;
vector<ll> vec[max_n];
vector<pair<ll , ll>> hates;
ll a , b , n , m , type , g , l;
ll col[max_n];
const ll q = 1e9 + 7;
bool flag;

void dfs(ll v , ll comp , ll t , bool y){
    if (t == 1) col[v] = comp;
    else    col[v] = ll(y) + 1;
    for (ll i = 0 ; i < vec[v].size() ; i++){
	 if (col[vec[v][i]] == 0)	 dfs(vec[v][i] , comp , t , !y);
	 else	  if (t == 2 && col[v] == col[vec[v][i]])   flag = 1;
	 if (flag)   return;
    }
}

void run_dfs(ll t){
    for (ll i = 0 ; i <= n ; i++){
	 if (t == 1 && i == n)   continue;
	 if (t == 2 && (i == 0 || i > l))  continue;
	 if (col[i])	   continue;
	 g++;
	 dfs(i , g , t , 0);
	 if (flag)   return;
    }
}

int main(){
    cin >> n >> m;
    for (ll i = 0 ; i < m ; i++){
	 cin >> a >> b >> type;
	 a--;	  b--;
	 if (a > b)  swap(a , b);
	 if (type == 1){
	     vec[a].push_back(b);
	     vec[b].push_back(a);
	 }
	 else	  hates.push_back({a , b});
    }
    run_dfs(1);
    for (ll i = 0 ; i < n ; i++)
	 vec[i].clear();
    for (ll i = 0 ; i < hates.size() ; i++){
	 pair<ll , ll> temp = hates[i];
	 if (col[temp.first] == col[temp.second]){
	     cout << 0 << endl;
	     return  0;
	 }
	 vec[col[temp.first]].push_back(col[temp.second]);
	 vec[col[temp.second]].push_back(col[temp.first]);
    }
    for (ll i = 0 ; i < n + 5 ; i++)
	 col[i] = 0;
    l = g;
    g = 0;
    run_dfs(2);
    if (flag){
	 cout << 0 << endl;
	 return  0;
    }
    ll ans = 1;
    for (ll i = 0 ; i < g - 1 ; i++){
	 ans *= 2;
	 ans %= q;
    }
    cout << ans << endl;
    return 0;
}