#include <cstdio>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int> > P;
#define X first
#define Y second

const int MAX = 100100;

int poc[MAX], p[MAX];
int n;

ll Rijesi(int l, int r)
{
  ll ret = 0;

  stack <P> S;

  ll tmp = 0;
  for (int i=l; i<r; i++) {
    for (; !S.empty(); ) {
      if (p[i] >= S.top().X) {
        tmp += S.top().Y.X * ((ll) p[i] - S.top().X);
        S.pop();
      }
      else
        break;
    }

    tmp += p[i];
    ret += tmp;
    int prij = l - 1;
    if (!S.empty())
      prij = S.top().Y.Y;

    S.push(P(p[i], make_pair(i - prij, i)));
  }

  return ret;
}

int main()
{
  int brq;

  scanf("%d%d", &n, &brq);

  for (int i=0; i<n; i++) {
    scanf("%d", &poc[i]);
    if (i)
      p[i-1] = abs(poc[i] - poc[i-1]);    
  }

  for (; brq; brq--) {
    int l, r;
    scanf("%d%d", &l, &r); l--; r--;
    cout << Rijesi(l, r) << endl;
  }

  return 0;
}