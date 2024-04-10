#include<bits/stdc++.h>
using namespace std;
int mp[26][26];
std::string A,B,s1,s2,ans;
int n,cost;
const int INF = 0x3f3f3f3f;

void flody() {
  for(int k=0;k<26;k++){
    for(int i=0;i<26;i++)
    {
      for(int j=0;j<26;j++){
        mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
      }
    }
  }
}
int main(int argc, char const *argv[]) {
  cin>>A>>B>>n;
  for(int i=0;i<26;i++){
    for(int j=0;j<26;j++){
      mp[i][j]=(i==j?0:INF);
    }
  }
  int a;
  for(int i=0;i<n;i++){
    cin>>s1>>s2>>a;
    int u = s1[0]-'a';
    int v = s2[0]-'a';
    mp[u][v] = min(mp[u][v],a);
  }
  flody();
  if(A.length() != B.length()){
    std::cout << "-1" << '\n';
    return 0;
  }
  cost = 0;
  for(int i=0;i<(int)A.length();i++)
  {
    int u = A[i] - 'a';
    int v = B[i] - 'a';
    int index = 0 ;
    int minn = INF;
    for(int j=0;j<26;j++) {
      if (mp[u][j] + mp[v][j] < minn) {
        minn = mp[u][j] + mp[v][j];
        index = j;
      }
    }
    if (minn >= INF) {
      /* code */
      std::cout << "-1" << '\n';
      return 0;
    }
    cost += minn;
    ans += (index+'a');
  }
  std::cout << cost << '\n';
  std::cout << ans << '\n';
  return 0;
}