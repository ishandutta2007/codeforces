#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF =2e15;

struct node
{
  int x,id;
}b[200010];

int cmp(node a,node b)
{
  return a.x > b. x;
}
int a[200010],ans[200010];
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  for(int i=0;i<n;i++) {
    std::cin >> a[i];
  }
  for(int i =0;i<n;i++) {
    b[i].id = i;
    std::cin >> b[i].x;
  }
  sort(a,a+n);
  sort(b,b+n,cmp);
  for(int i=0;i<n;i++){
    ans[b[i].id] = a[i];
  }
  for(int i=0;i<n;i++) {
    std::cout << ans[i] << " ";
  }
  std::cout  << '\n';
  return 0;
}