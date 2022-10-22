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

using namespace std;

typedef long long ll;
//#define size(x) ((ll)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

struct Ramp{
    ll x , d , t , p , num;
};

ll n , l , t;
vector<Ramp>	  vec;
const ll max_n = 5e6;
map<ll , ll>   mp;
vector<pair<ll , ll>> ad_list[max_n];
vector<ll> vertices;
set<pair<ll , ll>>    st;
ll save[max_n] , par[max_n];
bool mark[max_n];

bool help(Ramp a , Ramp b){ return  a.x < b.x; }

void update(ll v){
    for (ll i = 0 ; i < ad_list[v].size() ; i++){
        ll u = ad_list[v][i].first;
        ll w = ad_list[v][i].second;
        if (mark[u])    continue;
        if (save[u] == -1 || save[u] > save[v] + w){
            if (save[u] != -1)
                st.erase({save[u] , u});
            save[u] = save[v] + w;
            st.insert({save[u] , u});
            par[u] = v;
        }
    }
}

ll find_min(){
    pair<ll , ll> temp = *st.begin();
    st.erase(temp);
    mark[temp.second] = 1;
    return  temp.second;
}

void dijkstra(ll v){
    memset(save , -1 , max_n - 10);
    memset(par , -1 , max_n - 10);
    memset(mark , 0 , max_n - 10);
    mark[v] = 1;
    save[v] = 0;
    update(v);
    ll mini = 0;
    
    while ((mini = find_min()) != t - 1){
        update(mini);
        if (st.empty()) return;
    }
}

int main(){
    read_fast;
    cin >> n >> l;
    Ramp temp;
    vertices.pb(0);
    vertices.pb(l);
    for (ll i = 0 ; i < n ; i++){
        cin >> temp.x >> temp.d >> temp.t >> temp.p;
        temp.num = i + 1;
        vec.pb(temp);
        vertices.pb(temp.x);
        vertices.pb(temp.x + temp.d);
        if (temp.x >= temp.p)   vertices.pb(temp.x - temp.p);
    }
    sort(vertices.begin() , vertices.end());
    unique(vertices.begin() , vertices.end());
    for (ll i = 0 ; i < vertices.size() ; i++){
        if (i != 0 && vertices[i] <= vertices[i - 1]){
            vertices.resize(i);
            break;
        }
        mp[vertices[i]] = (i);
    }
    
    for (ll i = 0 ; i < vertices.size() - 1 ; i++){
        ad_list[i].pb({i + 1 , vertices[i + 1] - vertices[i]});
        ad_list[i + 1].pb({i , vertices[i + 1] - vertices[i]});
    }
    t = vertices.size();
    sort(vec.begin() , vec.end() , help);
    reverse(vec.begin() , vec.end());
    for (ll i = 0 ; i < vec.size() ; i++){
        vertices.pb(vec[i].x);
        ad_list[i + t].pb({mp[vec[i].x + vec[i].d] , vec[i].t});
        if (vec[i].x >= vec[i].p)
            ad_list[mp[vec[i].x - vec[i].p]].pb({i + t , vec[i].p});
    }
    dijkstra(0);
    cout << save[t - 1] << endl;
    ll g = t - 1;
    stack<ll>  mystack;
    while (g != -1){
        if (g >= t) mystack.push(vec[g - t].num);
        g = par[g];
    }
    cout << mystack.size() << endl;
    while (!mystack.empty()){
        cout << mystack.top() << endl;
        mystack.pop();
    }
    return 0;
}