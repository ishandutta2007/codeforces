#include <cstdio>
#include <vector>

std::vector<std::pair<int,int> > left,right;
int lcom[20],rcom[20];
int N,M;
int common(int i,int j){
  if(left[i].first==right[j].first&&
     left[i].second!=right[j].second) return left[i].first;
  if(left[i].first==right[j].second&&
     left[i].second!=right[j].first) return left[i].first;
  if(left[i].second==right[j].first&&
     left[i].first!=right[j].second) return left[i].second;
  if(left[i].second==right[j].second&&
     left[i].first!=right[j].first) return left[i].second;
  return 0;
}

void addinfo(int& x,int y){
  if(x==-1||x==y){
    x=y;
  }else{
    x=0;
  }
}

bool theyknow(){
  for(int i=0;i<N;i++){
    if(lcom[i]==0) return false;
  }
  for(int j=0;j<M;j++){
    if(rcom[j]==0) return false;
  }
  return true;
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    left.emplace_back(a,b);
  }
  for(int i=0;i<M;i++){
    int a,b;
    scanf("%d %d",&a,&b);
    right.emplace_back(a,b);
  }
  std::fill(lcom,lcom+N,-1);
  std::fill(rcom,rcom+M,-1);
  int ac=-1;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      int com=common(i,j);
      if(com==0) continue;
      addinfo(lcom[i],com);
      addinfo(rcom[j],com);
      addinfo(ac,com);
    }
  }
  if(ac>0){
    printf("%d\n",ac);
  }else if(theyknow()){
    printf("0\n");
  }else{
    printf("-1\n");
  }
  return 0;
}