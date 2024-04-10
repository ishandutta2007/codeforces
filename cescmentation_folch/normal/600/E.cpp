#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef map<ll, ll> mi;
typedef pair<ll, ll> pi;
typedef set<pi> spi;
typedef vector<ll> vi;
typedef vector<vi> vvi;

struct node{
  mi colo;
  spi num;
};

vvi G;
vi C;
vi R;
vi V;

node dfs(int x){
  V[x] = 1;
  node tt;
  tt.colo[C[x]] = 1;
  tt.num.insert(pi(1, C[x]));
  
  for(int i = 0; i < G[x].size(); ++i){
    int y = G[x][i];
    if(V[y]) continue;
    node tt2 = dfs(y);
    
    if(tt2.colo.size() > tt.colo.size()) swap(tt, tt2);
    
    for(mi::iterator it = tt2.colo.begin(); it != tt2.colo.end(); ++it){
      ll c = it -> first;
      ll k = it -> second;
      if(tt.colo.count(c) == 0){
	tt.colo[c] = k;
	pi kk = *tt.num.lower_bound(pi(k, 0));
        if(kk.first == k){
            tt.num.erase(kk);
            tt.num.insert(pi(k, c + kk.second));
        }
        else tt.num.insert(pi(k, c));
      }
      else {
	ll q = tt.colo[c];
	pi qq = *tt.num.lower_bound(pi(q, 0));
        tt.num.erase(qq);
        qq.second -= c;
        if(qq.second > 0) tt.num.insert(qq);
	tt.colo[c] += k;
	pi kk = *tt.num.lower_bound(pi(k + q, 0));
        if(kk.first == k + q){
            tt.num.erase(kk);
            tt.num.insert(pi(k + q, c + kk.second));
        }
        else tt.num.insert(pi(k + q, c));
      }
    }
  }
  
  R[x] = (*tt.num.rbegin()).second;
  
  /*
  ll m = -1;
  
  for(spi::iterator it = tt.num.begin(); it != tt.num.end(); ++it){
    pi p = *it;
    if(-p.first == m or m == -1){ 
      m = -p.first;
      R[x] += p.second;
//       cerr << '-' << x << ' ' << p.second << endl;
    }
    else break;
  }
  */
  return tt;
}

int main(){
  int n;
  cin >> n;
  
  G = vvi(n);
  C = vi(n);
  R = V = vi(n, 0);
  
  for(int i = 0; i < n; ++i) cin >> C[i];
  
  for(int i = 0; i < n - 1; ++i){
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  
  dfs(0);
  
  for(int i = 0; i < n; ++i) cout << (i? " " : "") << R[i];
  cout << endl;
}