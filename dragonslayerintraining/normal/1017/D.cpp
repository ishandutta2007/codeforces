#include <cstdio>
#include <algorithm>

int ws[16];

int readbin(){
  char str[16];
  scanf("%s",str);
  int res=0;
  for(int i=0;str[i];i++){
    res=res*2+str[i]-'0';
  }
  return res;
}

int cnt[1<<12];
int wu[1<<12][(1<<12)+1];
int pat[1<<12];

std::pair<int,int> pat_sort[1<<12];

int main(){
  int N,M,Q;
  scanf("%d %d %d",&N,&M,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&ws[i]);
  }
  std::reverse(ws,ws+N);
  
  pat[0]=0;
  for(int k=0;k<N;k++){
    pat[1<<k]=ws[k];
  }
  for(int k=1;k<(1<<N);k++){
    int lsb=(k&-k);
    pat[k]=pat[k-lsb]+pat[lsb];
  }
  
  for(int i=0;i<(1<<N);i++){
    pat_sort[i].first=pat[i];
    pat_sort[i].second=i^((1<<N)-1);
    //printf("PAT_SORT[%d]=(%d,%d)\n",i,pat_sort[i].first,pat_sort[i].second);
  }
  std::sort(pat,pat+(1<<N));
  std::sort(pat_sort,pat_sort+(1<<N));
  
  for(int i=0;i<M;i++){
    int x=readbin();
    cnt[x]++;
  }
  
  for(int k=0;k<(1<<N);k++){
    int ac=0;
    for(int i=0;i<(1<<N);i++){
      int x=pat_sort[i].second;
      wu[k][i]=ac;
      //printf("WU[%d][%d]=%d\n",k,i,wu[k][i]);
      ac+=cnt[k^x];
    }
    wu[k][1<<N]=ac;
    //printf("WU[%d][%d]=%d\n",k,1<<N,wu[k][1<<N]);
  }
  for(int i=0;i<Q;i++){
    int x=readbin();
    int K;
    scanf("%d",&K);
    printf("%d\n",wu[x][std::upper_bound(pat,pat+(1<<N),K)-pat]);
  }
  return 0;
}