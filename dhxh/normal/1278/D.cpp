#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

struct ex {
	int l, r;
} a[maxn];
int c[maxn];
int n;

bool cmp(int x, int y){
	if(a[x].l != a[y].l){
		return a[x].l < a[y].l;
	}
	return a[x].r < a[y].r;
}
int fa[maxn];
int son[maxn];

int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

bool check(){
	int i, j;
	int cnt = 0; 
	priority_queue <pair<int, int> > A;
	
	for(i=1;i<=n;i++){
		fa[i] = i;
	}
	
	for(i=1;i<=n;i++){
		priority_queue <pair<int, int> > B;
		
		while(A.size() and -A.top().first < a[c[i]].l){
			A.pop();
		}
		
		while(A.size() and -A.top().first < a[c[i]].r){
			int x = A.top().second;
			if(find(x) == find(c[i])) return false;
			cnt++;
			fa[find(x)] = find(c[i]);
			B.push(A.top());
			A.pop();
		}
		
		while(B.size()){
			A.push(B.top());
			B.pop();
		}
		A.push(make_pair(-a[c[i]].r, c[i]));
	}
	
	return cnt == n - 1;
}

int main(){
	int i, j;
	
	scanf("%d", &n);
	for(i=1;i<=n;i++){
		scanf("%d%d", &a[i].l, &a[i].r);
		c[i] = i;
	}
	
	sort(c + 1, c + n + 1, cmp);
	
	if(!check()){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
	
	return 0;
}
/*
4
1 4
2 5
3 6
7 8
*/