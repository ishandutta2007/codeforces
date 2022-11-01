#include <bits/stdc++.h>
#define L long long 
using namespace std;
const L N = 200001;
struct tree {
	vector<L>s;
	L n;
	tree(L n):n(n){
    	s.resize(n + 10);
	}
	void update(L x, L v) {
    for(; x < N; x += x & -x)
      s[x] += v;
  }
 
  L getsum(L x) {
    L ans = 0;
    for(;x > 0 ; x -= x & -x)
      ans += s[x];
    return ans;
  }
} t1(N), t2(N);
 
L sum[N];
L pos[N],n;
 
priority_queue <L> qmax;
priority_queue<L, vector<L>, greater<L> > qmin;
 
L add(L u) {
  qmin.push(u);
  while(qmin.size() > qmax.size()) {
    L u = qmin.top();
    qmin.pop();
    qmax.push(u);
  }
 
  while(qmin.size() && qmax.size() && qmin.top() < qmax.top()) {
    L u = qmin.top(), v = qmax.top();
    qmin.pop();
    qmax.pop();
    qmin.push(v);
    qmax.push(u);
  }
}
 
L getavg() {
  return qmax.top();
}
int main() {
  cin >> n;
  for(L i = 1, u; i <= n; ++i) {
    sum[i] = sum[i - 1] + i;
    cin >> u;
    pos[u] = i;
  }
  L cnt = 0;
  for(L i = 1; i <= n; ++i) {
    t1.update(pos[i], pos[i]);
    t2.update(pos[i], 1);
    add(pos[i]);
    L avg = getavg();
    L l, r;
    if(i % 2 == 0) {
      l = avg - i / 2 +1;
      r = avg + i / 2;
    }
    else {
      l = avg - i / 2;
      r = avg + i / 2;
    }
    L ans = -(sum[r] - sum[avg]) + sum[avg] - sum[l - 1] - 2 * t1.getsum(avg) + t1.getsum(n);
    
    cnt += i - t2.getsum(pos[i]);
    ans += cnt;
    cout << ans << " ";
  }
}