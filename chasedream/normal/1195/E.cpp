/**   Author: wlzhouzhuan
 *    Created: 2019/07/26 15:50:28
 *
**/
%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 100005;

int n, m;
ll a, b, g, x, y, z;

vector <deque <ll> > deq;
vector <vector <ll> > arr;

void ins(deque <ll>& dq, ll val) {
  while (!dq.empty() && dq.back() > val)
    dq.pop_back();
  dq.push_back(val);
}

void del(deque <ll>& dq, ll val) {
  if (!dq.empty() && dq.front() == val) {
    dq.pop_front();
  }
}

int main() { 
  scanf("%d%d", &n, &m); scanf("%lld%lld", &a, &b);
  scanf("%lld%lld%lld%lld", &g, &x, &y, &z);
  arr.resize(n); deq.resize(m);
  
  // a 
  for (int i = 0; i < n; i++) {
    arr[i].resize(m);
    for (int j = 0; j < m; j++) {
      arr[i][j] = g;
      g = (g * x + y) % z;
    }
  }
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < a; j++) {
      ins(deq[i], arr[j][i]);
    }
  }
  
  deque <ll> real_deq;
  long long ans = 0LL;
  
  //  
  for (int i = 0; i < b; i++) {
    ins(real_deq, deq[i].front());
  }
  ans += real_deq.front();
  for (int i = b; i < m; i++) {
    del(real_deq, deq[i - b].front());
    ins(real_deq, deq[i].front());
    ans += real_deq.front();
  }
  
  for (int i = a; i < n; i++) {
    for (int j = 0; j < m; j++) {
      del(deq[j], arr[i - a][j]);
      ins(deq[j], arr[i][j]);
    }
    
    deque <ll> real_d;
    for (int j = 0; j < b; j++) {
      ins(real_d, deq[j].front());
    }
    ans += real_d.front();
    for (int j = b; j < m; j++) {
      del(real_d, deq[j - b].front());
      ins(real_d, deq[j].front());
      ans += real_d.front();
    } 
  }
  printf("%lld\n", ans);
  return 0;
}
// 1