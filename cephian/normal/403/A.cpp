#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <utility>

using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
typedef pair<int,int> pii;

set<pii> e;

int main() {
  int t;
  scanf("%d",&t);
  while(t--) {
    int n,p;
    scanf("%d%d",&n,&p);
    int q = 0;
    p+=2*n;
    for(int a = 1; q != p && a <= n; ++a) {
      for(int b = a+1; q != p && b <= n; ++b) {
        ++q;
        printf("%d %d\n",a,b);
      }
    }
  }
  return 0;
}