#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int final[MN], og[MN];
bool done[MN];
pii query[MN];
int main() {
  int n;
  scanf ("%d",&n);
  for (int i = 1; i <= n; i++) scanf ("%d",&og[i]);
  int q;
  scanf ("%d",&q);
  for (int i = 1; i <= q; i++) {
    int type,a,b;
    scanf ("%d %d",&type,&a);
    if (type == 1) scanf ("%d",&b), query[i] = {a,b};
    else query[i] = {a,-1};
  }
  int curmx = -1;
  for (int i = q; i >= 1; i--) {
      if (query[i].second == -1) {
          curmx = max(curmx,query[i].first);
      }
      else {
        if (done[query[i].first]) continue;
        if (curmx == -1) final[query[i].first] = query[i].second;
        else final[query[i].first] = max(query[i].second,curmx);
        done[query[i].first] = 1;
      }
  }
  for (int i = 1; i <= n; i++) {
    if (!done[i]) final[i] = max(og[i],curmx);
    printf ("%d ",final[i]);
  }
  printf ("\n");
  return 0;
}