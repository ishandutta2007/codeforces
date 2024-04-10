#include<bits/stdc++.h>

using namespace std;
const int maxn = 200100;
const double eps = 1e-9;

struct node {
  int x,y;
  node(){}
  node(int x,int y) : x(x),y(y){}
  node operator +(const node &a)const{
    return node(x + a.x,y + a.y);
  }
  node operator -(const node &a)const{
    return node( x- a.x,y - a.y);
  }
  bool operator ==(const node &a) const{
    return x == a.x && y == a.y;
  }
  bool operator !=(const node &a)const{
    return x != a.x || y != a.y;
  }
  bool operator < (const node &a)const {
    return x < a.x || (x == a.x && y < a.y);
  }

}p[maxn];
int n,k;

int solve(node x)
{
  int cnt = 0;
  int j = n;
  for(int i = 1; i <= n; i++) {
    while(p[i] + p[j] != x  && (i == n || x  < p[i+1] + p[j] ) && j > 1){
      j--;
    }
    if(p[i] + p[j] != x){
      cnt++;
    }
    else j--;
    if(cnt > k) return 0;
  }
  return 1;
}
int main(int argc, char const *argv[]) {

  //std::cin >> n >> k;
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++) {
    // cin>>p[i].x>>p[i].y;
    scanf("%d%d",&p[i].x,&p[i].y);
  }
  if(k>=n) {
    std::cout << "-1" << '\n';
    return 0;
  }
  sort(p+1,p+n+1);
  std::vector<node> ans;
  for(int i = 1; i <= k + 1 ;i++) {
    for(int j = n - k; j <= n;j++) {
      int x = p[i].x + p[j].x;
      int y = p[i].y + p[j].y;
      if(solve(node(x,y))){
        ans.push_back(node(x,y));
      }
    }
  }
  sort(ans.begin(),ans.end());
  ans.erase(unique(ans.begin(),ans.end()),ans.end());
  std::cout << (int)ans.size() << '\n';
  for(auto pp : ans) {
    printf("%.1f %.1f\n", pp.x * 0.5, pp.y * 0.5);
  }
  return 0;
}