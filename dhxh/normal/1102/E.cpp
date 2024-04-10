#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

const int maxn = 2e5 + 5;

long long mod = 998244353;

int n, m, t;

map <int, int> st;
map <int, int> ed;

queue <int> q;

vector <pair <int, int> > vec;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

long long qpow(long long b, long long x){
	long long ret = 1;
	
	while(x){
		if(x & 1){
			ret = ret * b % mod;
		}
		
		x >>= 1;
		b = b * b % mod;
	}
	
	return ret;
}

int main(){
	int i, j;
	int x, y;
	int cnt = 0;
	
	n = read();
	
	for(i=1;i<=n;i++){
		x = read();
		if(!st[x]){
			st[x] = ed[x] = i;
			q.push(x);
		}else{
			ed[x] = i;
		}
	}
	
	while(!q.empty()){
		x = q.front();
		q.pop();
		vec.push_back(make_pair(st[x], ed[x]));
	}
	
	sort(vec.begin(), vec.end());
	
	x = 0, y = 0;
	
	for(i=0;i<vec.size();i++){
		if(vec[i].first > y){
			x = vec[i].first;
			y = vec[i].second;
			cnt++;
		}else{
			y = max(y, vec[i].second);
		}
	}
	
	printf("%lld\n", qpow(2, cnt - 1));
	
	return 0;
}