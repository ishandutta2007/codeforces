#include <cstdio>
#include <vector>

int query(int l,int r){
  printf("? 2 %d %d\n",l+1,r+1);
  fflush(stdout);
  int res;
  scanf("%d",&res);
  return res;
}

int prev[1005];
char str[1005];

int main(){
  int N;
  scanf("%d",&N);
  std::vector<int> last;
  for(int i=0;i<N;i++){
    int low=0,high=last.size()+1;
    while(high-low>1){
      int mid=(low+high)/2;
      if(query(last[last.size()-mid],i)!=mid){
	low=mid;
      }else{
	high=mid;
      }
    }
    if(high==last.size()+1){
      prev[i]=-1;
    }else{
      prev[i]=last[last.size()-high];
      last.erase(last.end()-high);
    }
    last.push_back(i);
  }
  for(int k=0;k<last.size();k++){
    printf("? 1 %d\n",last[k]+1);
    fflush(stdout);
    char res;
    scanf(" %c",&res);
    for(int i=last[k];i!=-1;i=prev[i]){
      str[i]=res;
    }
  }
  printf("! %s\n",str);
}