#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 253456
#define maxW 5234567

pair<int,int> num[maxN],mark[maxW];
int n,a[maxN];
map<int,vector<int>> cnt;
vector<vector<int>> large;
int main() {
  scanf("%d", &n);
  for (int i =1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]].push_back(i);
  }
  for (auto pr:cnt) {
    auto ids=pr.second;
    if (ids.size()>=4) {
      printf("YES\n");
      printf("%d %d %d %d\n",ids[0],ids[1],ids[2],ids[3]);
      return 0;
    }
    if (ids.size()>=2) {
      large.push_back(ids);
      mark[pr.first*2]=make_pair(ids[0],ids[1]);
    }
  }
  if (large.size()>=2) {
    printf("YES\n");
    printf("%d %d %d %d\n",large[0][0],large[1][0],large[0][1],large[1][1]);
    return 0;
  }
  int t=0;
  for (auto pr:cnt) num[t++]={pr.first,pr.second[0]};
  for (int i=0;i<t;i++) {
    for (int j=i+1;j<t;j++) {
      int w=num[i].first+num[j].first;
      if (mark[w]!=make_pair(0,0)) {
        printf("YES\n");
        printf("%d %d %d %d\n",num[i].second,num[j].second,mark[w].first,mark[w].second);
        return 0;
      }
      mark[w]=make_pair(num[i].second,num[j].second);
    }
  }
  printf("NO\n");
}