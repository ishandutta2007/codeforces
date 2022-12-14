#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

#define N 200010
set<int> r, c;
typedef set<int> :: iterator SI;
int q[N], R, C, n;
char p[N];
long long an[N];
int main(){
	scanf("%d%d%d", &R, &C, &n);
	char op[2];
	int x;
	r.insert(0);
	r.insert(R);
	c.insert(0);
	c.insert(C);
	for(int i = 1;i <= n;i ++){
		scanf("%s%d", op, &x);
		q[i] = x;
		p[i] = op[0];
		if(op[0] == 'V') r.insert(x); else c.insert(x);
	}
	int mx1 = 0, mx2 = 0;
	for(SI it = r.begin();it != r.end();){
		int v = *it;
		it ++;
		if(it == r.end()) break;
		mx1 = max(mx1, *it - v);
	}
	for(SI it = c.begin();it != c.end();){
		int v = *it;
		it ++;
		if(it == c.end()) break;
		mx2 = max(mx2, *it - v);
	}
	for(int i = n;i;i --){
		an[i] = 1LL * mx1 * mx2;
		if(p[i] == 'V'){
			SI it = r.lower_bound(q[i]);
			int v = *(-- it);
			it ++;
			it ++;
			mx1 = max(mx1, *it - v);
			r.erase(q[i]);
		}else{
			SI it = c.lower_bound(q[i]);
			int v = *(-- it);
			it ++;
			it ++;
			mx2 = max(mx2, *it - v);
			c.erase(q[i]);
		}
	}
	for(int i = 1;i <= n;i ++) printf("%I64d\n", an[i]);
	return 0;
}