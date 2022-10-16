#include <cstdio>
#include <vector>

int as[1000];
int freq[1001];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<=N;i++){
    freq[i]=0;
  }
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    freq[as[i]]++;
  }
  std::vector<int> out;
  while(true){
    int mex=0;
    while(freq[mex]) mex++;
    int choice=-1;
    if(mex<N){
      choice=mex;
    }else{
      for(int i=0;i<N;i++){
	if(as[i]!=i){
	  choice=i;
	  break;
	}
      }
    }
    if(choice==-1) break;
    out.push_back(choice);
    freq[as[choice]]--;
    as[choice]=mex;
    freq[as[choice]]++;
  }
  printf("%d\n",(int)out.size());
  for(int i=0;i<out.size();i++){
    if(i) printf(" ");
    printf("%d",out[i]+1);
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