#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <queue>
#include <assert.h>
#include <functional>
#include <complex>
#include <unordered_map>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

const long double PI = 3.141592653589793;
const int INF = 2e9 + 10;
const ll LONGINF = 4e18;
const ll INF2 = 1e17 + 10;
const ll mod = 998244353;

struct Node {
  Node* next[2];
//  bool term;
  int term_count;
  Node(): term_count(0) {
    next[0]= next[1] = nullptr;
  }
};

int nodes_cnt = 0;
Node* root;
Node nodes[10000000];

Node* new_node() {
  nodes[nodes_cnt] = Node();
  return &nodes[nodes_cnt++];
}

void add_num(int num) {
  Node* cur = root;
  for (int lvl = 30; lvl >= 0; --lvl) {
    int son = ((1 << lvl) & num ? 1 : 0);
    if (!cur->next[son]) {
      cur->next[son] = new_node();
    }
    ++cur->term_count;
    cur = cur->next[son];
  }
  ++cur->term_count;
}

int find_and_remove(int num) {
  Node* cur = root;
  int ans = 0;
  for (int lvl = 30; lvl >= 0; --lvl) {
    int son = ((1 << lvl) & num ? 1 : 0);
    if (!cur->next[son] || cur->next[son]->term_count == 0) {
      son ^= 1;
    }
    --cur->term_count;
    ans |= (1 << lvl) * son;
    cur = cur->next[son];
  }
  --cur->term_count;
  return ans;
}

void solve() {
  root = new_node();
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    add_num(p);
  }
  for (int i = 0; i < n; ++i) {
    int ans = find_and_remove(a[i]);
    cout << (a[i] ^ ans) << ' ';
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  solve();

  return 0;
}