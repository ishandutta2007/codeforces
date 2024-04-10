#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define oo 1000000010
const int N = 200010;
const int M = 1000010;
int n , m ;
 
bool notprime[M];
 
vector< int >  p[M];
 
vector< int > g[M];
vector< int > arr , arr2;
int cur[M];
 
int cost[M] , best[M];
 
int ans = oo;
 
queue < int > q;
 
void BFS1(){
	for(int i = 0 ;i < (int)arr.size();i++){
		cost[arr[i]] = -1;
		if(cur[arr[i]] > 0){
			q.push(arr[i]);
			best[arr[i]] = arr[i];
			cost[arr[i]] = 0;
		}
	}
	int node;
	while(!q.empty()){
		node = q.front();
		q.pop();
		for(int i = 0 ;i < (int)g[node].size();i++){
			if(cost[g[node][i]] != -1) continue;
			cost[g[node][i]] = cost[node] + 1;
			best[g[node][i]] = best[node];
			q.push(g[node][i]);
		}
	}
	for(int i = 0 ;i < (int)arr.size();i++){
		if(cost[arr[i]] == -1) continue;
		node = arr[i];
		for(int j = 0 ;j < (int)g[node].size();j++){
			if(cost[g[node][j]] != -1 && best[g[node][j]] != best[node])
				ans = min(ans , cost[node] + cost[g[node][j]] + 3);
		}
	}
}
 
void BFS(int node){
	for(int i = 0 ;i < (int)arr2.size();i++){
		cost[arr2[i]] = -1;
	}
	q.push(node);
	cost[node] = 0;
	best[node] = -1;
	while(!q.empty()){
		node = q.front();
		q.pop();
		for(int i = 0 ;i < (int)g[node].size();i++){
			if(cost[g[node][i]] == -1){
				cost[g[node][i]] = cost[node] + 1;
				best[g[node][i]] = node;
				q.push(g[node][i]);
				continue;
			}
			if(best[node] == g[node][i]) continue;
			ans = min(ans , cost[node] + cost[g[node][i]] + 1);
		}
	}
}
 
int main(){
	notprime[1] = true;
	int a , b;
	for(int i = 2;i < M;i++){
		if(notprime[i]) continue;
		arr.push_back(i);
		for(int j = i ;j < M;j += i){
			notprime[j] = true;
			a = 0 , b = j;
			while(b % i == 0) b /= i , a++;
			if(a & 1) p[j].push_back(i);
		}
	}
	scanf("%d",&n);
	for(int i = 0 ;i < n;i++){
		scanf("%d",&a);
		if((int)p[a].size() == 0){
			cout << 1 << endl;
			return 0;
		}
		else if((int)p[a].size() == 1){
			cur[p[a][0]]++;
		}
		else {
			g[p[a][0]].push_back(p[a][1]);
			g[p[a][1]].push_back(p[a][0]);	
		}
	}
	for(int i = 0 ;i < (int)arr.size();i++){
		if(cur[arr[i]] > 1){
			puts("2");
			return 0;
		}
		a = arr[i];
		sort(g[a].begin(),g[a].end());
		b = (int)g[a].size();
		g[a].resize(unique(g[a].begin(),g[a].end()) - g[a].begin());
		if((int)g[a].size() != b){
			puts("2");
			return 0;
		}
		if(b > 0){
			arr2.push_back(arr[i]);
		}
	}
	BFS1();
	for(int i = 0 ;i < (int)arr2.size() && arr2[i] <= 1000;i++) BFS(arr2[i]);
	if(ans == oo) ans = -1;
	cout << ans << endl;
	return 0;
}