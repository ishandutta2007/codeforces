#include <cstdio>
#include <vector>

int as[100005];
std::vector<std::vector<std::pair<int,int> > > queries;

struct Trie{
  int chd[2];
  int upd[2];
}trie[100005*30];
int trie_size;

int new_node(){
  trie[trie_size].chd[0]=0;
  trie[trie_size].chd[1]=0;
  trie[trie_size].upd[0]=0;
  trie[trie_size].upd[1]=0;
  return trie_size++;
}

int get_child(int node,int d){
  if(!trie[node].chd[d]){
    return trie[node].chd[d]=new_node();
  }
  return trie[node].chd[d];
}

int count_child(int node,int d,int t){
  if(!trie[node].chd[d]) return 0;
  int child=trie[node].chd[d];
  if(trie[child].upd[1]>=t){
    return 2;
  }else if(trie[child].upd[0]>=t){
    return 1;
  }else{
    return 0;
  }
}

void update(int val,int t){
  int node=0;
  for(int k=30-1;k>=0;k--){
    node=get_child(node,(val>>k)&1);
    trie[node].upd[1]=trie[node].upd[0];
    trie[node].upd[0]=t;
  }
}

int query(int t){
  //only consider time >=t
  std::vector<int> curr({0});
  int ans=0;
  for(int k=30-1;k>=0;k--){
    int zero_cnt=0;
    for(int x:curr){
      zero_cnt+=count_child(x,0,t);
    }
    std::vector<int> next;
    if(zero_cnt>=2){
      for(int x:curr){
	if(count_child(x,0,t)){
	  next.push_back(trie[x].chd[0]);
	}
      }
    }else if(zero_cnt==1){
      for(int x:curr){
	if(count_child(x,0,t)){
	  next.push_back(trie[x].chd[0]);
	}
	if(count_child(x,1,t)){
	  next.push_back(trie[x].chd[1]);
	}
      }
      ans|=(1<<k);
    }else{
      for(int x:curr){
	if(count_child(x,1,t)){
	  next.push_back(trie[x].chd[1]);
	}
      }
      ans|=(1<<k);
    }
    curr.swap(next);
  }
  return ans;
}

int ans[100005];

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  int Q;
  scanf("%d",&Q);
  queries.clear();
  queries.resize(N+1);
  for(int i=0;i<Q;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    queries[R].push_back({L,i});
  }
  trie_size=0;
  new_node();
  
  for(int r=1;r<=N;r++){
    update(as[r],r);
    for(auto q:queries[r]){
      int l=q.first,i=q.second;
      ans[i]=query(l);
    }
  }
  for(int i=0;i<Q;i++){
    printf("%d\n",ans[i]);
  }
}

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
}