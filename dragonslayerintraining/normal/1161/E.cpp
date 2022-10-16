#include <cstdio>
#include <vector>
#include <cstdlib>

bool tailq[100005];
bool same[100005];

std::vector<std::pair<int,int> > qs;
char res[100005];
int curr=0;

int color[100005];
//char ans[100005];

void ask(){
  /*
  for(int i=0;i<qs.size();i++){
    res[i]='0'+(ans[qs[i].first]==ans[qs[i].second]);
  }
  */
  if(!qs.empty()){
    printf("Q %d",(int)qs.size());
    for(auto q:qs){
      printf(" %d %d",q.first+1,q.second+1);
    }
    printf("\n");
    fflush(stdout);
    scanf("%s",res);
  }
  
  if(res[0]=='-') exit(0);
  curr=0;
  qs.clear();
}

void solve(){
  int N;
  scanf("%d",&N);
  //scanf("%s",ans);
  for(int s=0;s<2;s++){
    for(int i=s;i<N-1;i+=2){
      qs.push_back({i,i+1});
    }
    ask();
    for(int i=s;i<N-1;i+=2){
      tailq[i]=(res[curr++]=='0');
    }
  }
  tailq[N-1]=true;
  std::vector<int> tails;
  for(int i=0;i<N;i++){
    //printf("tailq[%d]=%d\n",i,tailq[i]);
    if(tailq[i]){
      tails.push_back(i);
    }
  }
  for(int s=0;s<4;s+=2){
    for(int i=s;i+2<tails.size();i+=4){
      qs.push_back({tails[i],tails[i+2]});
      if(i+3<tails.size()){
	qs.push_back({tails[i+1],tails[i+3]});
      }
    }
    ask();
    for(int i=s;i+2<tails.size();i+=4){
      same[tails[i]]=(res[curr++]=='1');
      if(i+3<tails.size()){
	same[tails[i+1]]=(res[curr++]=='1');
      }
    }
  }
  for(int i=tails.size()-1;i>=std::max<int>(tails.size()-2,0);i--){
    color[tails[i]]=i%3+1;
  }
  for(int i=tails.size()-3;i>=0;i--){
    if(same[tails[i]]){
      color[tails[i]]=color[tails[i+2]];
    }else{
      color[tails[i]]=color[tails[i+1]]^color[tails[i+2]];
    }
  }
  /*
    for(int i=0;i<N;i++){
    printf("same[%d]=%d\n",i,same[i]);
    }
  */
  for(int i=N-1;i>=0;i--){
    if(!tailq[i]){
      color[i]=color[i+1];
    }
  }
  std::vector<int> groups[4];
  for(int i=0;i<N;i++){
    groups[color[i]].push_back(i);
  }
  /*
  for(int i=0;i<N;i++){
    printf("%d",same[i]);
  }
  printf("\n");
    for(int i=0;i<N;i++){
    printf("%d",color[i]);
  }
  printf("\n");
  */
  printf("A %d %d %d\n",(int)groups[1].size(),
	 (int)groups[2].size(),
	 (int)groups[3].size());
  for(int c=1;c<=3;c++){
    for(int x:groups[c]){
      printf("%d ",x+1);
    }
    printf("\n");
  }
  fflush(stdout);
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}