#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iostream>
#define maxn 1000009
using namespace std;
long long b[maxn];
int n, k;
void update(int x, int val){
	while(x < maxn){
		b[x] += val;
		x += x & -x;
	}
}
long long getsum(int x){
	long long sum = 0;
	while(x > 0){
		sum += b[x];
		x -= x & -x;
	}
	return sum;
}
long long query(int L, int R){
	int x = getsum(L) - getsum(L - 1);
	int y = getsum(R) - getsum(R - 1);
	if(L <= R){
		return getsum(R) - getsum(L - 1) - x - y;
	}
	else{
		return getsum(n) - getsum(L - 1) + getsum(R) - x - y;
	}
}
int main(){
	cin >> n  >> k;
	long long ans = 1;
	int cur = 1, nxt;
	for(int i = 1; i <= n; i++){
		nxt = cur + k;
		if(nxt > n)
			nxt -= n;
		if(k <= n / 2){
			ans += query(cur, nxt);
		}
		else{
			ans += query(nxt, cur);
		}
		update(cur, 1);
		update(nxt, 1);
		cur = nxt;
		ans++;
		cout << ans << " ";
	}
	return 0;
}