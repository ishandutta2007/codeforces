#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

vector <int> V;

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    V.push_back(1);
    for (; V.size() >= 2 && V.back() == V[V.size()-2]; ) {
      int tmp = V.back();
      V.pop_back();
      V.pop_back();
      V.push_back(tmp + 1);
    }
  }

  for (int i=0; i<(int) V.size(); i++)
    printf("%d ", V[i]);

  return 0;
}