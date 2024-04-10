#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <iostream>

using namespace std;
typedef vector<vector<int> > graph;

graph G;
graph lab;
map<int, int> send;

bool seen[100005]={0};
int w[100005]={0};

int cc(int v, int f) {
  seen[v]=1;
  int a = 1;
  for(int i = 0; i < G[v].size(); ++i) {
    if(G[v][i] == f) continue;
    a += cc(G[v][i],v);
  }
  return a;
}

void find_leaf(int v, int f, vector<int>& l) {
  if(G[v].size() <= 1) {
    l.push_back(v);
  }
  for(int i = 0; i < G[v].size(); ++i) {
    if(G[v][i] == f) continue;
    find_leaf(G[v][i],v,l);
  }
}

vector<int> leaf;
set<int> A;

void assign(int v, int f) {
  A.insert(v);
  for(int i = 0; i < G[v].size(); ++i) {
    if(G[v][i] == f) continue;
    assign(G[v][i],v);
  }
}

set<int> same;
void solve_same(int n, int a) {
  for(int i = 0; i < n; ++i) {
    int p;
    scanf("%d",&p);
    if(p == a-p) continue;
    if(same.count(a-p)) {
      same.erase(a-p);
    } else {
      same.insert(p);
    }
  }
  if(same.size()) cout << "NO\n";
  else {
    cout << "YES\n";
    for(int i = 0; i < n; ++i) {
      if(i) cout << " ";
      cout << "0";
    }
    cout << "\n";
  }
}

int main() {
  int n,a,b;
  scanf("%d%d%d",&n,&a,&b);
  if(a==b) {
    solve_same(n,a);
    return 0;
  }

  G = graph(n,vector<int>());
  lab = graph(n,vector<int>());
  for(int i = 0; i < n; ++i) {
    int p;
    scanf("%d",&p);
    w[i] = p;
    if(send.count(a-p)) {
      int v = send[a-p];
      G[i].push_back(v);
      G[v].push_back(i);
      lab[i].push_back('a');
      lab[v].push_back('a');
    }
    if(send.count(b-p)) {
      int v = send[b-p];
      G[i].push_back(v);
      G[v].push_back(i);
      lab[i].push_back('b');
      lab[v].push_back('b');
    }
    send[p]=i;
  }
  for(int i = 0; i < n; ++i) {
    if(seen[i]) continue;
    int c = cc(i,-1);
    leaf.clear();
    find_leaf(i,-1,leaf);
    if(c%2==0) {
      if(lab[leaf[0]][0] == 'a') {
        assign(leaf[0],-1);
      }
    } else {
      bool ok = 0;
      for(int j = 0; j < leaf.size(); ++j) {
        int i = leaf[j];
        if(G[i].size() == 0) {
          if(w[i] == a-w[i]) {
            A.insert(i);
            ok = 1;
            break;
          }
          if(w[i] == b-w[i]) {
            ok = 1;
            break;
          }
          // cout << "zow" << endl;
        } else if(lab[i][0] == 'a' && b-w[i] == w[i]) {
          ok = 1;
          break;
        } else if(lab[i][0] == 'b' && a-w[i] == w[i]) {
          A.insert(i);
          assign(G[i][0],i);
          ok = 1;
          break;
        }
      }
      if(!ok) {
        printf("NO\n");
        return 0;
      }
    }
  }

  printf("YES\n");
  for(int i = 0; i < n; ++i) {
    if(i) printf(" ");
    if(A.count(i)) printf("0");
    else printf("1");
  }
  printf("\n");
  return 0;
}