#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

const int maxn = 3e5 + 5;

int n, m, q;

int opt[maxn];

struct ex {
	long long st;
	long long ed;
	long long blank;
	
	int init(long long t, long long d){
		st = t;
		ed = t + d;
		blank = 0;
		return 0;
	}
};

ex exmerge(ex x, ex y){
	ex ret;
	
	if(x.st == 0){
		return y;
	}
	if(y.st == 0){
		return x;
	}
	
	if(x.ed < y.st){
		ret.st = x.st;
		ret.ed = y.ed;
		ret.blank = x.blank + y.blank + y.st - x.ed;
	}else{
		ret.st = x.st;
		ret.ed = y.ed + max(x.ed - y.st - y.blank, 0ll);
		ret.blank = x.blank + y.blank - min(x.ed - y.st, y.blank);
	}
	
	return ret;
}

struct node {
	long long t;
	long long d;
	ex x;
	int fix;
	int c[2];
	
	int init(long long tt, long long dd){
		t = tt;
		d = dd;
		fix = rand();
		c[0] = c[1] = 0;
		x.init(tt, dd);
		return 0;
	}
};

node tree[maxn * 2];
int tc = 0;
int root = 0;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int merge(int pos){
	tree[pos].x.init(tree[pos].t, tree[pos].d);
	if(tree[pos].c[0]){
		tree[pos].x = exmerge(tree[tree[pos].c[0]].x, tree[pos].x);
	}
	
	if(tree[pos].c[1]){
		tree[pos].x = exmerge(tree[pos].x, tree[tree[pos].c[1]].x);
	}
	return 0;
}

int rotate(int &pos, int d){
	int c = tree[pos].c[d];
	
	tree[pos].c[d] = tree[c].c[!d];
	tree[c].c[!d] = pos;
	
	merge(pos);
	merge(c);
	
	pos = c;
	
	return 0;
}

int insert(int &pos, long long t, long long d){
	if(!pos){
		pos = ++tc;
		tree[pos].init(t, d);
	}else{
		int dr = tree[pos].t < t;
		insert(tree[pos].c[dr], t, d);
		
		if(tree[pos].fix < tree[tree[pos].c[dr]].fix){
			rotate(pos, dr);
		}
		
		merge(pos);
	}
	
	return 0;
}

int remove(int &pos, long long t){
	if(tree[pos].t != t){
		int d = tree[pos].t < t;
		remove(tree[pos].c[d], t);
		merge(pos);
	}else{
		if(!tree[pos].c[0]){
			pos = tree[pos].c[1];
		}else if(!tree[pos].c[1]){
			pos = tree[pos].c[0];
		}else{
			int d = tree[tree[pos].c[0]].fix < tree[tree[pos].c[1]].fix;
			rotate(pos, d);
			remove(tree[pos].c[!d], t);
			merge(pos);
		}
	}
	
	return 0;
}

ex query(int &pos, long long t){
	ex ret;
	
	if(!pos){
		ret.init(0, 0);
	}else{
		ret.init(tree[pos].t, tree[pos].d);
		if(tree[pos].t > t){
			ret = query(tree[pos].c[0], t);
		}else if(tree[pos].t == t){
			ret = exmerge(tree[tree[pos].c[0]].x, ret);
		}else{
			ret = exmerge(exmerge(tree[tree[pos].c[0]].x, ret), query(tree[pos].c[1], t));
		}
	}
	
	return ret;
}

long long getans(long long t){
	ex ret = query(root, t);
	return max(ret.ed - t, 0ll);
}

int main(){
	int i, j;
	char op;
	int x, y;
	
	srand(time(0));
	
	q = read();
	
	for(i=1;i<=q;i++){
		scanf(" %c", &op);
		if(op == '+'){
			x = read();
			y = read();
			opt[i] = x;
			insert(root, x, y);
		}else if(op == '-'){
			x = read();
			remove(root, opt[x]);
		}else{
			x = read();
			printf("%lld\n", getans(x));
		}
	}
	
	return 0;
}