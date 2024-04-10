#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
#define all(x) (x).begin(),(x).end()
const int MN = 2e5+3;
int r[MN], l[MN], p[MN];
bool done[MN];
int find (int n) {return p[n] == n ? n : p[n] = find(p[n]);}
void merge (int a, int b) {
  a = find(a); b = find(b);
  if (a == b) return;
  p[a] = b;
  r[b] = max(r[b],r[a]);
  l[b] = min(l[b],l[a]);
}
bool solveStupid (vector<pii> a) {
  int n = a.size();
  while (1) {
    int mn = INT_MAX, id = -1; bool same = 1; int w = a[0].first;
    for (int i = 0; i < n; i++) {
    if (a[i].first < mn) {
      mn = a[i].first;
      id = i;
    }
    same &= a[i].first == w;
    }
    if (same) return 0;
    if (id == n-1 || a[id+1].first != a[id].first) return 1;
    a[id].first++; a[id+1].first++;
  }
  return 0;
}
int main () {
  int n;
  scanf ("%d",&n);
  vector<pii> a(n);
  int mx = 0; bool no = 0;
  for (int i = 0; i < n; i++) {
    scanf ("%d",&a[i].first), a[i].second = i, p[i] = l[i] = r[i] = i;
  }
  //bool go = solveStupid(a);
  sort(all(a));
  int lst = -1;
  for (int i = 0; i < n; i++) {
    int cur = a[i].first, pos = a[i].second;
    done[pos] = 1;
    if (done[pos+1])
      merge(pos,pos+1);
    if (pos && done[pos-1])
      merge(pos,pos-1);
    if (i+1<n && a[i+1].first != cur) {
      for (int j = i; j > lst; j--) {
        int cmp = find(a[j].second);
        if ((r[cmp]-l[cmp]+1)&1) {
          no = 1;
          goto oof;
        }
      }
      lst = i;
    }
  }
  oof:;
  printf (no?"NO\n":"YES\n");
  return 0;
}