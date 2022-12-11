#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

vi V;

struct node {
  int cont;
  node* pare;
  map<int, node*> f;
  node() {
    pare = nullptr;
    cont = 0;
  }
  ~node() {
    for (auto it : f) 
      delete it.second;
  }
};

ll que(int a, int b) {
  if (a == b) return 0;
  int c = (a+b)/2;
  ll res = que(a, c) + que(c+1, b);
  node *root = new node();
  stack<int> S;
  node *p = root;
  for (int i = c; i >= a; --i) {
    if (S.size() and S.top() == V[i]) {
      S.pop();
      p = p->pare;
    }
    else {
      S.push(V[i]);
      if (p->f.count(V[i]) == 0) {
        p->f[V[i]] = new node();
        p->f[V[i]]->pare = p;
      }
      p = p->f[V[i]];
    }
    ++p->cont;
  }
  p = root;
  S = stack<int>();
  for (int i = c+1; i <= b; ++i) {
    if (S.size() and S.top() == V[i]) {
      S.pop();
      p = p->pare;
    }
    else {
      S.push(V[i]);
      if (p->f.count(V[i]) == 0) {
        p->f[V[i]] = new node();
        p->f[V[i]]->pare = p;
      }
      p = p->f[V[i]];
    }
    res += p->cont;
  }
  delete root;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    V = vi(n);
    for (auto& x : V) cin>> x;
    cout << que(0, n-1) << '\n';
  }

}