#include <cstdio>
#include <vector>
#include <cmath>

std::vector<std::pair<int,int> > nodes;
int N;
int sgn[200000];
int xs[200000];
int ys[200000];

int new_node(int a,int b){
  int id=nodes.size();
  nodes.emplace_back(a,b);
  xs[id]=xs[a]-xs[b];
  ys[id]=ys[a]-ys[b];
  return id;
}

std::vector<int> vs;

void insert(int i){
  for(int k=0;k<vs.size();k++){
    int j=vs[k];
    if(std::hypot(xs[j]-xs[i],ys[j]-ys[i])<=1e6){
      vs.erase(vs.begin()+k);
      insert(new_node(i,j));
      return;
    }
  }
  vs.push_back(i);
}

void recover(int i,int s){
  sgn[i]=s;
  if(i>=N){
    recover(nodes[i].first,s);
    recover(nodes[i].second,-s);
  }
}

int main(){
  scanf("%d",&N);
  nodes.resize(N);

  for(int i=0;i<N;i++){
    scanf("%d %d",&xs[i],&ys[i]);
    insert(i);
  }
  for(int mask=0;mask<(1<<vs.size());mask++){
    int X=0,Y=0;
    for(int i=0;i<vs.size();i++){
      if(mask&(1<<i)){
	X+=xs[vs[i]];
	Y+=ys[vs[i]];
      }else{
	X-=xs[vs[i]];
	Y-=ys[vs[i]];
      }
    }
    if(std::hypot(X,Y)<=15e5){
      for(int i=0;i<vs.size();i++){
	if(mask&(1<<i)){
	  recover(vs[i],1);
	}else{
	  recover(vs[i],-1);
	}
      }
      break;
    }
  }
  for(int i=0;i<N;i++){
    printf("%d\n",sgn[i]);
  }
  return 0;
}