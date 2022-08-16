#include <iostream>
#include <queue>
#include <vector>


using namespace std;
vector<vector<pair<int, pair<int, int> > > > graph;
struct cand{
  int index, to, weight;
  long long prio;
  cand(int nindex, int nto,int nweight,long long nprio){
    index= nindex;
    to = nto;
    weight = nweight;
    prio = nprio;
  }

  bool operator<(const cand& other)const{
    if(other.prio == prio){
      return other.weight < weight;
    }
    return other.prio < prio;

  }
};
int N, M;
void algorithm(int start){
  vector<bool> finalized(N, false);
  vector<long long> opt(N, 0x7FFFFFFFFFFFFFFF);
  vector<int> edges;
  priority_queue<cand> pq;
  long long sum = 0;
  pq.emplace(-1, start, 0, 0);

  while(!pq.empty()){
    cand cur = pq.top();
    pq.pop();
    if(finalized[cur.to])continue;
    finalized[cur.to] = true;
    sum+=cur.weight;
    if(cur.index!=-1)
    edges.push_back(cur.index);

    for(auto& e:graph[cur.to]){
      long long newW =opt[cur.to] +  e.second.first;
      if(newW <= opt[e.first]){
          opt[e.first] = newW;
          pq.emplace(e.second.second, e.first, e.second.first, newW);
      }
    }
  }

  cout << sum << "\n";

  for(int e:edges){
    cout << e <<" ";
  }
}


int main(){
  cin >> N >> M;
  /// to, weight, index
  graph = vector<vector<pair<int, pair<int, int> > > >(N);
  int a, b, weight;
  int counter = 0;
  for(int i=0;i<M;++i){
    cin >> a >> b >> weight;
    a-=1;
    b-=1;
    graph[a].push_back(pair<int, pair<int, int> >(b, pair<int, int> (weight, ++counter)));
    graph[b].push_back(pair<int, pair<int, int> >(a, pair<int, int> (weight, counter)));
  }

  int start;
  cin >> start;
  start-=1;
  algorithm(start);
  return 0;
}