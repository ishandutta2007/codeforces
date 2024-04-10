#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

int p[MAX];

int main()
{
  int n;

  cin >> n;
  for (int i=0; i<n; i++)
    scanf("%d", &p[i]);

  sort(p, p + n);
  int q;

  scanf("%d", &q);

  for (; q--; ) {
    int x;
    scanf("%d",  &x);
    printf("%d\n", (int) (upper_bound(p, p + n, x) - p));
  }

	return 0;
}