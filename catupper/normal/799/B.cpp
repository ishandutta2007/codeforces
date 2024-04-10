#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

set<int> buy;
set<int> ok[4];
int n;
int p[216000];
int a[216000];
int b[216000];
int main(){
  cin >> n;
  for(int i = 0;i < n;i++)cin >> p[i];
  for(int i = 0;i < n;i++)cin >> a[i];
  for(int i = 0;i < n;i++)cin >> b[i];
  for(int i = 0;i < n;i++){
    ok[a[i]].insert(p[i]);
    ok[b[i]].insert(p[i]);
  }
  int m, c;
  cin >> m;
  for(int i = 0;i < m;i++){
    cin >> c;
    int done = 0;
    while(!ok[c].empty()){
      int tmp = *ok[c].begin();
      ok[c].erase(ok[c].begin());
      if(buy.count(tmp))continue;
      printf("%d ",tmp);
      buy.insert(tmp);
      done = 1;
      break;
    }
    if(done == 0)printf("-1 ");
  }
  puts("");
  return 0;
}