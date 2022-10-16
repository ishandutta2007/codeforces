#include <cstdio>
#include <cassert>
#include <algorithm>

int min[5000][101];
int max[5000][101];
int next=0;

char str[10005];
int at=0;
int limit;

int plus=0,minus=0;

int solve(){
  if(str[at]=='('){
    at++;
    int left=solve();
    assert(str[at]=='?');
    at++;
    int right=solve();
    assert(str[at]==')');
    at++;
    for(int i=0;i+plus<=limit;i++){
      for(int j=0;i+j+plus<=limit;j++){
	min[next][i+j+plus]=std::min(min[next][i+j+plus],
				     min[left][i]+min[right][j]);
	max[next][i+j+plus]=std::max(max[next][i+j+plus],
				     max[left][i]+max[right][j]);
      }
    }
    for(int i=0;i+minus<=limit;i++){
      for(int j=0;i+j+minus<=limit;j++){
	min[next][i+j+minus]=std::min(min[next][i+j+minus],
				      min[left][i]-max[right][j]);
	max[next][i+j+minus]=std::max(max[next][i+j+minus],
				      max[left][i]-min[right][j]);
      }
    }
  }else{
    assert(str[at]>='0'&&str[at]<='9');
    min[next][0]=str[at]-'0';
    max[next][0]=str[at]-'0';
    at++;
  }
  /*
    for(int i=0;i<=limit;i++){
    printf("max[%d][%d]=%d\n",next,i,max[next][i]);
    }
    for(int i=0;i<=limit;i++){
    printf("min[%d][%d]=%d\n",next,i,min[next][i]);
    }
  */
  return next++;
}

int main(){
  int P,M;
  scanf("%s %d %d",str,&P,&M);
  limit=std::min(P,M);
  plus=(P<M);
  minus=1-plus;
  for(int i=0;i<5000;i++){
    std::fill(min[i],min[i]+limit+1,1e5);
    std::fill(max[i],max[i]+limit+1,-1e5);
  }
  printf("%d\n",max[solve()][limit]);
  return 0;
}