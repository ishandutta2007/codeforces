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
ll n , m , t1 ,t2;
bool fl;
const ll max_n = 2 * 1e5 + 100;
vector<ll> vec[max_n];
ll mark[max_n] , cnt[max_n];
ll ans , g;

void dfs(ll v , ll col , ll level){
    cnt[level] += 1;
    mark[v] = col;
    ll temp;
    for (ll i = 0 ; i < vec[v].size() ; i++){
	 temp = vec[v][i];
	 if (mark[temp] == 0){
	     if (col == 1)	dfs(temp , 2 , level + 1);
	     else    dfs(temp , 1 , level + 1);
	 }
	 else	  if (mark[temp] == mark[v])  fl = 1;
	 
	 if (fl == 1)	   return;
    }
}

ll w(ll x){
    if (x < 2)  return  0;
    return  ll(ll(x * ll(x - 1)) / ll(2));
}

ll f(ll x){
    if (cnt[x] == 0)	   return  0;

    ll t = f(x + 2);
    ans += ll(cnt[x] * t);
    ans += w(cnt[x]);
    return  t + cnt[x];
}

void get(){
    ll alaki;
    for (ll i = 0 ; i < n ; i++){
	 if (mark[i] != 0)	continue;
	 t1 = t2 = 0;
	 dfs(i , 1 , 0);
	 alaki = f(0);
	 alaki = f(1);
	 for (ll j = 0 ; cnt[j] != 0 ; j++)
	     cnt[j] = 0;
	 if (fl == 1)	   return;
    }
}

int main(){
    cin >> n >> m;
    if (m == 0){
	 cout << 3 << " ";
	 ans = ll(ll(n * ll(n - 1) * ll(n - 2)) / 6);
	 cout << ans << endl;
	 return  0;
    }

    ll a , b , flag = 0;
    for (ll i = 0 ; i < m ; i++){
	 cin >> a >> b;
	 a--;	  b--;
	 vec[a].push_back(b);
	 vec[b].push_back(a);
	 if (vec[a].size() > 1 || vec[b].size() > 1) flag = 1;
    }
    if (flag == 0){
	 cout << 2 << " ";
	 ans = ll(m * (n - 2));
	 cout << ans << endl;
	 return  0;
    }
    get();
    if (fl == 1){
	 cout << 0 << " " << 1 << endl;
	 return  0;
    }

    cout << 1 << " ";
    cout << ans << endl;

    return 0;
}