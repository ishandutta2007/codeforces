#include<bits/stdc++.h>
using namespace std;

int b[1010];
vector<int> c;
int n, k;

int main(){
	scanf("%d%d", &n, &k);
	int now = 0;
	for(int i = 1; i <= k; ++i){
		int x;
		scanf("%d", &x);
		b[x] = 1;
		now = __gcd(now, x);
	}
	bool flag0 = 0, flag1 = 0;
	for(int i = 0; i <= 1000; ++i)
		if(b[i]){
			c.push_back(i - n);
			if(i == n){
				printf("%d\n", 1);
				return 0;
			}
			if(i < n) flag0 = 1;
			else flag1 = 1;
		}
	if(!flag0 || ! flag1){
		printf("-1\n");
		return 0;
	}
	
	queue<int> q;
	map<int, int> mp; mp[0] = 0;
	q.push(0);
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(auto v : c){
			int y = x + v;
			if(y > 1000 || y < -1000) continue;
			if(y == 0){
				printf("%d\n", mp[x] + 1);
				return 0;
			}
			if(!mp.count(y)){
				mp[y] = mp[x] + 1;
				q.push(y);
			}
		}
	}
	return 0;
}