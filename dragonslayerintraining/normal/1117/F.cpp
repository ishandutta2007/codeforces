#include <cstdio>
#include <vector>
#include <algorithm>

char str[100005];
int last[17];

int bad[1<<17];
int len[1<<17];
int ok[1<<17];

int as[17][17];

int main(){
  int N,P;
  scanf("%d %d",&N,&P);
  scanf("%s",str);
  for(int i=0;i<N;i++){
    len[1<<(str[i]-'a')]++;
  }
  for(int i=0;i<P;i++){
    for(int j=0;j<P;j++){
      scanf("%d",&as[i][j]);
    }
  }
  std::fill(last,last+P,-1);
  std::vector<int> ord;
  for(int i=0;i<N;i++){
    int c1=str[i]-'a';
    std::sort(ord.begin(),ord.end(),[](int i,int j){return last[i]>last[j];});
    int allowed=(1<<P)-1;
    for(int c2:ord){
      //printf("recent %d: %d\n",i,c2);
      if(!as[c1][c2]){
	/*
printf("forbid (%c,%c): ",c2+'a',c1+'a');
	for(int k=0;k<P;k++){
	  putchar((k==c1||k==c2)?'1':((allowed&(1<<k))?'*':'0'));
	}putchar('\n');
	*/
	bad[allowed^(1<<c1)^(1<<c2)]++;
	bad[allowed^(1<<c1)]--;
	bad[allowed^(1<<c2)]--;
	bad[allowed]++;
	/*
printf("bad[%d]++\n",allowed^(1<<c1)^(1<<c2));
	printf("bad[%d]--\n",allowed^(1<<c1));
	printf("bad[%d]--\n",allowed^(1<<c2));
	printf("bad[%d]++\n",allowed);
	*/
      }
      allowed^=(1<<c2);
      if(c1==c2) break;
    }
    if(last[c1]==-1){
      ord.push_back(c1);
    }
    last[c1]=i;
  }
  for(int k=0;k<P;k++){
    for(int i=0;i<(1<<P);i++){
      if(i&(1<<k)) continue;
      bad[i]+=bad[i|(1<<k)];
    }
  }
  /*
  for(int i=0;i<(1<<P);i++){
    printf("bad[%d]=%d\n",i,bad[i]);
  }
  */
  for(int k=0;k<P;k++){
    for(int i=0;i<(1<<P);i++){
      if(i&(1<<k)) continue;
      len[i|(1<<k)]+=len[i];
    }
  }
  ok[(1<<P)-1]=1;
  for(int i=(1<<P)-1;i>=0;i--){
    for(int k=0;k<P;k++){
      if(i&(1<<k)) continue;
      if(bad[i]==0&&bad[i|(1<<k)]==0){
	ok[i]|=ok[i|(1<<k)];
      }
    }
    //printf("ok[%d]=%d\n",i,ok[i]);
  }
  int best=N;
  for(int i=0;i<(1<<P);i++){
    if(ok[i]){
      /*
      for(int k=0;k<P;k++){
	printf("%d",(i>>k)&1);
      }
      printf("\n");
      */
      best=std::min(best,len[i]);
    }
  }
  printf("%d\n",best);
  return 0;
}