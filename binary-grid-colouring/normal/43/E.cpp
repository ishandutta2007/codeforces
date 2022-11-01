#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,s;
std::vector<pair<int,int>> seg[123];

int get_ans(int x,int y)
{
  int ans = 0;
  int dx = 0 , dy = 0;
  int t = 0;
  int lastx = 0, nowx = 0 ;
  int lasty = 0, nowy = 0;
  while(nowx < s && nowy < s)
  {
     int tmp = min(seg[x][dx].second,seg[y][dy].second) - t;
     t += tmp;
     /*
    x     -----
    y:   --------
      this case is not a "lead"
     */
     if(nowx != nowy)
     {
       lastx = nowx;
       lasty = nowy;
     }
     nowx += seg[x][dx].first * tmp;
     nowy += seg[y][dy].first * tmp;
     if(1LL * (lastx - lasty) * (nowx - nowy) < 0 )
     {
       ans++;
     }
     if(seg[x][dx].second < seg[y][dy].second) {
       dx++;
     }
     else if(seg[x][dx].second > seg[y][dy].second) {
       dy++;
     }
     else{
       dx++;
       dy++;
     }
  }
  return ans;
}
int main(int argc, char const *argv[]) {

   std::cin >> n >> s;
   int c;
   for (size_t i = 0; i < n ; i++) {
     /* code */
     std::cin >> c;
     for(int j = 0;j < c ;j++) {
       int v,t;
       std::cin >> v >> t;
       seg[i].push_back(make_pair(v,t));
     }
     for(int j = 1; j < c;j++) {
       seg[i][j].second += seg[i][j-1].second;
     }
   }
   int ans = 0;
   for (size_t i = 0; i < n; i++) {
     /* code */
     for (size_t j = i + 1; j < n; j++) {
       ans += get_ans(i,j);
     }
   }
   std::cout << ans << '\n';
   return 0;
}