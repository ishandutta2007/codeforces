#include <bits/stdc++.h>
using namespace std;

#define llong long long /*{{{*/
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
#define _pt(x) typename iterator_traits<x>::value_type
template<class u> vector<_pt(u)> tovec(u a, u b) { return vector<_pt(u)>(a, b); }
template<class x> ostream& operator<<(ostream& cout, const vector<x>& a) {
  cout << "[";
  rep(i, len(a)) cout << a[i] << (i == len(a) - 1 ? "" : ", ");
  return cout << "]";
}
template<class u, class v> ostream& operator<<(ostream& cout, const pair<u, v>& a) {
  return cout << a.xx << ": " << a.yy;
}/*}}}*/

#define rem ((llong)1e9+7)
set<string> nonAlpha = {"0011", "0101", "1110", "1111"};
struct trie {
  trie* parent;
  trie* child[2];
  llong dp;

  trie(trie* argParent, int branch): parent(argParent), child{0} {
    if (!parent) return;
    parent->child[branch] = this;
    calDp();
  }

  bool getSelfBranch() {
    assert(parent);
    return parent->child[1] == this;
  }

  void calDp() {
    trie* p = this;
    string s(4, ' ');
    dp = 0;
    //dp = 1;
    for (int i = 0; i < 4 and p->parent; ++i, p = p->parent) {
      s[3 - i] = (char)('0' + p->getSelfBranch());
      //if (i == 3) clog << s << endl;
      if (i == 3 and nonAlpha.count(s)) continue;
      (dp += p->parent->dp) %= rem;
    }
  }
};

vector<trie*> atEnd;

string tr;
void printTrie(trie* r)  {
  if (!r->child[0] and !r->child[1]) {
    clog << tr << endl;
    return ;
  }

  rep(i, 2) {
    tr += (char)('0' + i);
    if (r->child[i]) printTrie(r->child[i]);
    tr.pop_back();
  }
}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  trie* root = new trie(0, 0);
  root->dp = 1;
  int n; cin >> n;
  llong ans = 0;
  //clog << tovec(all(nonAlpha)) << endl;
  while (n--) {
    int branch; cin >> branch;

    atEnd.push_back(root);
    vector<trie*> newEnd;
    for (auto i: atEnd) {
      if (!i->child[branch]) {
        (ans += (new trie(i, branch))->dp) %= rem;
      }
      newEnd.push_back(i->child[branch]);
    }
    //printTrie(root);
    //clog << endl;
    atEnd = move(newEnd);
    cout << ans << '\n';
  }
  for (auto i: atEnd) delete i;

  return 0;
}