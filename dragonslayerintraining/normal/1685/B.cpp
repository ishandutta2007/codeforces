#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

char str[200005];

bool solve(){
  int A,B,C,D;
  scanf("%d %d %d %d",&A,&B,&C,&D);
  scanf("%s",str);
  int N=A+B+2*C+2*D;
  if(A+C+D!=std::count(str,str+N,'A')) return false;
  int wild=0;
  std::vector<int> abs,bas;
  int start=0;
  for(int i=1;i<=N;i++){
    if(i==N||str[i]==str[i-1]){
      //segment of length i-start
      int len=i-start;
      if(len%2==1){
	wild+=len/2;
	//printf("wild %d\n",len/2);
      }else{
	if(str[start]=='A'){
	  //printf("ABx%d\n",len/2);
	  C-=len/2;
	  abs.push_back(len/2);
	}else{
	  //printf("BAx%d\n",len/2);
	  D-=len/2;
	  bas.push_back(len/2);
	}
      }
      start=i;
    }
  }
  //printf("C=%d, D=%d\n",C,D);
  if(C<=0&&D<=0) return true;
  if(C>0&&D>0){
    return C+D<=wild;
  }
  if(D>0){
    std::swap(A,B);
    std::swap(C,D);
    std::swap(abs,bas);
  }
  //printf("C=%d, D=%d\n",C,D);
  assert(C>0&&D<=0);
  C-=wild;
  //printf("C=%d, D=%d\n",C,D);
  std::sort(bas.begin(),bas.end());
  while(C>0){
    if(bas.empty()) return false;
    int use=std::min(C+1,bas.back());
    bas.pop_back();
    C-=use-1;
    D+=use;
  }
  return D<=0;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    printf("%s\n",solve()?"YES":"NO");
  }
}