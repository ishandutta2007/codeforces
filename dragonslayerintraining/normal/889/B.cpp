#include <cstdio>
#include <string>
#include <algorithm>

int next[26];
int occur[26];
int reached[26];

char str[100005];

std::string res;

int distinct=0;

int main(){
  std::fill(next,next+26,-1);
  
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%s",str);
    for(int i=0;str[i];i++){
      occur[str[i]-'a']=1;
    }
    for(int i=1;str[i];i++){
      if((next[str[i-1]-'a']!=-1)&&(next[str[i-1]-'a']!=(str[i]-'a'))){
	printf("NO\n");
	return 0;
      }
      next[str[i-1]-'a']=str[i]-'a';
      reached[str[i]-'a']=1;
    }
  }
  for(int i=0;i<26;i++){
    distinct+=occur[i];
  }
  for(int i=0;i<26;i++){
    if(occur[i]&&!reached[i]){
      res.push_back('a'+i);
      distinct--;
      for(int k=next[i];(k!=i)&&(k!=-1);k=next[k]){
	res.push_back('a'+k);
	distinct--;
	if(distinct<0){
	  printf("NO\n");
	  return 0;
	}
      }
    }
  }
  if(distinct>0){
    printf("NO\n");
    return 0;
  }
  printf("%s\n",res.c_str());
  return 0;
}