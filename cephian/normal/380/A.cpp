#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct event {
  ll cover;
  int type;
  ll x, y;

  event() {}

  event(ll val) : x(val) {
    type = 1;
  }

  event(ll l, ll r) : x(l), y(r) {
    type = 2;
  }
};

int n,m;
const int N = 5;
int pre[N];
ll q = 0;

vector<event> all;

int query(ll k) {
  if(k < N) return pre[k];
  int lo = 0;
  int hi = all.size()-1;
  while(lo < hi) {
    int mid = (lo+hi)/2;
    if(all[mid].cover-1 < k) {
      lo = mid+1;
    } else {
      hi = mid;
    }
  }
  if(all[lo].type == 1)
    return all[lo].x;
  return query((k - all[lo-1].cover) % all[lo].x);
}

int main() {
  ios::sync_with_stdio(0);
  cin >> m;
  for(int i = 0; i < m; ++i) {
    int type;
    cin >> type;
    ll prev = 0;
    if(i == 0) prev = 0;
    else prev = all[all.size()-1].cover;
    if(type == 1) {
      int x;
      cin >> x;
      all.push_back(event(x));
      all.back().cover = prev+1;
    } else {
      ll x,y;
      cin >> x >> y;
      all.push_back(event(x,y));
      all.back().cover = prev + x*y;
    }
    // cout << i << " -> " << all.back().cover << endl;
  }
  int loc = 0;
  while(loc < all.size() && q < N) {
    if(all[loc].type == 1) {
      pre[q++] = all[loc].x;
    } else {
      for(int i = 0; i < all[loc].x * all[loc].y && q+i < N; ++i) {
        pre[q+i] = pre[i%all[loc].x];
      }
      q += all[loc].x * all[loc].y;
    }
    ++loc;
  }
  cin >> n;
  for(int i = 0; i < n; ++i) {
    ll k;
    cin >> k;
    cout << query(k-1) << ((i==n-1)?"\n":" ");
  }

  return 0;
}