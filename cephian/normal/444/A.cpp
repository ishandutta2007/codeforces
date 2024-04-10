#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 505;
int n,m;
int wt[N];

int main() {
  scanf("%d%d",&n,&m);
  for(int i = 1; i <= n; ++i) {
    scanf("%d",wt+i);
  }
  double mx = 0;
  for(int i = 0; i < m; ++i) {
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    mx = max(mx,double(wt[u]+wt[v])/w);
  }
  printf("%.12lf\n",mx);
}