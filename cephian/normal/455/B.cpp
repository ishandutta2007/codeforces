#include <iostream>
#include <vector>

using namespace std;

struct node {
  int child[26];
  node() {
    for(int i = 0; i < 26; ++i)
      child[i]=0;
  }
};

vector<node> tree;
int n,k;

void add(int v, string& s, int i) {
  if(i >= s.size()) return;
  if(!tree[v].child[s[i]-'a']) {
    tree.push_back(node());
    tree[v].child[s[i]-'a']=tree.size()-1;
  }
  add(tree[v].child[s[i]-'a'],s,i+1);
}

bool force_win(int v) {
  for(int i = 0; i < 26; ++i) {
    if(!tree[v].child[i]) continue;
    if(!force_win(tree[v].child[i])) return 1;
  }
  return 0;
}

bool force_lose(int v) {
  bool em = 1;
  for(int i = 0; i < 26; ++i) {
    if(!tree[v].child[i]) continue;
    em=0;
    if(!force_lose(tree[v].child[i])) return 1;
  }
  return em;
}

string s;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  tree.push_back(node());
  for(int i = 0; i < n; ++i) {
    cin >> s;
    add(0,s,0);
  }
  bool fw = force_win(0);
  bool fl = force_lose(0);
  if(fw && fl) cout << "First\n";
  else if(fw && !fl) {
    if(k&1) cout << "First\n";
    else cout << "Second\n";
  } else if(!fw) cout << "Second\n";
  return 0;
}