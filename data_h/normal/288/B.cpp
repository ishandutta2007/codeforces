#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <vector>
#include <functional>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <set>
using namespace std;
typedef long long ll;

const ll inf = 1000000007;

ll n, m, a[10], ans, be[10], l, b[10];
queue<ll> q;

struct line
{
  ll next, to;     
}li[100];

void makeline(ll fr, ll to)
{
  ++l;
  li[l].next = be[fr];
  be[fr] = l;
  li[l].to = to;   
}

bool check()
{
  memset(b, 0, sizeof(b));
  memset(be, 0, sizeof(be));
  l = 0;
  for (ll i = 1; i <= m; ++i) makeline(a[i], i);   
  q.push(1);
  b[1] = 1;
  ll ans = 0;
  while (!q.empty())
  {
    ll now = q.front();
    q.pop();
    ++ans;
    for (ll i = be[now]; i; i = li[i].next)
    {
      ll to = li[i].to;
      if (b[to]) continue;
      b[to] = 1;
      q.push(to);  
    }    
  }
  return ans == m;
}

void dfs(ll now)
{
  if (now == m + 1)
  {
    if (check()) ++ans;
    return;
  }
  for (ll i = 1; i <= m; ++i)
  {
    a[now] = i;  
    dfs(now + 1);
  }
}

ll power(ll a, ll b)
{
  ll ans = 1;
  while (b)
  {
    if (b & 1) ans = (ans * a) % inf;
    a = (a * a) % inf;
    b >>= 1;    
  }  
  return ans;
}

int main()
{
  //freopen("input.in","r",stdin);
 // freopen("output.out","w",stdout);
  scanf("%I64d%I64d", &n, &m);
  if (m > 1)
  {
    dfs(2);
    ans = ((ans % inf) * m) % inf;
  }
  else 
    ans = 1;
  
  ans = (ans * power(n - m, n - m)) % inf;
  printf("%I64d", ans);
  //fclose(stdin);fclose(stdout);    
}