#include <cstdio>
#include <cstring>
#include <bitset>

char str[100005][4];

std::bitset<26*26> f,g;
std::bitset<26*26*26> h;

int hsh(char a,char b){
  return (a-'a')*26+(b-'a');
}

int hsh(char a,char b,char c){
  return hsh(a,b)*26+(c-'a');
}

bool solve(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%s",str[i]);
  }
  for(int i=0;i<N;i++){
    const char* s=str[i];
    if(strlen(s)==1){
      return true;
    }
    if(s[0]==s[strlen(s)-1]){
      return true;
    }
  }
  f.reset();
  g.reset();
  h.reset();
  for(int i=0;i<N;i++){
    const char* s=str[i];
    if(strlen(s)==2){
      if(f.test(hsh(s[1],s[0]))){
	return true;
      }
      if(g.test(hsh(s[1],s[0]))){
	return true;
      }
      f.set(hsh(s[0],s[1]));
    }else{
      if(f.test(hsh(s[2],s[1]))){
	return true;
      }
      if(h.test(hsh(s[2],s[1],s[0]))){
	return true;
      }
      h.set(hsh(s[0],s[1],s[2]));
      g.set(hsh(s[0],s[1]));
    }
  }
  return false;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    if(solve()){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
}