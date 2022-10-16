#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>

std::vector<int> edges[200005];
int anc[200005][18];
int depth[200005];
int N,Q;


void dfs_la(int x){
  for(int k=1;k<18;k++){
    anc[x][k]=anc[anc[x][k-1]][k-1];
  }
  for(int y:edges[x]){
    if(y==anc[x][0]) continue;
    anc[y][0]=x;
    depth[y]=depth[x]+1;
    dfs_la(y);
  }
}

int la(int x,int d){
  for(int k=0;k<18;k++){
    if(d&(1<<k)){
      x=anc[x][k];
    }
  }
  return x;
}

int lca(int x,int y){
  if(depth[x]<depth[y]) std::swap(x,y);
  x=la(x,depth[x]-depth[y]);
  if(x==y) return x;
  for(int k=18-1;k>=0;k--){
    if(anc[x][k]!=anc[y][k]){
      x=anc[x][k];
      y=anc[y][k];
    }
  }
  return anc[x][0];
}

int dist(int x,int y){
  int z=lca(x,y);
  return depth[x]+depth[y]-2*depth[z];
}

int triple(int x,int y,int z){
  return lca(x,y)^lca(x,z)^lca(y,z);
}

struct SignedPath{
  bool sign;
  int x,y;
};

SignedPath intersect(int v,int w,int x,int y){
  int s=triple(v,w,x);
  int t=triple(v,w,y);
  if(s!=t){
    return SignedPath{true,s,t};
  }else{
    return SignedPath{false,s,triple(v,x,y)};
  }
}

void update_diam(int& a,int& b,int c){
  int dab=dist(a,b);
  int dac=dist(a,c);
  int dbc=dist(b,c);
  if(dab>=dac&&dab>=dbc) return;
  if(dac>dbc){
    b=c;
  }else{
    a=c;
  }
}

SignedPath merge(SignedPath a,SignedPath b){
  if(a.sign&&b.sign){
    return intersect(a.x,a.y,b.x,b.y);
  }else if(!a.sign&&!b.sign){
    update_diam(b.x,b.y,a.x);
    update_diam(b.x,b.y,a.y);
    return b;
  }else{
    if(b.sign) std::swap(a,b);
    int s=triple(a.x,a.y,b.x);
    int t=triple(a.x,a.y,b.y);
    if(s==t) update_diam(b.x,b.y,s);
    return b;
  }
}

struct Node{
  SignedPath p;
  bool active;
  Node():active(false){
  }
  Node(SignedPath p):p(p),active(true){
  }
}st[400005];

void dump(Node x){
  if(!x.active){
    printf("Empty");
  }else{
    printf("%c(%d,%d)",x.p.sign?'+':'-',x.p.x,x.p.y);
  }
}

Node merge(Node a,Node b){
  Node res;
  res.active=a.active||b.active;
  if(a.active&&b.active){
    res.p=merge(a.p,b.p);
  }else if(a.active){
    res.p=a.p;
  }else if(b.active){
    res.p=b.p;
  }
  //dump(a),printf(" merge "),dump(b),printf(" = "),dump(res),printf("\n");
  return res;
}

void pull(int i){
  st[i]=merge(st[i<<1],st[i<<1|1]);
}

void update(int i,Node x){
  //printf("Update %d to ",i),dump(x),printf("\n");
  for(st[i+=Q]=x;i>1;i>>=1){
    pull(i>>1);
  }
}

Node query(){
  Node lsum,rsum;
  for(int a=0+Q,b=Q+Q;a<b;a>>=1,b>>=1){
    if(a&1) lsum=merge(lsum,st[a++]);
    if(b&1) rsum=merge(st[--b],rsum);
  }
  return merge(lsum,rsum);
}
      

int main(){
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N-1;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    X--,Y--;
    edges[X].push_back(Y);
    edges[Y].push_back(X);
  }
  dfs_la(0);
  std::map<std::pair<int,int>,std::vector<int>> map;
  for(int i=0;i<Q;i++){
    int T;
    scanf("%d",&T);
    if(T==1){
      int U,V;
      scanf("%d %d",&U,&V);
      U--,V--;
      if(U>V) std::swap(U,V);
      map[{U,V}].push_back(i);
      update(i,Node(SignedPath{true,U,V}));
    }else if(T==2){
      int U,V;
      scanf("%d %d",&U,&V);
      U--,V--;
      if(U>V) std::swap(U,V);
      auto& vec=map[{U,V}];
      assert(vec.size()>0);
      update(vec.back(),Node());
      vec.pop_back();
    }else if(T==3){
      int D;
      scanf("%d",&D);
      Node x=query();
      //printf("Query="),dump(x),printf("\n");;
      assert(x.active);
      if(x.p.sign){
	printf("Yes\n");
      }else{
	int diam=dist(x.p.x,x.p.y);
	//fprintf(stderr,"diam:%d\n",diam);
	if(D*2>=diam){
	  printf("Yes\n");
	}else{
	  printf("No\n");
	}
      }
    }
  }
}