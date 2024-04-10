#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

map <pii, int> E;
vector <int> T[101010], V[101010];
int n;

void add(int u, int v, int i)
{	
	if(E.find(pii(u, v)) != E.end()){
		int x = E[pii(u, v)];
		T[x].push_back(i);
		T[i].push_back(x);
		E.erase(pii(u, v));
	}
	else E[pii(u, v)] = i;
}

void print(int p, int r)
{
	if(p == 1 && r) printf("\n");
	else{
		printf("%d ", p);
		if(V[p][0] != r) print(V[p][0], p);
		else print(V[p][1], p);
	}
}

void dfs(int p, int r)
{
	for(int &t: T[p]){
		if(t != r) dfs(t, p);
	}
	
	printf("%d ", p);
}

int main()
{
	int t, i, a, b, c;
	
	scanf("%d", &t);
	
	for(; t --; ){
		scanf("%d", &n);
		
		for(i = 1; i < n - 1; i ++){
			scanf("%d%d%d", &a, &b, &c);
			if(a > b) swap(a, b);
			if(a > c) swap(a, c);
			if(b > c) swap(b, c);
			add(a, b, i); add(a, c, i); add(b, c, i);
		}
		
		for(auto t: E){
			pii p = t.first;
			V[p.first].push_back(p.second);
			V[p.second].push_back(p.first);
		}
		
		print(1, 0);
		dfs(1, 0);
		
		printf("\n");
		
		E.clear();
		
		for(i = 1; i <= n; i ++){
			T[i].clear(); V[i].clear();
		}
	}
	
	return 0;
}