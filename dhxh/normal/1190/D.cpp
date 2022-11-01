#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

struct point {
	int x, y;
};

point p[maxn];

bool cmp(point x, point y){
	if(x.y != y.y)return x.y > y.y;
	return x.x < y.x;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

struct node {
	int x;
	int fix;
	int c[2];
	int w;
	int sum;
};

struct node tree[2 * maxn];

int tc = 0;
int root = 0;

int update(int pos){
	tree[pos].sum = tree[tree[pos].c[0]].sum + tree[tree[pos].c[1]].sum + tree[pos].w;
	return 0;
}

int rotate(int &pos, int d){
	int c = tree[pos].c[d];
	
	tree[pos].c[d] = tree[c].c[!d];
	tree[c].c[!d] = pos;
	
	update(pos);
	update(c);
	
	pos = c; 
	
	return 0;
}

int insert(int &pos, int x){
	if(!pos){
		pos = ++tc;
		tree[pos].x = x;
		tree[pos].w = tree[pos].sum = 1;
		tree[pos].fix = rand();
	}else{
		if(tree[pos].x == x){
			tree[pos].w = 1;
		}else{
			int d = x > tree[pos].x;
			insert(tree[pos].c[d], x);
			update(pos);
			if(tree[tree[pos].c[d]].fix > tree[pos].fix){
				rotate(pos, d);
			}
		}
		update(pos);
	}
	
	return 0;
}

int remove(int &pos, int x){
	if(tree[pos].x != x){
		int d = tree[pos].x < x;
		remove(tree[pos].c[d], x);
		update(pos);
	}else{
		if(tree[pos].w > 1){
			tree[pos].w--;
			update(pos);
		}else{
			if(!tree[pos].c[0]){
				pos = tree[pos].c[1];
			}else if(!tree[pos].c[1]){
				pos = tree[pos].c[0];
			}else{
				int d = tree[tree[pos].c[0]].fix < tree[tree[pos].c[1]].fix;
				rotate(pos, d);
				remove(tree[pos].c[!d], x);
				update(pos);
			}
		}
	}
	
	return pos;
}

int query_rank(int pos, int x){
	if(!pos)return 0;
	if(tree[pos].x == x){
		return 1 + tree[tree[pos].c[0]].sum;
	}else if(tree[pos].x > x){
		return query_rank(tree[pos].c[0], x);
	}else{
		return tree[tree[pos].c[0]].sum + tree[pos].w + query_rank(tree[pos].c[1], x);
	}
}

int main(){
	int i, j;
	long long x, y;
	long long ans = 0;
	
	
	n = read();
	
	for(i=1;i<=n;i++){
		p[i].x = read();
		p[i].y = read();
	}
	
	sort(p + 1, p + n + 1, cmp);
	
	for(i=1;i<=n;i++){
		insert(root, p[i].x);
		if(i < n and p[i + 1].y == p[i].y){
			x = query_rank(root, p[i + 1].x - 1);
		}else{
			x = tree[root].sum;
		}
		
		y = query_rank(root, p[i].x);
		x = x - y + 1;
		ans += x * y;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}