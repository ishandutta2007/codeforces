%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

ll u, v, p;
queue <ll> q, q2;
map <ll, ll> inq, inq2, pre, nxt;
vector <ll> ans;

void print(ll u) {
  ll v = u;
  while (v != -1) {
    //printf("fake1 %lld -> pre %lld\n", v, pre[v]);
    ans.push_back(v);
    v = pre[v]; 
  }
  
  /*
  for (int i = (int)ans.size() - 1; i >= 0; i--)
    printf("%d ", ans[i]);
  putchar('\n');
  */
  
  for (int i = (int)ans.size() - 1; i > 0; i--) {
    v = ans[i - 1];
    if ((ans[i] + 1) % p == v) printf("1 ");
    else if ((ans[i] + p - 1) % p == v) printf("2 ");
    else printf("3 "); 
  }
  while (nxt[u] != -1) {
    //printf("fake2 %lld -> nxt %lld\n", v, nxt[u]);
    v = nxt[u];
    if ((u + 1) % p == v) printf("1 ");
    else if ((u + p - 1) % p == v) printf("2 ");
    else printf("3 ");
    u = v;
  }
  putchar('\n'); return ;
}

ll qpow(ll a, ll b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % p;
    b >>= 1; a = a * a % p;
  }
  return res;
}

void bfs(ll u, ll v) {
  q.push(u); inq[u] = 1, pre[u] = -1;
  q2.push(v); inq2[v] = 1, nxt[v] = -1;

  while (!q.empty()) {
    ll u = q.front(); q.pop();
    if (inq2[u]) {
      printf("%lld\n", inq[u] + inq2[u] - 2);
      print(u);
      exit(0);
    }
    
    long long f = 0;
    if (!inq[f = (u + 1) % p]) {
      q.push(f); inq[f] = inq[u] + 1;
      pre[f] = u;
    }
    if (!inq[f = (u + p - 1) % p]) {
      q.push(f); inq[f] = inq[u] + 1;
      pre[f] = u;
    }
    if (!inq[f = qpow(u, p - 2)]) {
      q.push(f); inq[f] = inq[u] + 1;
      pre[f] = u;
    }
    
    u = q2.front(); q2.pop();
    if (!inq2[f = (u + 1) % p]) {
      q2.push(f); inq2[f] = inq2[u] + 1;
      nxt[f] = u;
    }
    if (!inq2[f = (u + p - 1) % p]) {
      q2.push(f); inq2[f] = inq2[u] + 1;
      nxt[f] = u;
    }
    if (!inq2[f = qpow(u, p - 2)]) {
      q2.push(f); inq2[f] = inq2[u] + 1;
      nxt[f] = u;
    } 
  }
}

int main() {
  scanf("%lld%lld%lld", &u, &v, &p);
  bfs(u, v);
  return 0;
}