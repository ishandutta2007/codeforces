#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3, MOD = 1e9+7;
map<int,int> trie[2000000][2]; int id = 0;
void add (int n) {
  int cur = 0;
  for (int i = 30; i >= 0; i--) {
    int go = n>>i&1;
    if (!trie[cur][go].count(i)) trie[cur][go][i] = ++id;
    cur = trie[cur][go][i];
  }
}
int get (int cur, int bit) {
  if (bit == -1) return 0;
  int ret = INT_MAX;
  if (!trie[cur][0].count(bit)) ret = min(ret,get(trie[cur][1][bit],bit-1));
  else if (trie[cur][1].count(bit)) ret = min(ret,get(trie[cur][1][bit],bit-1)+(1 << bit));
  if (!trie[cur][1].count(bit)) ret = min(ret,get(trie[cur][0][bit],bit-1));
  else if (trie[cur][0].count(bit)) ret = min(ret,get(trie[cur][0][bit],bit-1)+(1 << bit));
  return ret;
}
int main () {
  int n;
  scanf ("%d",&n);
  for (int i = 1; i <= n; i++) {
    int a;
    scanf ("%d",&a);
    add(a);
  }
  printf ("%d\n",get(0,30));
  return 0;
}