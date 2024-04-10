#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

long long n, m, t;

long long a[maxn];

long long ans = 0;

int ec = 1;

struct ex {
    int c[2];
    long long s;
    long long value;
    int fix;
    long long w;
    bool v;
    
    int init(long long x){
        value = x;
        fix = rand();
        v = true;
        w = 1;
        s = 1;
    }
};

ex tree[maxn * 4];

int root = 0;
    
int getsize(int &pos){
    tree[pos].s = tree[pos].w + tree[tree[pos].c[0]].s + tree[tree[pos].c[1]].s;
}

int rotate(int &pos, int d){
    int c = tree[pos].c[d];
    
    tree[pos].c[d] = tree[c].c[!d];
    tree[c].c[!d] = pos;
    
    getsize(pos);
    getsize(c);
    pos = c;
    
    return 0;
}

int insert(int &pos, long long x){
    int d;
    if(!pos){
    	ec++;
    	pos = ec;
        tree[pos].init(x);
    }else{
        if(tree[pos].value == x){
            tree[pos].w++;
            getsize(pos);
        }else{
            d = tree[pos].value < x;
            insert(tree[pos].c[d], x);
            if(tree[pos].fix < tree[tree[pos].c[d]].fix){
                rotate(pos, d);
            }else{
                getsize(pos);
            }
        }
    }
    return 0;
}

long long query_rank(int &pos, long long x){
	if(!pos){
		return 0;
	}
    if(tree[pos].value == x){
        return tree[tree[pos].c[0]].s;
    }else if(tree[pos].value > x){
        return query_rank(tree[pos].c[0], x);
    }else{
        return tree[tree[pos].c[0]].s + tree[pos].w + query_rank(tree[pos].c[1], x);
    }
}

long long read(){
	long long x;
	scanf("%I64d", &x);
	return x;
}

int main(){
	long long i, j;
	
	n = read();
	
	m = read();
	
	for(i=1;i<=n;i++){
		a[i] = read();
		a[i] += a[i - 1];
	}
	
	insert(root, a[n]);
	
	for(i=n-1;i>=0;i--){
		ans += query_rank(root, m + a[i]);
		insert(root, a[i]);
	}
	
	printf("%I64d\n", ans);
	
	return 0;
}