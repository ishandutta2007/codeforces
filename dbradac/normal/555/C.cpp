#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

const int TOUR = 1<<30;

typedef long long llint;
typedef pair<int,int> pii;

struct node {
  int maxx, prop;
  node *l, *r;
  node (int _maxx, int _prop, node *_l, node *_r) : maxx(_maxx), prop(_prop), l(_l), r(_r) {}
  node () {}
};

struct tour {
  node *NIL, *root;
  tour () {
    NIL = new node(0, 0, NIL, NIL);
    NIL->l = NIL->r = NIL;
    root = new node(0, 0, NIL, NIL);
  }

  void prop(node *p) {
    p->l->maxx = max(p->l->maxx, p->prop);
    p->l->prop = max(p->l->prop, p->prop);

    p->r->maxx = max(p->r->maxx, p->prop);
    p->r->prop = max(p->r->prop, p->prop);

    p->prop = 0;
  }

  void insert(node *p, int lo, int hi, int begin, int end, int val) {
    if (lo >= end || hi <= begin)
      return;
    if (lo >= begin && hi <= end) {
      p->maxx = max(p->maxx, val);
      p->prop = max(p->prop, val);
      return;
    }

    if (p->l == NIL)
      p->l = new node(0, 0, NIL, NIL);
    if (p->r == NIL)
      p->r = new node(0, 0, NIL, NIL);
    prop(p);

    insert(p->l, lo, (lo+hi)/2, begin, end, val);
    insert(p->r, (lo+hi)/2, hi, begin, end, val);
    p->maxx = max(p->l->maxx, p->r->maxx);
  }

  int vrati(node *p, int lo, int hi, int begin, int end) {
    if (lo >= end || hi <= begin)
      return 0;
    if (lo >= begin && hi <= end)
      return p->maxx;
    
    if (p->l == NIL)
      p->l = new node(0, 0, NIL, NIL);
    if (p->r == NIL)
      p->r = new node(0, 0, NIL, NIL);

    prop(p);
    return max(vrati(p->l, lo, (lo+hi)/2, begin, end),
               vrati(p->r, (lo+hi)/2, hi, begin, end));
  }
} Ver, Hor;


int main()
{
  int n, q;

  scanf("%d%d", &n, &q);

  for (int i=0; i<q; i++) {
    int col, row;
    char c;
    scanf("%d%d %c", &col, &row, &c);
    if (c == 'U') {
      int tmp = Hor.vrati(Hor.root, 0, TOUR, col, col + 1);
      printf("%d\n", row - tmp);
      Ver.insert(Ver.root, 0, TOUR, tmp + 1, row + 1, col);
      Hor.insert(Hor.root, 0, TOUR, col, col + 1, row);
    }
    else {
      int tmp = Ver.vrati(Ver.root, 0, TOUR, row, row + 1);
      printf("%d\n", col - tmp);
      Hor.insert(Hor.root, 0, TOUR, tmp + 1, col + 1, row);
      Ver.insert(Ver.root, 0, TOUR, row, row + 1, col);
    }
  }

  return 0;
}