#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <deque>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF 1001001001
#define MOD 1000000007

int N,M,W;
ll C[5001],K[5001],P[5001];
vector<pair<ll,ll>>stores[5001];
vector<int>adj[5001];
int dis[5001];
bool visited[5001];
multiset<pair<ll,ll>>mst; //cost, num
ll tot,cnt;

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>N>>M;
  for (int i=0;i<M;i++){
    int X,Y;
    cin>>X>>Y;
    adj[X].push_back(Y);
    adj[Y].push_back(X);
  }
  cin>>W;
  for (int i=0;i<W;i++){
    cin>>C[i]>>K[i]>>P[i];
    stores[C[i]].push_back({P[i],K[i]});
  }
  int Q;
  cin>>Q;
  queue<int>q;
  while (Q--){
    int G,R,A;
    int ans=INF;
    cin>>G>>R>>A;
    for (int i=1;i<=N;i++){
      dis[i]=INF;
      visited[i]=false;
    }
    tot=0; cnt=0;
    mst.clear();
    q.push(G);
    dis[G]=0;
    visited[G]=true;
    while (!q.empty()){
      int X=q.front();
      if (ans==INF){
	for (int i=0;i<(int)stores[X].size();i++){
	  cnt+=stores[X][i].second;
	  tot+=stores[X][i].second*stores[X][i].first;
	  mst.insert(stores[X][i]);
	  if (cnt<=R)
	    continue;
	  else{	    
	    while (cnt>R){
	      ll canDel=cnt-R;
	      if (mst.rbegin()->second<=canDel){
		cnt-=mst.rbegin()->second;
		tot-=mst.rbegin()->second*mst.rbegin()->first;
		mst.erase(mst.find(*mst.rbegin()));
	      }
	      else{
		cnt-=canDel;
		tot-=canDel*mst.rbegin()->first;
		int a=mst.rbegin()->first;
		int b=mst.rbegin()->second-canDel;
		mst.erase(mst.find(*mst.rbegin()));
		mst.insert({a,b});
	      }
	    }
	  }
	}
	if (cnt==R && tot<=A)
	  ans=dis[X];
      }
      q.pop();
      for (int Y:adj[X]){
	if (!visited[Y]){
	  visited[Y]=true;
	  dis[Y]=dis[X]+1;
	  q.push(Y);
	}
      }
    }
    if (ans==INF)
      cout<<-1<<endl;
    else
      cout<<ans<<endl;
  }
  return 0;
}