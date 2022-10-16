#include <iostream>
#include <algorithm>

int N;
struct cdomino{
  int x;
  int h;
  int id;
  bool operator<(struct cdomino other){
    return x<other.x;
  }
}dominos[100000];
int xs[100000];
int st[400000];
int max[100000];

void set(int w,int L,int R,int a,int v){
  if((a<L)||(a>R)){
    return;
  }
  if(L==R){
    st[w]=v;
  }else{
    set(w*2+1,L,(L+R)/2,a,v);
    set(w*2+2,(L+R)/2+1,R,a,v);
    st[w]=std::max(st[w*2+1],st[w*2+2]);
  }
}

void set(int a,int v){
  set(0,0,N-1,a,v);
}

int query(int w,int L,int R,int a,int b){
  //std::cerr<<"query("<<w<<","<<L<<","<<R<<","<<a<<","<<b<<")"<<std::endl;
  if((a>R)||(b<L)){
    return 0;
  }
  if((a<=L)&&(b>=R)){
    return st[w];
  }else{
    return std::max(query(w*2+1,L,(L+R)/2,a,b),
		    query(w*2+2,(L+R)/2+1,R,a,b));
  }
}

int query(int a,int b){
  return query(0,0,N-1,a,b);
}

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>dominos[i].x>>dominos[i].h;
    dominos[i].id=i;
  }
  std::sort(dominos,dominos+N);
  for(int i=0;i<N;i++){
    xs[i]=dominos[i].x;
  }
  for(int i=N-1;i>=0;i--){
    //std::cerr<<"i="<<i<<": "<<xs[i]<<","<<dominos[i].h<<std::endl;
    int* p=std::lower_bound(xs+i,xs+N,xs[i]+dominos[i].h);
    if(p!=xs){
      int farthest=*(p-1);
      int q=query(i+1,p-xs-1);
      //std::cerr<<"i="<<i<<",f="<<farthest<<",q="<<q<<std::endl;
      set(i,std::max(q,i));
      continue;
    }
    set(i,i);
  }
  for(int i=0;i<N;i++){
    //std::cerr<<i<<": "<<dominos[i].id<<":"<<query(0,0,N-1,i,i)<<std::endl;
    max[dominos[i].id]=query(0,0,N-1,i,i)-i+1;
  }
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<max[i];
  }
  std::cout<<std::endl;
  return 0;
}