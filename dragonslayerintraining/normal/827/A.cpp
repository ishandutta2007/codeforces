#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

char T[1000005];
char *Ts[100005];
int Tlen[100005];

struct event{
  int start;
  int ref;
  event(int start,int ref):start(start),ref(ref){
  }
  bool operator<(struct event other)const{
    if(start!=other.start){
      return start>other.start;
    }
    return ref<other.ref;
  }
};

std::priority_queue<struct event> active;

char str[2000005];


int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int K;
    scanf("%s %d",T,&K);
    Tlen[i]=strlen(T);
    Ts[i]=new char[Tlen[i]+1];
    strcpy(Ts[i],T);
    Ts[i][Tlen[i]]='\0';
    for(int j=0;j<K;j++){
      int X;
      scanf("%d",&X);
      X--;
      active.emplace(X,i);
      //fprintf(stderr,"String %s(%d) at location %d\n",Ts[i],Tlen[i],X);
    }
  }
  for(int i=0;;i++){
    while((!active.empty())&&
	  (i-active.top().start>=Tlen[active.top().ref])){
      active.pop();
    }
    if(active.empty()){
      str[i]='\0';
      break;
    }
    if(i<active.top().start){
      str[i]='a';
    }else{
      str[i]=Ts[active.top().ref][i-active.top().start];
    }
  }
  printf("%s\n",str);
  return 0;
}