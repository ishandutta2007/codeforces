#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

struct node {
  int ne[26], suff;
  
  vector <int> rsuff;
  int a, b, cur, was;
};

#define maxn 1000100

int fen[maxn * 2], fen_n;
int f_get (int i) {
  int res = 0;
  while (i >= 0) {
    res += fen[i];
    i = (i & (i + 1)) - 1;
  }
  return res;
}
void f_add (int i, int d) {
  while (i < fen_n) {
    fen[i] += d;
    i |= i + 1;
  }
}

node arr[maxn];
int arr_n = 0;

node *add (char *s) {
  node *v = &arr[0];
  while (*s) {
    int c = *s++ - 'a';
    if (!v->ne[c]) {
      v->ne[c] = ++arr_n;
    }
    v = &arr[v->ne[c]];
  }
  return v;
}

void fix (node *v, int d) {
  if (d == -1 && v->cur == 1 || d == +1 && v->cur == 0) {
    f_add (v->a, +d);
    f_add (v->b, -d);
    v->cur += d;
  }
}

int q[maxn], ql, qr;
void aho() {
  for (int i = 0; i < 26; i++) {
    if (arr[0].ne[i]) {
      int x = arr[0].ne[i];
      q[qr++] = x;
    }
  }

  while (ql < qr) {
    int id = q[ql++];
    node *v = &arr[id];
    
    arr[v->suff].rsuff.push_back(id);

    for (int i = 0; i < 26; i++) {
      int x = arr[v->suff].ne[i];
      if (v->ne[i]) {
        arr[v->ne[i]].suff = x;
        q[qr++] = v->ne[i];
      } else {
        v->ne[i] = x;
      }
    }
  }
}

char buf[maxn];

void dfs (node *v) {
  v->was = 1;
  v->a = fen_n++;
  for (int i = 0; i < (int)v->rsuff.size(); i++) {
    dfs (&arr[v->rsuff[i]]);
  }
  v->b = fen_n++;
}
node *words[maxn];

int main (void) {
  int qn, wn;
  scanf ("%d%d", &qn, &wn);

  for (int i = 1; i <= wn; i++) {
    scanf ("%s", buf);
    words[i] = add (buf);
  }
  
  aho();

  for (int i = 0; i < arr_n; i++) {
    if (!arr[i].was) {
      dfs (&arr[i]);
    }
  }

  for (int i = 1; i <= wn; i++) {
    fix (words[i], +1);
  }

  for (int  i = 0; i < qn; i++) {
    char c;
    while ((c = getc(stdin)) == ' ' || c == '\n');
    if (c == '+') {
      int x;
      scanf ("%d", &x);

      fix (words[x], +1);
    } else if (c == '-') {
      int x;
      scanf ("%d", &x);

      fix (words[x], -1);
    } else {
      scanf ("%s", buf);
      char *s = buf;
      long long res = 0;
      node *v = &arr[0];
      while (*s) {
        v = &arr[v->ne[*s - 'a']];
        res += f_get (v->a);
        s++;
      }
      printf ("%I64d\n", res);
    }

  }
  
  return 0;
}