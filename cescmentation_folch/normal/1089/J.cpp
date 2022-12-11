#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

struct node {
  int fi;
  string word;
  map<char, node*> fill;
  node() {
    fi = 0;
  }
  node(string a) {
    fi = 1;
    word = a;
  }
  ~node() {
    for (auto it : fill) 
      delete it.second;
  }
};

void f(string& a, int i, node* p) {
  if (i == (int)a.size()) {
    p->fi = 1;
    p->word = a;
    return;
  }
  if (p->fill.count(a[i]) == 0) {
    p->fill[a[i]] = new node();
  }
  f(a,i+1,p->fill[a[i]]);
}

vector<string> vss;

string valor(int n) {
  return vss[n];
  /*
  string r;
  while (n >= 0) {
    r.push_back('a' + n%26);
    n /= 26;
    if (n == 0) break;
  }
  reverse(r.begin(), r.end());
  return r;
  */
}

bool find(string& a, int i, node* p) { 
  if (i == (int)a.size()) return p->fi;
  if (p->fill.count(a[i]) == 0) return false;
  return find(a, i+1, p->fill[a[i]]);
}

int longest(string& a, int i, node* p) {
  int k = -1;
  if (p->fi) k = i;
  if (i >= (int)a.size()) return k;
  if (p->fill.count(a[i]) == 0) return k;
  return max(k, longest(a, i+1, p->fill[a[i]]));
}

int longest2(string& a, int i, int i2, node* p) {
  int k = -1;
  if (p->fi) k = i;
  if (k != -1 and i > i2) return k;
  if (i >= (int)a.size()) return k;
  if (p->fill.count(a[i]) == 0) return k;
  return max(k, longest2(a, i+1, i2, p->fill[a[i]]));
}

int longnum(string& a, int i) {
  if (i >= (int)a.size()) return -1;
  if (a[i] < '0' or '9' < a[i]) return -1;
  int j = i;
  while (j < (int)a.size() and '0' <= a[j] and a[j] <= '9') ++j;
  return j;
}

int longword(string& a, int i) {
  if (i >= (int)a.size()) return -1;
  if (a[i] >= '0' and '9' >= a[i]) return -1;
  int j = i;
  while (('0' <= a[j] and a[j] <= '9') or ('a' <= a[j] and a[j] <= 'z') or ('A' <= a[j] and a[j] <= 'Z') or a[j] == '_' or a[j] == '$') ++j;
  if (j == i) return -1;
  return j;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string ri(1,'a');
  for (int i = 0; i < 26; ++i) {
    ri[0] = 'a' + i;
    vss.push_back(ri);
  }
  ri= string(2,'a');
  for (int i = 0; i < 26; ++i) {
    ri[0] = 'a' + i;
    for (int j = 0; j < 26; ++j) {
      ri[1] = 'a' + j;
      vss.push_back(ri);
    }
  }
  ri= string(3,'a');
  for (int i = 0; i < 26; ++i) {
    ri[0] = 'a' + i;
    for (int j = 0; j < 26; ++j) {
      ri[1] = 'a' + j;
      for (int w = 0; w < 26; ++w) {
        ri[2] = 'a' + w;
        vss.push_back(ri);
      }
    }
  }
  int n;
  cin >> n;
  node* root = new node();
  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    f(a,0,root);
  }
  int q;
  cin >> q;
  cin.ignore();
  string res;
  vi rdist;
  int conta = 0;
  map<string, string> S;
  for (int cc = 0; cc < q; ++cc) {
    string line;
    getline(cin, line);
    for (int i = 0; i < (int)line.size(); ++i) {
      if (line[i] == ' ') continue;
      if (line[i] == '#') break;
      int j1 = longest(line, i, root);
      int j2 = longword(line, i);
      int j3 = longnum(line, i);
      if (j1 >= j2 and j1 >= j3) {
        for (int l = i; l < j1; ++l) {
          res.push_back(line[l]);
        }
        rdist.push_back(j1 - i);
        i = j1-1;
      }
      else if (j3 >= j1 and j3 >= j2) {
        for (int l = i; l < j3; ++l) {
          res.push_back(line[l]);
        }
        rdist.push_back(j3 - i);
        i = j3-1;
      }
      else {
        string sss;
        for (int l = i; l < j2; ++l) {
          sss.push_back(line[l]);
        }
        if (S.count(sss) == 0) {
          string pal = valor(conta++);
          while (find(pal, 0, root)) {
            pal = valor(conta++);
          }
          S[sss] = pal;
        }
        string pal = S[sss];
        res += pal;
        rdist.push_back(pal.size());
        i = j2-1;
      }
    }
  }
  int ind = 0;
  int nextsp = (int)res.size() + 10;
  for (auto dist : rdist) {
    if (ind + dist >= nextsp) {
      nextsp = (int)res.size() + 10;
      cout << ' ';
    }
    int j1 = longest2(res, ind, ind+dist, root);
    int j2 = min(ind + dist + 1, longword(res, ind));
    int j3 = min(ind + dist + 1, longnum(res, ind));

    if (j1 > ind + dist) nextsp = min(nextsp, j1);
    if (j2 > ind + dist) nextsp = min(nextsp, j2);
    if (j3 > ind + dist) nextsp = min(nextsp, j3);
    for (int i = ind; i < ind + dist; ++i) cout << res[i];
    ind += dist;
  }
  cout << '\n';
  delete root;
}