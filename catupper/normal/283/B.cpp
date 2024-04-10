#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<functional>
#include<algorithm>

using namespace std;
typedef pair<long long, long long> P;
long long dist[650100];
vector<P> edge[650100];
long long n, p;
long long ans[210000];
#define INF (1LL << 60)



void dijkstra(long long s){
    priority_queue<P, vector<P>, greater<P> > pq;
    fill(dist, dist + 650100, INF);
    dist[s] = 0;
    pq.push(P(0, s));
    while(!pq.empty()){
	P tmp = pq.top();pq.pop();
	long long d = tmp.first, from = tmp.second;
	if(dist[from] < d)continue;
	for(long long i = 0;i < edge[from].size();i++){
	    long long to = edge[from][i].first, cost = edge[from][i].second;
	    if(dist[to] > d + cost){
		dist[to] = d + cost;
		pq.push(P(dist[to], to));
	    }
	}
    }
}

int main(){
    cin >> n;
    for(long long i = 2;i <= n;i++){//plus , minus + 21000,65000
	cin >> p;
	if(i + p > n){
	    edge[650000].push_back(P(i, p));
	}
	else{
	    edge[i + p + 210000].push_back(P(i, p));
	}
	if(i - p <= 0){
	    edge[650010].push_back(P(i + 210000, p));
	}
	else{
	    edge[i - p].push_back(P(i + 210000, p));
	}
	edge[i + 210000].push_back(P(420000 + i - 1, i - 1));
    }
    dijkstra(650000);
    for(long long i = 1;i < n;i++){
	ans[i] = dist[420000 + i];
    }
    dijkstra(650010);
    for(long long i = 1;i < n;i++){
	long long tmp = min(ans[i], dist[420000 + i]);
	cout << (tmp == INF ? -1: tmp) << endl;
    }
    return 0;
}