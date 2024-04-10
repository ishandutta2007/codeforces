#include<bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define all(x) (x).begin(),(x).end()
#define INF 100000000000000000
#define modulo 1000000007
#define mod 998244353
//#define int long long int
#define set unordered_set
using namespace std;
int n, m, q;
vector<int> no(100005);
vector<vector<int> > grid;
vector<ii> ans[2000005];
vector<ii> add[2000005];
vector<ii> rem[2000005];
vector<int> path;
 
int _hash(int x, int y){return x * m + y;}
ii _dehash(int x){return {x / m, x % m};}
bool check(int v, int j){
      int x = _dehash(v).first + _dehash(path[j]).first, y = _dehash(v).second + _dehash(path[j]).second;
      return (0 <= x && x < n && 0 <= y && y < m);
}
 
int Find(int x){
      if(no[x] == x) return x;
      return no[x] = Find(no[x]);
}
bool merge(int x, int y){
      x = Find(x);
      y = Find(y);
      if(x == y) return false;
 
      no[y] = x;
      return true;
}
 
int32_t main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
 
      cin >> n >> m >> q;
      path = {m, 1, -m, -1};
      grid.resize(n, vector<int> (m, 0));
      for(int i = 0; i < n * m; i++){
            add[0].pb({i, 0});
      }
      for(int i = 1; i <= q; i++){
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            if(grid[a][b] == c)continue;
            rem[grid[a][b]].pb({_hash(a, b), i});
            add[c].pb({_hash(a, b), i});
            grid[a][b] = c;
      }
      for(int i = 0; i <= 2e6; i++){
            if(add[i].empty() && rem[i].empty())continue;
            set<int> Q;
            int last = 0;
            for(int j = 0; j < add[i].size(); j++){
                  int x = add[i][j].first;
                  int y = add[i][j].second;
                  no[x] = x;
                  last++;
                  for(int k = 0; k < 4; k++){
                        if(check(x, k) && Q.count(x + path[k]) && merge(x + path[k], x)){
                              last--;
                        }
                  }
                  if(i != 0)
                  ans[y].pb({i, last});
                  Q.insert(x);
            }
            for(int j = 0; j < rem[i].size(); j++){
                  Q.erase(rem[i][j].first);
            }
            last = 0;
            for(set<int>::iterator itr = Q.begin(); itr != Q.end(); itr++){
                  no[*itr] = *itr;
                  last++;
            }
            for(set<int>::iterator itr = Q.begin(); itr != Q.end(); itr++){
                  for(int k = 0; k < 4; k++){
                        if(check(*itr, k) && Q.count(*itr + path[k]) && merge(*itr + path[k], *itr)){
                              last--;
                        }
                  }
            }
            for(int j = (int)rem[i].size() - 1; j >= 0; j--){
                  int x = rem[i][j].first;
                  int y = rem[i][j].second;
                  ans[y].pb({i, last});
                  no[x] = x;
                  last++;
                  for(int k = 0; k < 4; k++){
                        if(check(x, k) && Q.count(x + path[k]) && merge(x + path[k], x)){
                              last--;
                        }
                  }
                  Q.insert(x);
            }
      }
      vector<int> cnt(2000005,0);
      cnt[0] = 1;
      int sum = 1;
      for(int i = 1; i <= q; i++){
            for(int j = 0; j < ans[i].size(); j++){
                  sum -= cnt[ans[i][j].first];
                  cnt[ans[i][j].first] = ans[i][j].second;
                  sum += cnt[ans[i][j].first];
            }
            cout << sum << "\n";
      }
 
}