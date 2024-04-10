#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#define maxn 1000009
using namespace std;
const int MOD = 1e9 + 7;
long long fact[maxn];
map<int,int>mp;
vector<pair<int,int> >G;
vector<int>a[maxn];
int st[maxn];
int id[maxn];
bool cmp(int a, int b){
	return id[a] < id[b];
}
int main(){
	int tot  = 0;
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		int g;
		scanf("%d", &g);
		mp.clear();
		G.clear();
		for(int j = 0; j < g; j++){
			int x;
			scanf("%d", &x);
			mp[x]++;
		}
		for(auto it : mp){
			G.push_back(make_pair(it.second,it.first));
		}
		sort(G.begin(),G.end());
		int sz = G.size();
		int cur = 0;
		while(cur < sz){
			int L = cur;
			while(cur + 1 < sz && G[cur+1].first == G[cur].first){
				cur++;
			}
			int R = cur;
			for(int j = L; j <= R; j++){
				a[tot].push_back(G[j].second);
			}
			tot++;
			cur++;
		}
	}
	int sum = 0;
	for(int i = 1; i <= m ;i++){
		id[i] = 0;
		st[0] ++;
	}
	sum ++;
	for(int i = 0; i < tot; i++){
		sort(a[i].begin(),a[i].end(),cmp);
		int cur = 0;
		int sz = a[i].size();
		while(cur < sz){
			int L = cur;
			while(cur + 1 < sz && id[a[i][cur]] == id[a[i][cur+1]])
				cur++;
			int R = cur;
			int now = id[a[i][R]];
			if(R - L + 1 < st[now]){
				for(int j = L; j <= R; j++){
					id[a[i][j]] = sum;
				}
				st[now] -= R - L + 1;
				st[sum] += R - L + 1;
				sum++;
			}
			cur++;
		}
	}
	long long ans = 1;
	fact[0] = 1;
	for(int i = 1; i <= m; i++)
		fact[i] = fact[i - 1] * i % MOD;
	for(int  i = 0; i < sum ; i++){
		ans *= fact[st[i]];
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}