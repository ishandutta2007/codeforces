#include <cstdio>
#include <vector>
#include <set>

int N;

int as[150005];

int maxp[1000006];

int uf[1000006];

std::set<std::pair<int,int> > one;

int find(int a){
  while(a!=uf[a]){
    a=uf[a]=uf[uf[a]];
  }
  return a;
}

int main(){
  for(int i=1;i<=1000005;i++){
    uf[i]=i;
  }
  for(int i=2;i<=1000005;i++){
    if(maxp[i]) continue;
    for(int j=i;j<=1000005;j+=i){
      maxp[j]=i;
    }
  }
  int Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    std::vector<int> primes;
    for(int x=as[i];x>1;x/=maxp[x]){
      primes.push_back(maxp[x]);
    }
    for(int i=0;i+1<primes.size();i++){
      uf[find(primes[i])]=find(primes[i+1]);
    }
  }
  for(int i=0;i<N;i++){
    std::set<int> cmpts;
    cmpts.insert(find(maxp[as[i]]));
    for(int x=as[i]+1;x>1;x/=maxp[x]){
      cmpts.insert(find(maxp[x]));
    }
    for(int x:cmpts){
      for(int y:cmpts){
	one.insert({x,y});
      }
    }
  }
  while(Q--){
    int S,T;
    scanf("%d %d",&S,&T);
    int X=find(maxp[as[S-1]]),Y=find(maxp[as[T-1]]);
    if(X==Y){
      printf("0\n");
    }else if(one.count(std::make_pair(X,Y))){
      printf("1\n");
    }else{
      printf("2\n");
    }
  }

}