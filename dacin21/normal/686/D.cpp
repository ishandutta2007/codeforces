#include <bits/stdc++.h>

using namespace std;

vector<int> p;
vector<vector<int> > childs;
vector<int> subSize;
vector<int> maxChild;
vector<int> cent;

void dfs(int cur){
  subSize[cur]=1;
  maxChild[cur]=0;
  int bigChild=-1;
  for(auto &e:childs[cur]){
    dfs(e);
    subSize[cur]+=subSize[e];
    if(subSize[e]>maxChild[cur]){
      maxChild[cur]=subSize[e];
      bigChild=e;
    }
  }
  if(maxChild[cur]*2 <=subSize[cur]){
    cent[cur]=cur;
    return;
  }
  assert(bigChild!=-1);
  int &i=cent[cur];
  for(i=cent[bigChild];2*(subSize[cur]-subSize[i])>subSize[cur];i=p[i]){

  }

}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N, Q, a;
    cin >> N >> Q;
    p.resize(N);
    childs.resize(N);
    subSize.resize(N);
    maxChild.resize(N);
    cent.resize(N);
    for(int i=1;i<N;++i){
      cin >> p[i];
      childs[--p[i]].emplace_back(i);
    }
    dfs(0);
    for(int i=0;i<Q;++i){
      cin >> a;
      cout << cent[--a]+1 << "\n";
    }
    return 0;
}