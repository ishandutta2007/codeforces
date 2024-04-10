#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5; 

int n, m;
int val[N], z[N], u[N], v[N];
vector< pair<int, int> > adj[N];
bool tes(int lim) {
  for(int i = 0; i<n; i++)
    val[i] = 0;
  for(int i = 0; i<lim; i++)
    val[v[i]]++;
  stack<int> st;
  int cnt = 0;
  for(int i = 0; i<n; i++)
    if(val[i] == 0) {
      cnt++;
      st.push(i);
    }
  if(cnt != 1)
    return false;
  int relax = 0;
  while(!st.empty()) {
    relax++;
    if(cnt != 1)
      return false;
    int now = st.top(); st.pop();
    cnt--;
    for(auto it : adj[now]) if(it.second < lim) {
      val[it.first]--;
      if(val[it.first] == 0) {
        cnt++;
        st.push(it.first);
      }
    }
  }
  return relax == n;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i= 0; i<m; i++) {
    scanf("%d%d", u+i, v+i);
    u[i]--; v[i]--;
    adj[u[i]].push_back(make_pair(v[i], i));
  }
  int l = 0, r = m, now = 0;
  while(l < r) {
    int mid = (l+r)>>1;
    if(tes(mid))
      r = mid;
    else
      l = mid+1;
  }
  if(tes(l))
    printf("%d\n", l);
  else
    puts("-1");
  return 0;
}