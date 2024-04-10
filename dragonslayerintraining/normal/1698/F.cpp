#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

int as[505];
int bs[505];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&bs[i]);
  }
  if(as[0]!=bs[0]){
    printf("NO\n");
    return;
  }
  std::vector<std::pair<int,int> > moves;
  auto rev=[&](int l,int r){
    moves.emplace_back(l,r);
    std::reverse(as+l,as+r+1);
    /*
    printf("rev[%d:%d]:",l,r);
    for(int i=0;i<N;i++){
      printf("%d ",as[i]);
    }
    printf("\n");
    */
  };
  auto fix1=[&](int i){
    int x=as[i-1],y=bs[i];
    for(int j=i;j+1<N;j++){
      if(as[j]==y&&as[j+1]==x){
	rev(i-1,j+1);
	return true;
      }
    }
    return false;
  };
  auto fix2=[&](int i){
    int x=as[i-1],y=bs[i];
    for(int j=i;j+1<N;j++){
      if(as[j]==x&&as[j+1]==y){
	std::map<int,int> last;
	for(int k=i;k<=j;k++){
	  last[as[k]]=k;
	}
	for(int k=j+1;k<N;k++){
	  if(last.count(as[k])){
	    rev(last[as[k]],k);
	    return fix1(i);//should succeed
	  }
	}
	return false;
      }
    }
    return false;
  };
  for(int i=1;i<N;i++){
    if(as[i]==bs[i]) continue;
    if(fix1(i)) continue;
    if(fix2(i)) continue;
    printf("NO\n");
    return;
  }
  printf("YES\n%d\n",(int)moves.size());
  for(auto m:moves){
    printf("%d %d\n",m.first+1,m.second+1);
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}