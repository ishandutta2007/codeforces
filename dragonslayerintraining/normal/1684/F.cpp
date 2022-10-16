#include <cstdio>
#include <map>
#include <vector>
#include <cassert>

void solve(){
  int N,M;
  scanf("%d %d",&N,&M);
  std::map<int,std::vector<int> > where;
  std::vector<int> ls(N,N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    where[A].push_back(i);
  }
  for(int i=0;i<M;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    L--,R--;
    ls[R]=std::min(ls[R],L);
  }
  for(int i=N-2;i>=0;i--){
    ls[i]=std::min(ls[i],ls[i+1]);
  }
  int min_right=0,max_left=N;
  std::vector<int> banned(N,N);
  for(int i=0;i<N;i++){
    banned[i]=i+1;
  }
  auto ban = [&banned,N](int l,int r){
    l=std::max(l,0);
    r=std::min(r,N-1);
    if(l<=r){
      //printf("ban [%d,%d]\n",l,r);
      banned[r]=std::min(banned[r],l);
    }
  };
  bool bad=false;
  for(auto it:where){
    auto& pos=it.second;
    int j=0;
    for(int i=0;i<pos.size();i++){
      while(j<i&&pos[j]<ls[pos[i]]){
	j++;
      }
      if(i!=j){
	min_right=std::max(min_right,pos[i-1]);
	max_left=std::min(max_left,pos[j+1]);
	//note pos[i]>0 since i>j
	ban(0,pos[i-1]-1);
	ban(pos[j]+1,pos[i]-1);
	ban(pos[j+1]+1,N-1);
	bad=true;
      }
    }
  }
  if(!bad){
    printf("0\n");
    return;
  }
  int best=N;
  int l=N-1;
  for(int r=N-1;r>=0;r--){
    //printf("ban[%d]=%d\n",r,banned[r]);
    l=std::min(l,banned[r]-1);
    if(l<0) break;
    //printf("good: [%d,%d]\n",l,r);
    best=std::min(best,r-l+1);
  }
  printf("%d\n",best);
}


int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}