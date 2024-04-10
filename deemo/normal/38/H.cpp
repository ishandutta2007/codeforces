/*
    I found myself in Wonderland
    Get back on my feet again..
*/

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
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
//#define size(x) ((ll)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

ll n , m , g1 , g2 , s1 , s2;
const ll max_n = 52;
vector<pair<ll , ll>> ad_list[max_n];
ll d[max_n][max_n][max_n];
ll save[max_n];
bool mark[max_n];
vector<ll> dis[max_n];
set<pair<ll , ll>>	   st;

void update(ll v){
    mark[v] = 1;
    for (ll i = 0 ; i < ad_list[v].size() ; i++){
	 ll u = ad_list[v][i].first;
	 ll w = ad_list[v][i].second;
	 if (mark[u])	   continue;
	 if (save[u] == -1 || save[u] > save[v] + w){
	     if (save[u] != -1)
		  st.erase({save[u] , u});
	     save[u] = save[v] + w;
	     st.insert({save[u] , u});
	 }
    }
}

ll find_min(){
    pair<ll , ll> temp = *st.begin();
    st.erase(temp);
    return  temp.second;
}

void dijk(ll root){
    fill(mark , mark + n , 0);
    fill(save , save + n , -1);
    save[root] = 0;
    update(root);
    ll mini;

    while (!st.empty()){
	 mini = find_min();
	 update(mini);
    }
    for (ll i = 0 ; i < n ; i++){
	 if (i == root)  continue;
	 dis[root].pb(save[i]);
    }
    sort(dis[root].begin() , dis[root].end());
    dis[root].resize(unique(dis[root].begin() , dis[root].end()) - dis[root].begin());
}

bool lesss(ll min_g , ll ind , ll x){
    if (dis[min_g][0] > x)  return	true;
    if (dis[min_g][0] < x)  return	false;
    if (min_g < ind)	   return  false;
    return  true;
}

bool more(ll max_b , ll ind , ll x){
    if (dis[max_b][dis[max_b].size() - 1] < x)	return	 true;
    if (dis[max_b][dis[max_b].size() - 1] > x)	return	 false;
    if (max_b > ind)	   return  false;
    return  true;
}

ll get(ll min_g , ll max_b){
    if (lesss(min_g , max_b , dis[max_b][dis[max_b].size() - 1]))    return  0;
    
    for (ll i = 0 ; i <= n ; i++)
	 for (ll j = 0 ; j <= n ; j++)
	     for (ll w = 0 ; w <= n ; w++)
		  d[i][j][w] = 0;

    for (ll i = 0 ; i < n ; i++){
	 bool fg , fs , fb;
	 fg = fs = fb = 0;
	 for (ll j = 0 ; j < dis[i].size() ; j++){
	     if (i == min_g){
		  fg = 1;
		  continue;
	     }
	     if (i == max_b){
		  fb = 1;
		  continue;
	     }
	     if (lesss(min_g , i , dis[i][j]))    fg = 1;
	     if (more(max_b , i , dis[i][j]))    fb = 1;
	     
	     if (dis[min_g][0] > dis[i][j])  continue;
	     if (dis[min_g][0] == dis[i][j] && min_g >= i)    continue;
	     if (dis[max_b][dis[max_b].size() - 1] < dis[i][j])	 continue;
	     if (dis[max_b][dis[max_b].size() - 1] == dis[i][j] && max_b <= i)	   continue;
	     fs = 1;
	 }    
	 if (i == 0){
	     if (fg) d[i][0][1] = 1;
	     if (fb) d[i][0][0] = 1;
	     if (fs) d[i][1][0] = 1;
	     continue;
	 }

	 for (ll s = 0 ; s <= n ; s++)
	     for (ll g = 0 ; g <= n ; g++){
		  if (fb) d[i][s][g] += d[i - 1][s][g];
		  if (fs && s > 0) d[i][s][g] += d[i - 1][s - 1][g];
		  if (fg && g > 0) d[i][s][g] += d[i - 1][s][g - 1];
	     }	  
    }
    ll ret = 0;
    for (ll i = g1 ; i <= g2 ; i++)
	 for (ll j = s1 ; j <= s2 ; j++)
	     ret += d[n - 1][j][i];	 
    return  ret;
}
    
int main(){
    read_fast;
    {
	 cin >> n >> m;
	 ll a , b , c;
	 for (ll i = 0 ; i < m ; i++){
	     cin >> a >> b >> c;
	     a--;    b--;
	     ad_list[a].push_back({b , c});
	     ad_list[b].push_back({a , c}); 
	 }
    }
    {
	 for (ll i = 0 ; i < n ; i++)
	     dijk(i);
	 cin >> g1 >> g2;
	 cin >> s1 >> s2;
    }
    ll ans = 0;
    for (ll i = 0 ; i < n ; i++)
	 for (ll j = 0 ; j < n ; j++){
	     if (i == j) continue;
	     ll t = get(i , j);
	     ans += t;
	 }
    cout << ans << endl;
    return 0;
}