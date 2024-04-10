#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

void solve(){
  int N,K;
  scanf("%d %d",&N,&K);
  std::set<int> unused;
  for(int i=0;i<N*2;i++){
    unused.insert(i);
  }
  std::vector<std::pair<int,int> > chords;
  for(int i=0;i<K;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    if(X>Y) std::swap(X,Y);
    chords.push_back({X,Y});
    unused.erase(X);
    unused.erase(Y);
  }
  std::vector<int> left(unused.begin(),unused.end());
  for(int i=0;i<left.size()/2;i++){
    chords.push_back({left[i],left[i+left.size()/2]});
  }
  std::sort(chords.begin(),chords.end());
  int cnt=0;
  for(auto a:chords){
    for(auto b:chords){
      if(a.first<b.first&&b.first<a.second&&a.second<b.second){
	cnt++;
      }
    }
  }
  printf("%d\n",cnt);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}