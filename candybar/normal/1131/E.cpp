#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#include <cassert>
#define maxn 100005

using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;

int n,len[35],nxt[35];
string p[maxn];
bool allsame(string s){
  for(int i = 1;i < (int)s.size();i++) if(s[i] != s[i - 1]) return false;
  return true;
}
int main(){
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i = 1;i <= n;i++) cin >> p[i];
  for(int i = 1;i <= n;i++){
    int m = p[i].size();
    if(allsame(p[i])){
      for(int j = 0;j < 26;j++){
        if(j + 'a' == p[i][0]){
          nxt[j] = min((ll)inf,len[j] + ll(len[j] + 1) * m);
        }else nxt[j] = (len[j] > 0);
      }
    }else{
      int tmp = 0;
      for(int j = 0;j < 26;j++) nxt[j] = (len[j] > 0);
      for(int j = 0;j < m;j++){
        if(i == 0 || p[i][j] == p[i][j - 1]) tmp++;
        else tmp = 1;
        nxt[p[i][j] - 'a'] = max(nxt[p[i][j] - 'a'],tmp);
      }
      int pre = 1, suf = 1;
      for(int j = 1;j < m;j++){
        if(p[i][j] == p[i][j - 1]) pre++;
        else break;
      }
      for(int j = m - 2;j >= 0;j--){
        if(p[i][j] == p[i][j + 1]) suf++;
        else break;
      }
      if(p[i][0] == p[i][m - 1]){
        int c = p[i][0] - 'a';
        if(len[c]) nxt[c] = max(nxt[c],pre + suf + 1);
      }else{
        int c = p[i][0] - 'a', d = p[i][m - 1] - 'a';
        if(len[c]) nxt[c] = max(nxt[c],1 + pre);
        if(len[d]) nxt[d] = max(nxt[d],suf + 1);
      }
    }
    memcpy(len,nxt,sizeof(nxt));
  }
  int ans = 0;
  for(int i = 0;i < 26;i++) ans = max(ans,len[i]);
  printf("%d\n",ans);
  return 0;
}