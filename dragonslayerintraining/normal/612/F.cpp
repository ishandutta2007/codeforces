#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

const int INF=1e9+7;

int S,N;

int as[2005];

std::map<int,std::vector<int> > layers;

std::vector<std::pair<int,int> > adj[4005];

int dist[4005];
int prev[4005];

int rdist(int i,int j){
  if(j>=i){
    return j-i;
  }else{
    return j-i+N;
  }
}

int ldist(int i,int j){
  return rdist(j,i);
}

int udist(int i,int j){
  return std::min(ldist(i,j),rdist(i,j));
}

int SRC(){ return N*2; }
int SNK(){ return N*2+1; }
int BEGIN(int i){ return i; }
int END(int i){ return N+i; }

std::vector<int> ans;

std::vector<int> rpath(int s,int t,int v){
  std::vector<int> path;
  if(s<=t){
    for(int i=s;i<=t;i++){
      if(as[i]==v){
	path.push_back(i);
      }
    }
  }else{
    for(int i=s;i<N;i++){
      if(as[i]==v){
	path.push_back(i);
      }
    }
    for(int i=0;i<=t;i++){
      if(as[i]==v){
	path.push_back(i);
      }
    }
  }
  return path;
}

//x is end
void recover(int x){
  if(x==SRC()) return;
  recover(prev[prev[x]]);
  int end=x-N;
  int begin=prev[x];
  std::vector<int> rightward=rpath(begin,end,as[begin]),leftward=rpath(end,begin,as[begin]);
  std::reverse(leftward.begin(),leftward.end());
  //printf("%d: %d->%d L%d R%d\n",as[begin],begin,end,leftward.size(),rightward.size());
  if(leftward.size()>rightward.size()){
    ans.insert(ans.end(),leftward.begin(),leftward.end());
  }else{
    ans.insert(ans.end(),rightward.begin(),rightward.end());
  }
}

int main(){
  scanf("%d %d",&N,&S);
  S--;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    layers[as[i]].push_back(i);
  }
  for(int i:layers.begin()->second){
    adj[SRC()].push_back({BEGIN(i),udist(S,i)});
  }
  for(auto it=layers.begin();it!=layers.end();it++){
    auto& curr_layer=it->second;
    for(int i=0;i<curr_layer.size();i++){
      int a=curr_layer[i],b=curr_layer[(i+1)%curr_layer.size()];
      adj[BEGIN(a)].push_back({BEGIN(b),rdist(a,b)});
      adj[BEGIN(b)].push_back({BEGIN(a),ldist(b,a)});
      
      adj[BEGIN(a)].push_back({END(b),ldist(a,b)});
      adj[BEGIN(b)].push_back({END(a),rdist(b,a)});
    }

    auto next=it;
    ++next;
    if(next!=layers.end()){
      auto& next_layer=next->second;
      for(int i:curr_layer){
	for(int j:next_layer){
	  adj[END(i)].push_back({BEGIN(j),udist(i,j)});
	}
      }
    }
  }
  for(int i:layers.rbegin()->second){
    adj[END(i)].push_back({SNK(),0});
  }
  std::fill(dist,dist+N*2+2,INF);
  std::priority_queue<std::tuple<int,int,int> > q;
  q.push({0,SRC(),-1});
  while(!q.empty()){
    int d=-std::get<0>(q.top());
    int x=std::get<1>(q.top());
    int p=std::get<2>(q.top());
    q.pop();
    if(d>=dist[x]) continue;
    dist[x]=d;
    prev[x]=p;
    for(auto e:adj[x]){
      int y=e.first,len=e.second;
      q.push({-(d+len),y,x});
    }
  }
  /*
  for(int i=0;i<N;i++){
    printf("%d: %d %d\n",i,dist[BEGIN(i)],dist[END(i)]);
  }
  */
  printf("%d\n",dist[SNK()]);
  recover(prev[SNK()]);
  for(int x:ans){
    //printf("%d\n",x);
    
    if(rdist(S,x)<ldist(S,x)){
      printf("+%d\n",rdist(S,x));
    }else{
      printf("-%d\n",ldist(S,x));
    }
    S=x;
    
  }
}