#include <cstdio>
#include <vector>

int as[300000];
int ps[300000];

std::vector<int> left,right,cnt;

int new_node(int l,int r){
  int index=left.size();
  left.push_back(l);
  right.push_back(r);
  cnt.push_back(0);
  return index;
}

int get_left(int node){
  if(left[node]<0){
    int add=new_node(-1,-1);
    left[node]=add;
  }
  return left[node];
}

int get_right(int node){
  if(right[node]<0){
    int add=new_node(-1,-1);
    right[node]=add;
  }
  return right[node];
}


void insert(int node,int X){
  cnt[node]++;
  for(int k=29;k>=0;k--){
    if((X>>k)&1){
      node=get_right(node);
    }else{
      node=get_left(node);
    }
    cnt[node]++;
  }
}

void erase(int node,int X){
  cnt[node]--;
  for(int k=29;k>=0;k--){
    if((X>>k)&1){
      node=get_right(node);
    }else{
      node=get_left(node);
    }
    cnt[node]--;
  }
}

int argmin_xor(int node,int X){
  int ans=0;
  for(int k=29;k>=0;k--){
    int b=((X>>k)&1);
    if((cnt[get_left(node)]==0)||(b&&cnt[get_right(node)])){
      node=get_right(node);
      ans=(ans<<1)|1;
    }else{
      node=get_left(node);
      ans=(ans<<1);
    }
  }
  return ans;
}

/*
void dump(int node,int val){
  if(cnt[node]){
    printf("%d: %d\n",node,val);
    if(cnt[get_left(node)]) dump(get_left(node),val<<1);
    if(cnt[get_right(node)]) dump(get_right(node),(val<<1)|1);
  }
}
*/

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  int root=new_node(-1,-1);
  for(int i=0;i<N;i++){
    scanf("%d",&ps[i]);
    insert(root,ps[i]);
  }
  //dump(root,0);
  for(int i=0;i<N;i++){
    int min=argmin_xor(root,as[i]);
    erase(root,min);
    if(i>0) printf(" ");
    printf("%d",as[i]^min);
  }
  printf("\n");
  return 0;
}