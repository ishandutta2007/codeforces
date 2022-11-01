#include<bits/stdc++.h>

using namespace std;
const int maxn = 2000;
const double eps = 1e-9;


int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};
int n,m;
int sx = 0 ,sy = 0;
int res[4];
int main(int argc, char const *argv[]) {
  /* code */
  int ans = 0;
  std::cin >> n >> m;
  std::vector<string> s(n);
  for(int i=0;i<n;i++) {
    std::cin >> s[i];
    for(int j=0;j<m;j++) {
      if(s[i][j] =='S') {
        sx = i;
        sy = j;
      }
    }
  }
  //std::cerr << "/* error message */" << '\n';
  
//  std::cerr << "/* error message */" << '\n';
  string ss;
  std::cin >> ss;
  for(int i = 0;i < 4;i++) {
    res[i] = i;
  }
  ans = 0;
  do {
    /* code */
    bool ok=true;
    int nextx = sx, nexty = sy;
    for(int i=0;i<(int)ss.size() &&ok==true;i++) {
      int pos = res[ss[i] - '0'];
      nextx+=dx[pos];
      nexty+=dy[pos];
      if(nextx>=n||nextx < 0||nexty >= m|| nexty < 0||s[nextx][nexty] == '#')
      {
        ok = false;break;
      }
      if(s[nextx][nexty] == 'E') 
      {
        break;
      }
    }
    if (ok==true)
    {
      ok&=(s[nextx][nexty]=='E');
    }
    ans+=(ok==true?1:0);
  //  std::cout << "ans=" << ans << '\n';
  }while (next_permutation(res, res+4));
  //std::cerr << "/* error message */" << '\n';
  std::cout << ans << '\n';
  return 0;
}