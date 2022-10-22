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

struct Thing{
    ll first , second , type;
};
    
const int max_n = 2 * 1e5 + 200;
ll save[max_n] , par[max_n] , t[max_n] , mark[max_n];
bool operator <(Thing a , Thing b){
    if (a.second < b.second)    return  true;
    if (a.second == b.second && a.type > b.type)    return  true;
    if (a.second == b.second && a.type == b.type && a.first < b.first)  return  true;
    return  false;
}

bool operator <(pair<ll , ll> a , pair<ll , ll> b){
    if (a.second < b.second)    return  true;
    if (a.second == b.second && a.first < b.first)  return  true;
    return  false;
}

ll n , m;
vector<pair<ll , ll>> ans1;
vector<ll>  vec[max_n];
set<Thing>	   st;
set<pair<ll , ll>>	   z;
map<pair<ll , ll> , bool>	   mp;

const ll q = 1e5 + 10;

void init(){
    for (ll i = 0 ; i < n ; i++){
	 save[i] = -1;
	 par[i] = -1;
	 t[i] = -1;
    }
    save[0] = 0;
    mark[0] = 1;	   
    Thing temp;
    for (ll i = 0 ; i < vec[0].size() ; i++){
	 save[vec[0][i]] = 1; 
	 t[vec[0][i]] = mp[{0 , vec[0][i]}];
	 temp.first = vec[0][i];	  temp.second = 1;	
	 temp.type = t[vec[0][i]];
	 st.insert(temp);
	 par[vec[0][i]] = 0;
    }
}

ll find_min(){
    Thing temp = *st.begin();
    st.erase(temp);
    mark[temp.first] = 1;
    return  temp.first;
}

void update(ll v){
    Thing y;
    ll temp , w;
    for (ll i = 0 ; i < vec[v].size() ; i++){
	 temp = vec[v][i];
	 if (mark[temp] != 0)    continue;
	 if (save[temp] == -1 || (save[temp] > 1 + save[v] || (save[temp] == 1 + save[v] && (t[v] + int(mp[{v , temp}])) > t[temp]))){
	     y.first = temp;	    y.second = save[temp];	    y.type = t[temp];
	     st.erase(y);
	     save[temp] = save[v] + 1;
	     y.second = save[temp];	     
	     if (mp[{temp , v}] == 0)   t[temp] = t[v];
	     else    t[temp] = t[v] + 1;
	     y.type = t[temp];
	     st.insert(y);
	     par[temp] = v;
	 }
    }
}

void dijk(){
    init();    
    if (n == 1) return;
    ll mini;

    while ((mini = find_min()) != n - 1)
	 update(mini);

    while (par[mini] != -1){
	 z.erase({mini , par[mini]});
	 z.erase({par[mini] , mini});
	 if (mp[{par[mini] , mini}] == 0)
	     ans1.push_back({par[mini] , mini});
	 mini = par[mini];
    }

}

int main(){
    cin >> n >> m;
    ll a , b , type;
    for (ll i = 0 ; i < m ; i++){
	 cin >> a >> b >> type;
	 a--;	  b--;
	 if (type == 1)  z.insert({a , b});
	 vec[a].push_back(b);
	 vec[b].push_back(a);
	 mp[{a , b}] = type;
	 mp[{b , a}] = type;
    }
    dijk();
    //cout << save[n - 1] << endl;
    cout << ans1.size() + z.size() << endl;
    for (ll i = 0 ; i < ans1.size() ; i++)
	 cout << ans1[i].first + 1 << " " << ans1[i].second + 1 << " " << 1 << endl;
    
    pair<ll , ll> c;
    while (!z.empty()){
	 c = *z.begin();
	 cout << c.first + 1 << " " << c.second + 1 << " " << 0 << endl;
	 z.erase(c);
    }
    return 0;
}