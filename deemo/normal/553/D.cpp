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

struct Node{
    ll a , b , num;
};

bool operator < (Node a , Node b){
    if (ll(a.a * b.b) < ll(a.b * b.a))  return  true;
    if (ll(a.a * b.b) > ll(a.b * b.a))  return  false;
    return  a.num < b.num;
}

ll n , m , k;
const ll max_n = 2 * 1e5 + 100;
vector<ll> vec[max_n];
short mark[max_n];
pair<ll , ll> save[max_n];
set<Node>   st;
set<ll>    sec;
Node mini;
vector<ll> ans;

void dfs(ll v){
    mark[v] = 1;
    ll cnt = 0;
    for (ll i = 0 ; i < vec[v].size() ; i++){
	 if (mark[vec[v][i]] == 0)
	     dfs(vec[v][i]);
	 if (mark[vec[v][i]] != 2)	 cnt++;
    }
    Node t;
    t.a = cnt;  t.b = vec[v].size();    t.num = v;
    st.insert(t);
    save[v] = {t.a , t.b};
    sec.insert(v);
}

void get(){
    Node t , temp;
    mini.a = -1;    mini.b = 1;    
    stack<ll>  p;
    bool flag;
    ll nei;
    set<ll>::iterator  it;

    for (ll i = 0 ; i < n ; i++){
	 if (mark[i] != 0)	continue;
	 flag = 0;
	 dfs(i);
	 while (!st.empty()){
	     t = *st.begin();
	     if (mini < t){
		  while (!p.empty()){
		      sec.erase(p.top());
		      p.pop();
		  }
		  mini = t;
		  flag = 1;
	     }
	     mark[t.num] = 2;
	     st.erase(t);
	     p.push(t.num);
	     for (ll j = 0 ; j < vec[t.num].size() ; j++){
		  nei = vec[t.num][j];
		  if (mark[nei] == 2) continue;
		  temp.a = save[nei].first;	  temp.b = save[nei].second;  temp.num = nei;
		  st.erase(temp);
		  save[nei].first -= 1;
		  temp.a = save[nei].first;
		  st.insert(temp);
	     }
	 }
	 if (flag == 1){
	     ans.clear();
	     while (!sec.empty()){
		  ans.push_back(*sec.begin());
		  sec.erase(*sec.begin());
	     }
	 }
	 while (!p.empty())	p.pop();
	 while (!sec.empty())    sec.erase(*sec.begin());
    }
}

int main(){
    cin >> n >> m >> k;
    ll a , b;
    for (ll i = 0 ; i < k ; i++){
	 cin >> a;
	 mark[a - 1] = 2;	 
    }
    for (ll i = 0 ; i < m ; i++){
	 cin >> a >> b;
	 a--;	  b--;
	 vec[a].push_back(b);
	 vec[b].push_back(a);
    }
    
    get();
    cout << ans.size() << endl;
    for (ll i = 0 ; i < ans.size() ; i++){
	 if (i == ans.size() - 1)	 cout << ans[i] + 1 << endl;
	 else	  cout << ans[i] + 1 << " ";
    }
    return 0;
}