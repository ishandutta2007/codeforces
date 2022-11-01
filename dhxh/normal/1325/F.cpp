#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

vector <int> e[maxn];
vector <int> ans;
stack <int> s;
bool vis[maxn];
int dep[maxn];
int N;
bool v[maxn];

int dfs(int x, int fr){
	vis[x] = true;
	s.push(x);
	
	for(auto y : e[x]){
		if(y == fr) continue;
		if(!vis[y]){
			dep[y] = dep[x] + 1;
			dfs(y, x);
			dep[y] = 0;
		}else if(dep[y]){
			if(dep[x] - dep[y] + 1 >= N){
				printf("2\n");
				printf("%d\n", dep[x] - dep[y] + 1);
				while(s.top() != y){
					printf("%d ", s.top());
					s.pop();
				}
				printf("%d\n", s.top());
				exit(0);
			}
		}
	}
	
	//if(e[x].size() < N){
		if(!v[x]){
			for(auto y : e[x]){
				v[y] = true;
			}
			ans.push_back(x);
		}
	//}
	
	s.pop();
	return 0;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	
	n = read();
	m = read();
	
	N = sqrt(n);
	while(N * N < n) N++;
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	for(i=1;i<=n;i++){
		if(!vis[i]){
			dep[i] = 1;
			dfs(i, -1);
			dep[i] = 0;
		}
	}
	
	printf("1\n");
	for(i=1;i<=n;i++){
		if(v[i]) continue;
		N--;
		printf("%d ", i);
		if(!N) break;
	}
	printf("\n");
	
	return 0;
}