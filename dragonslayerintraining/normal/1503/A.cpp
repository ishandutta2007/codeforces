#include <cstdio>
#include <algorithm>
#include <string>

char str[200005];

void solve(){
  int N;
  scanf("%d",&N);
  scanf("%s",str);
  std::string a(N,'?'),b(N,'?');
  int ones=std::count(str,str+N,'1');
  if(ones%2){
    printf("NO\n");
    return;
  }
  ones/=2;
  int open=0;
  bool flip=false;
  for(int i=0;i<N;i++){
    if(str[i]=='1'){
      if(--ones>=0){
	a[i]=b[i]='(';
	open++;
      }else{
	a[i]=b[i]=')';
	open--;
      }
    }else{
      if(flip){
	a[i]='(',b[i]=')';
	open++;
      }else{
	a[i]=')',b[i]='(';
	open--;
      }
      flip^=1;
    }
    if(open<0){
      printf("NO\n");
      return;
    }
  }
  printf("YES\n%s\n%s\n",a.c_str(),b.c_str());
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}