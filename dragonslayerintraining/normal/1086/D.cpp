#include <cstdio>
#include <algorithm>
#include <string>

std::string rps="RPS";

struct Node{
  int cnt[3][3][3];//type,lstate,rstate
  int mask;
  //States:
  //0: all of same type
  //1: all of same or defeated
  //2: some it can defeat
  void clear(){
    for(int k=0;k<3;k++){
      for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
	  cnt[k][i][j]=0;
	}
      }
    }
    mask=0;
  }
  Node(){
    clear();
  }
  Node(int t){
    clear();
    cnt[t][0][0]=1;
    mask=(1<<t);
  }
}st[400005];
int N;

int minstate(int k,int mask){
  if(mask&(1<<((k+2)%3))){
    return 2;
  }else if(mask&(1<<((k+1)%3))){
    return 1;
  }else{
    return 0;
  }
}

struct Node combine(const struct Node& a,const struct Node& b){
  struct Node res;
  //printf("Combining...");
  for(int k=0;k<3;k++){
    int j2=minstate(k,b.mask);
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	res.cnt[k][i][std::max(j,j2)]+=a.cnt[k][i][j];
      }
    }
  }
  for(int k=0;k<3;k++){
    int i2=minstate(k,a.mask);
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	res.cnt[k][std::max(i,i2)][j]+=b.cnt[k][i][j];
      }
    }
  }
  /*
  for(int k=0;k<3;k++){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	if(res.cnt[k][i][j]) printf("%d%c(%d,%d)",res.cnt[k][i][j],rps[k],i,j);
      }
    }
  }
  printf("\n");
  */
  res.mask=a.mask|b.mask;
  return res;
}

struct Node query(int a,int b){
  struct Node left,right;
  for(a+=N,b+=N;a<b;a>>=1,b>>=1){
    if(a&1) left=combine(left,st[a++]);
    if(b&1) right=combine(st[--b],right);
  }
  return combine(left,right);
}

void answer(){
  struct Node q=query(0,N);
  int ans=0;
  /*
  for(int i=0;i<N;i++){
    printf("%d: %d\n",i,st[i+N].mask);
  }
  */
  for(int k=0;k<3;k++){
    /*
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
	if(q.cnt[k][i][j]){
	  printf("%d are %c,%d,%d\n",q.cnt[k][i][j],rps[k],i,j);
	}
      }
    }
    */
    ans+=q.cnt[k][0][0];
    ans+=q.cnt[k][0][2];
    ans+=q.cnt[k][2][0];
    ans+=q.cnt[k][2][2];
  }
  printf("%d\n",ans);
}

int main(){
  int Q;
  scanf("%d %d ",&N,&Q);
  for(int i=0;i<N;i++){
    int t=std::find(rps.begin(),rps.end(),getchar())-rps.begin();
    st[i+N]=Node(t);
  }
  for(int i=N-1;i>0;i--){
    st[i]=combine(st[i<<1],st[i<<1|1]);
  }
  answer();
  for(int i=0;i<Q;i++){
    int P;
    scanf("%d ",&P);
    P--;
    int t=std::find(rps.begin(),rps.end(),getchar())-rps.begin();
    st[P+N]=Node(t);
    P+=N;
    for(P>>=1;P>0;P>>=1){
      st[P]=combine(st[P<<1],st[P<<1|1]);
    }
    answer();
  }
  return 0;
}