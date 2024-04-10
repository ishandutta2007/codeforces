#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<vi> vvi;

const int N = 200010;

struct cosa {
  int a = 0, b2 = 0, ab = 0, bc = 0, abc = 0;
};
cosa T[4*N];
int lazy[4*N];

void actu(int node, int a, int b) {
  T[node].a += lazy[node];
  T[node].b2 -= 2*lazy[node];
  T[node].ab -= lazy[node];
  T[node].bc -= lazy[node];
  if (a != b) {
    lazy[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
  }
  lazy[node] = 0;
}

void fes(int node, int a, int b, int x, int y, int val) {
  actu(node, a ,b);
  if (b < x or y < a) return;
  if (x <=  a and b <= y) {
    T[node].a += val;
    T[node].b2 -= 2*val;
    T[node].ab -= val;
    T[node].bc -= val;
    if (a != b) {
      lazy[2*node] +=val;
      lazy[2*node+1] += val;
    }
    return;
  }
  fes(2*node, a ,(a+b)/2, x,y,val);
  fes(2*node+1, 1+(a+b)/2,b, x,y,val);
  T[node].a = max(T[2*node].a, T[2*node+1].a);
  T[node].b2 = max(T[2*node].b2, T[2*node+1].b2);
  T[node].ab = max(T[2*node].a + T[2*node+1].b2,max(T[2*node].ab, T[2*node+1].ab));
  T[node].bc = max(T[2*node].b2 + T[2*node+1].a,max(T[2*node].bc, T[2*node+1].bc));
  T[node].abc = max(max(T[2*node].a + T[2*node+1].bc,T[2*node].ab + T[2*node+1].a),max(T[2*node].abc,T[2*node+1].abc));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >>q;
  n = 2*n -2;
  string s;
  cin >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == ')') {
      fes(1,0,n,i,n,-1);
    } else {
      fes(1,0,n,i,n,1);
    }
  }
  cout << max(T[1].abc,T[1].a) << '\n';
  while (q--) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    if (s[x] != s[y]) {
      swap(s[x],s[y]);
      if (s[x] == ')') {
        fes(1,0,n,x,n,-2);
        fes(1,0,n,y,n,2);
      } else {
        fes(1,0,n,x,n,2);
        fes(1,0,n,y,n,-2);
      }
    }
    cout << max(T[1].abc,T[1].a) << '\n';
  }
}