#include <iostream>
#include <map>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100005;
int st[4*N],l[4*N],r[4*N], a[N], q, n;
map<int, vector<int> > elem;

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

void build(int v, int i, int j) {
  if(i == j) {
    st[v] = a[i];
  } else {
    build(v*2, i, (i+j)/2);
    build(v*2+1,(i+j)/2+1, j);
    st[v] = gcd(st[v*2], st[v*2+1]);
  }
  l[v] = i;
  r[v] = j;
}

int qu(int v, int i, int j) {
  if(j < l[v] || i > r[v]) return 0;
  if(i <= l[v] && j >= r[v]) return st[v];
  return gcd(qu(v*2, i, j), qu(v*2+1, i, j));
}

int countv(int i, int j, int val) {
  if(!elem.count(val)) return 0;
  vector<int> &v = elem[val];
  int a = distance(v.begin(), lower_bound(v.begin(), v.end(), i));
  int b = distance(v.begin(), upper_bound(v.begin(), v.end(), j));
  return b-a;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for(int i = 1; i <= n; ++i) {
    cin >> a[i];
    if(!elem.count(a[i]))
      elem[a[i]] = vector<int>();
    elem[a[i]].push_back(i);
  }
  build(1, 1, n);
  cin >> q;
  while(q--) {
    int a,b;
    cin >> a >> b;
    int g = qu(1,a,b);
    cout << b-a+1 - countv(a,b,g) << "\n";
  }
  return 0;
}