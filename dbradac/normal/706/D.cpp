#include <cstdio>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>
#include <map>

using namespace std;
#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int LG = 30;

struct node {
  int kol;
  node *l, *r;
  void update() {
    kol = l->kol + r->kol;
  }
};

struct trie {
  node *root, *NIL;

  trie() {
    NIL = new node {0, 0, 0};
    NIL->l = NIL->r = NIL;
    root = NIL;
  }

  void clear(node *p) {
    if (p == NIL)
      return;

    clear(p->l);
    clear(p->r);
    delete p;
  }

  ~trie() {
    clear(root);
    delete NIL;
  }

  node* insert(node *p, int x, int poz, int st) {
    if (p == NIL) {
      p = new node{0, NIL, NIL};
      p->l = p->r = NIL;
    }

    if (poz == -1) {
      p->kol += st;
      return p;
    }

    if (x >> poz & 1)
      p->r = insert(p->r, x, poz-1, st);
    else
      p->l = insert(p->l, x, poz-1, st);

    p->update();

    return p;
  }

  void insert(int x) {
    root = insert(root, x, LG, 1);
  }

  void erase(int x) {
    root = insert(root, x, LG, -1);
  }

  int mx(node *p, int poz, int x) {
    if (poz == -1)
      return 0;

    if (x>>poz & 1) {
      if (p->l->kol)
        return mx(p->l, poz-1, x) + (1<<poz);
      return mx(p->r, poz-1, x);
    }
    else {
      if (p->r->kol)
        return mx(p->r, poz-1, x) + (1<<poz);
      return mx(p->l, poz-1, x);
    }
  }

  int mx(int x) {
    return mx(root, LG, x);
  }
} Tr;

int n;

int main()
{
  Tr.insert(0);
  scanf("%d", &n);

  char sl[5] = "?+-";
  for (int i=0; i<n; i++) {
    char c[3];
    int x;

    c[0] = sl[rand()%2];
    x = rand() % 100000;
    scanf(" %s%d", c, &x);

    if (c[0] == '?')
      printf("%d\n", Tr.mx(x));
    else {
      P q = P(c[0] == '+' ? 1 : -1, x);
      if (q.X == 1)
        Tr.insert(x);
      else
        Tr.erase(x);
    }
  }

  return 0;
}