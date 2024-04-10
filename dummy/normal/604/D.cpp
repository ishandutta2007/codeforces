#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 6;

int to[N];
long long ok[N];

long long powmod(long long base, long long pw)  {
  long long ret = 1;
  while(pw) {
    if(pw & 1)
      ret = (ret * base) % mod;
    base = (base * base) % mod;
    pw >>= 1;
  }
  return ret;
}

int main() {
  int p, k;
  memset(ok, 0, sizeof ok);
  scanf("%d%d", &p, &k); 
  if(k == 0) {
    cout << powmod(p, p-1) << endl;
    return 0;
  }
  for(int i = 0; i<p; i++)
    to[i] = (1LL*i*k) % p;
  vector< int > st;
  for(int i = 0; i<p; i++) if(to[i] >= 0){
    int now = to[i], cnt = 1;
    to[i] = -1;
    while(now != i) {
      int tmp = now;
      now = to[now];
      to[tmp] = -1;
      cnt++;
    }
    ok[cnt]++;
    st.push_back(cnt);
  }
  st.erase(unique(st.begin(), st.end()), st.end());
  long long ans = 1;
  for(int i = 0; i<st.size(); i++) {
    long long sum = 0;
    for(int j = 0; j<= i; j++) if((st[i] % st[j]) == 0){
      sum += ok[st[j]]*(long long)st[j];
      sum %= mod;
    }
    ans = (ans * powmod(sum, ok[st[i]])) % mod;
  }
  cout << ans << endl;
  return 0;
}