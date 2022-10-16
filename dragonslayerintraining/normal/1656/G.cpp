#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

bool vis[200005];
int from[200005];

void mark(int i){
  while(!vis[i]){
    vis[i]=true;
    i=from[i];
  }
}

void solve(){
  int N;
  scanf("%d",&N);
  std::vector<std::vector<int> > where(N+1);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    where[A].push_back(i);
  }
  bool can_odd=(N%2==1);
  int l=(N+1)/2;
  for(int a=1;a<=N;a++){
    if(where[a].size()%2==1){
      if(!can_odd){
	printf("NO\n");
	return;
      }
      can_odd=false;
      if(where[a][0]==(N-1)/2){
	if(where[a].size()==1){
	  printf("NO\n");
	  return;
	}
	std::swap(where[a][0],where[a][1]);
      }
      from[(N-1)/2]=where[a][0];
      for(int k=1;k<where[a].size();k+=2){
	from[l]=where[a][k];
	from[N-1-l]=where[a][k+1];
	l++;
      }
    }else{
      for(int k=0;k<where[a].size();k+=2){
	from[l]=where[a][k];
	from[N-1-l]=where[a][k+1];
	l++;
      }
    }
  }
  assert(l==N);
  std::fill(vis,vis+N,false);
  mark(N/2);
  int j=from[N/2];
  //j is some non-center point inside growing component
  if(!vis[N-1-j]){
    mark(N-1-j);
    std::swap(from[j],from[N-1-j]);
  }
  for(int i=N/2;i<N;i++){
    if(vis[i]&&vis[N-1-i]) continue;
    if(vis[i]||vis[N-1-i]){
      mark(i);
      mark(N-1-i);
      std::swap(from[i],from[N-1-i]);
    }else{
      mark(i);
      bool flag=vis[N-1-i];
      mark(N-1-i);
      std::swap(from[i],from[j]);
      std::swap(from[N-1-i],from[N-1-j]);
      if(flag){
	std::swap(from[i],from[N-1-i]);
      }
    }
  }
  printf("YES\n");
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",from[i]+1);
  }
  printf("\n");
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}