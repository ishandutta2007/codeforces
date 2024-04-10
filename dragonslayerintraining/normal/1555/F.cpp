#include <cstdio>
#include <vector>
#include <functional>
#include <utility>
#include <numeric>
#include <algorithm>

int N,Q;

int us[500005];
int vs[500005];
int ws[500005];
bool ans[500005];

int uf[300005];

std::vector<std::pair<int,int> > adj[300005];

bool vis[300005];
int size[300005];
int weight[300005];

void dfs_init(int x){
  vis[x]=true;
  size[x]=1;
  for(auto e:adj[x]){
    int y=e.first,w=e.second;
    if(vis[y]) continue;
    adj[y].erase(std::find(adj[y].begin(),adj[y].end(),std::make_pair(x,w)));
    weight[y]=weight[x]^w;
    dfs_init(y);
    size[x]+=size[y];
  }
  for(auto& e:adj[x]){
    if(size[e.first]>size[adj[x][0].first]){
      std::swap(e,adj[x][0]);
    }
  }
}

int pre[300005];
int post[300005];
int euler=0;

int head[300005];
int par[300005];

void dfs_hld(int x){
  //printf("who[%d]=%d\n",euler,x+1);
  pre[x]=euler++;
  for(auto e:adj[x]){
    int y=e.first;
    par[y]=x;
    head[y]=(y==adj[x][0].first)?head[x]:y;
    dfs_hld(e.first);
  }
  post[x]=euler;
}

std::vector<std::pair<int,int> > hld(int a,int b){
  std::vector<std::pair<int,int> > segs;
  if(pre[a]>pre[b]) std::swap(a,b);
  while(pre[head[a]]<pre[head[b]]){
    segs.push_back({pre[head[b]],pre[b]});
    b=par[head[b]];
  }
  while(pre[head[b]]<pre[head[a]]){
    segs.push_back({pre[head[a]],pre[a]});
    a=par[head[a]];
  }
  if(pre[a]>pre[b]) std::swap(a,b);
  if(a!=b){
    segs.push_back({pre[a]+1,pre[b]});
  }
  return segs;
}

long long ft_m[300005];
long long ft_b[300005];

void ft_update(long long* ft,int i,int v){
  for(;i<=N;i+=(i&-i)){
    ft[i]+=v;
  }
}

long long ft_query(long long* ft,int i){
  long long ans=0;
  for(;i>0;i-=(i&-i)){
    ans+=ft[i];
  }
  return ans;
}

//add v to [a,inf)
void lin_update(int a,int v){
  ft_update(ft_m,a,v);
  ft_update(ft_b,a,-v*(a-1LL));
}

//query sum of [0,a]
long long lin_query(int a){
  return ft_query(ft_m,a)*a+ft_query(ft_b,a);
}

int find(int a){
  return (a==uf[a])?a:(uf[a]=find(uf[a]));
}

int main(){
  scanf("%d %d",&N,&Q);
  for(int i=0;i<Q;i++){
    scanf("%d %d %d",&us[i],&vs[i],&ws[i]);
    us[i]--,vs[i]--;
  }
  std::iota(uf,uf+N,0);
  for(int i=0;i<Q;i++){
    if(find(us[i])!=find(vs[i])){
      uf[find(us[i])]=find(vs[i]);
      ans[i]=true;
    }
  }
  for(int i=0;i<Q;i++){
    if(ans[i]){
      adj[us[i]].push_back({vs[i],ws[i]});
      adj[vs[i]].push_back({us[i],ws[i]});
    }
  }
  for(int i=0;i<N;i++){
    if(vis[i]) continue;
    weight[i]=0;
    dfs_init(i);
    head[i]=i;
    par[i]=-1;
    dfs_hld(i);
  }
  /*
  for(int i=0;i<N;i++){
    printf("head[%d]=%d\n",i+1,head[i]+1);
  }
  */
  for(int i=0;i<Q;i++){
    if(ans[i]) continue;
    if((weight[us[i]]^weight[vs[i]]^ws[i])!=1){
      //NO
      continue;
    }
    long long res=0;
    //printf("HLD:%d..%d:",us[i]+1,vs[i]+1);
    for(auto seg:hld(us[i],vs[i])){
      //printf(" [%d,%d]",seg.first,seg.second);
      res+=lin_query(seg.second)-lin_query(seg.first-1);
    }
    //printf("\n");
    //printf("%lld\n",res);
    if(res) continue;
    for(auto seg:hld(us[i],vs[i])){
      lin_update(seg.first,1);
      lin_update(seg.second+1,-1);
    }
    ans[i]=true;
  }
  for(int i=0;i<Q;i++){
    if(ans[i]){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
}