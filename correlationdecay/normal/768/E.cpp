#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#define maxn 1300
using namespace std;
map<pair<int,long long>,int>mp;
int sg(int x, long long st){
	if(x == 0)
		return 0;
	pair<int,long long> cur = make_pair(x, st);
	if(mp.count(cur))
		return mp[cur];
	bool vis[70] = {0};
	for(int i = 1; i <= x; i++){
		if((1LL << i) & st)
			continue;
		if(x - i >= i)
			vis[sg(x - i, st ^ (1LL << i))] = 1;
		else
			vis[sg(x - i, st)] = 1;
	}
	for(int i = 0 ;i < 70; i++){
		if(!vis[i])
			return mp[cur] = i;
	}
	return 0;
}
int main(){
	int n;int  ans = 0;
	cin >> n;
	for(int i = 1; i <= n ; i++){
		int x;
		scanf("%d", &x);
		ans = ans ^ sg(x, 0);
	}
	if(ans == 0)
		puts("YES");
	else
		puts("NO");
	return 0;
}