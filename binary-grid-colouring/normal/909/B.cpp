#include<bits/stdc++.h>
#include <set>

using namespace std;
typedef long long ll;
const int maxn = 100010;
const int mod = 1e9+7;
#define  pii pair<int,int>
#define fi first
#define se second

int n,m;
string tmp;

struct node{
  int l,r;
  bool operator < (const node &b)const{
    return l < b.l;
  }
};
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<node> v;
  for(int i=1;i<=n;i++) {
    for(int j=i;j<=n;j++) {
      v.push_back({i,j});
    }
  }
  priority_queue<int,std::vector<int>,greater<int>>pq;
  for(int i=0;i<(int)v.size();i++) {
    if(pq.size() && pq.top() < v[i].l){
      pq.pop();
    }
    pq.push(v[i].r);
  }
  std::cout << (int)pq.size()<< '\n';
  return 0;
}