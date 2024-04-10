#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

vi Tval;

void act(int node, int a, int b, int x, int val) {
  if (b < x or x < a) return;
  if (a == b) {
    Tval[node] = val;
    return;
  }
  int m = (a+b)/2;
  act(2*node,a,m,x,val);
  act(2*node+1,1+m,b,x, val);
  Tval[node] = max(Tval[2*node], Tval[2*node+1]);
}

int que(int node, int a, int b, int x, int y) {
  if (b < x or y < a) return 0;
  if (x <= a and b <= y) return Tval[node];
  int m = (a+b)/2;
  return max(que(2*node,a,m,x,y),
      que(2*node+1,1+m,b,x,y));
}

vi lazy;
vpi T;

inline void actu(int node, bool t) {
  T[node].first += lazy[node];
  if (!t) {
    lazy[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
  }
  lazy[node] = 0;
}

const int INF = 100000000;

pi que2(int node, int a, int b, int x, int y) {
  actu(node, a==b);
  if (b < x or y < a) return pi(INF, INF);
  if (x <= a and b <= y) {
    return T[node];
  }
  int m=(a+b)/2;
  return min(que2(2*node,a,m,x,y),
      que2(2*node+1,1+m,b,x,y));
}

void act2(int node, int a, int b, int x, int y, int val) {
  actu(node, a == b);
  if (b < x or y < a) return;
  if (x <= a and b <= y) {
    lazy[node] = val;
    actu(node, a==b);
    return;
  }
  int m=(a+b)/2;
  act2(2*node,a,m,x,y,val);
  act2(2*node+1,1+m,b,x,y,val);
  T[node] = min(T[2*node], T[2*node+1]);
}

void build2(int node, int a, int b, int val) {
  if (a == b) {
    T[node].first = val;
    T[node].second = a;
    return;
  }
  int m = (a+b)/2;
  build2(2*node,a,m, val);
  build2(2*node+1,1+m,b, val);
  T[node] = min(T[2*node], T[2*node+1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  T = vpi(4*n);
  lazy = vi(4*n,0);
  int ROP = 4*n;
  build2(1, 0, n-1, ROP);
  Tval = vi(4*n,0);
  vi P(n+1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin>> x;
    P[x] = i;
    act(1,0,n-1,i, x);
  }
  set<int> ss;
  for (int q = 0; q < n; ++q) {
    if (q) cout << ' ';
    cout << que(1,0,n-1,0,n-1);
    int x;
    cin >> x;
    --x;
    ss.insert(x);
    act2(1,0,n-1,x,x,-ROP);
    pi vv = que2(1,0,n-1,x,n-1);
    int y = vv.second;
    int val = que(1,0,n-1,0,y);
    int ind = P[val];
    act(1,0,n-1,ind,0);
    act2(1,0,n-1,x,n-1,-1);
    act2(1,0,n-1,ind,n-1,1);
  }
  cout << '\n';
}