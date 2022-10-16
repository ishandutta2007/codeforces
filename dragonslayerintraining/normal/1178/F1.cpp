#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

const int MOD=998244353;

int cs[1000005];
int ds[1000005];
int ds_len=0;

int first[1000][1000];
int dp[1000][1000];

std::vector<int> where[501];

int left[501];
int right[501];

int core[501];

int get_dp(int l,int r);

int get_core(int c){
  if(core[c]!=-1) return core[c];
  int res=1;
  for(int i=0;i+1<where[c].size();i++){
    int a=where[c][i],b=where[c][i+1];
    res=1LL*res*get_dp(a+1,b-1)%MOD;
  }
  core[c]=res;
  //printf("core[%d]=%d\n",c,core[c]);
  return core[c];
}

int get_dp(int l,int r){
  if(l>r) return 1;
  if(dp[l][r]!=-1) return dp[l][r];
  int c=first[l][r];
  int lsum=0,rsum=0;
  for(int a=l;a<=left[c];a++){
    lsum=(lsum+1LL*get_dp(l,a-1)*get_dp(a,left[c]-1))%MOD;
    //printf("lsum+=%dx%d\n",get_dp(l,a-1),get_dp(a,left[c]-1));
  }
  for(int b=right[c];b<=r;b++){
    rsum=(rsum+1LL*get_dp(right[c]+1,b)*get_dp(b+1,r))%MOD;
    //printf("rsum+=%dx%d\n",get_dp(right[c]+1,b),get_dp(b+1,r));
  }
  
  dp[l][r]=1LL*lsum*get_core(c)%MOD*rsum%MOD;
  //printf("dp[%d..%d](%d)=%d\n",l,r,c,dp[l][r]);
  return dp[l][r];
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    scanf("%d",&cs[i]);
  }
  for(int i=0;i<M;i++){
    if(i==0||cs[i]!=cs[i-1]){
      ds[ds_len++]=cs[i];
    }
  }
  if(ds_len>N*2){
    printf("0\n");
    return 0;
  }
  for(int i=0;i<ds_len;i++){
    first[i][i]=ds[i];
  }
  for(int l=0;l<ds_len;l++){
    for(int r=l+1;r<ds_len;r++){
      first[l][r]=std::min(first[l][r-1],ds[r]);
    }
  }
  for(int i=0;i<ds_len;i++){
    where[ds[i]].push_back(i);
    //printf("%d ",ds[i]);
  }
  //printf("\n");
  for(int c=1;c<=N;c++){
    assert(where[c].size());
    left[c]=where[c].front();
    right[c]=where[c].back();
    //printf("%d: [%d..%d]\n",c,left[c],right[c]);
  }
  for(int i=ds_len-1;i>=0;i--){
    left[ds[i]]=i;
  }
  for(int i=1;i<=N;i++){
    if(first[left[i]][right[i]]<i){
      //printf("!!!! %d\n",i);
      printf("0\n");
      return 0;
    }
  }
  for(int i=0;i<ds_len;i++){
    for(int j=0;j<ds_len;j++){
      dp[i][j]=-1;
    }
  }
  for(int i=1;i<=N;i++){
    core[i]=-1;
  }
  printf("%d\n",get_dp(0,ds_len-1));
}