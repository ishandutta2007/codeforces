#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5;

priority_queue<pair<int,int>> q;
int T,a,b,mark[N];
vector<int> v;
vector<int> res;

int main() {
  scanf("%d",&T);
  int i=0;
  while(T--){
    scanf("%d",&a);
    v.empty();
    if(a==1){
      scanf("%d",&b);
      int k=v.size();
      q.push(make_pair(b,-k));
      v.push_back(b);
    }else if(a==2){
      while(mark[i])++i;
      mark[i]=1;
      res.push_back(i+1);
    }else{
      while(true){
        pair<int,int> p=q.top();
        int j=-p.second;
        q.pop();
        if(!mark[j]){
          mark[j]=1;
          res.push_back(j+1);
          break;
        }
      }
    }
  }
  for(int k=0;k<res.size();++k)printf("%d ",res[k]);
}