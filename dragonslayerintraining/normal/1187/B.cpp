#include <cstdio>
#include <array>

char str[200005];
std::array<int,26> freq[200005];
char ts[200005];

bool maj(std::array<int,26> a,std::array<int,26> b){
  for(int i=0;i<26;i++){
    if(a[i]<b[i]) return false;
  }
  return true;
}

int main(){
  int N;
  scanf("%d",&N);
  scanf("%s",str);
  for(int i=0;i<N;i++){
    freq[i+1]=freq[i];
    freq[i+1][str[i]-'a']++;
  }
  int M;
  scanf("%d",&M);
  while(M--){
    scanf("%s",ts);
    std::array<int,26> cnt({});
    for(int i=0;ts[i];i++){
      cnt[ts[i]-'a']++;
    }
    int low=0,high=N;
    while(high-low>1){
      int mid=(low+high)/2;
      if(maj(freq[mid],cnt)){
	high=mid;
      }else{
	low=mid;
      }
    }
    printf("%d\n",high);
  }
    
  return 0;
}