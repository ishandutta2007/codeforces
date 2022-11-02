#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#define maxn 200009
using namespace std;
int n,  m;
bool vis[maxn];
int val[maxn];
vector<int>D;
int dp[maxn], pre[maxn];
vector<int>G[maxn];
vector<int>pro;
void getdiv(){
	for(int i = 0; i < n; i++){
		if(vis[i])
			continue;
		int x = __gcd(i ,n);
		if(val[x] == 0){
			D.push_back(x);
		}
		val[x]++;
		G[x].push_back(i);
	}
	sort(D.begin(), D.end());
}

void findpro(int cur){
	if(pre[cur] != -1)
		findpro(pre[cur]);
	for(int j = 0 ; j < G[D[cur]].size(); j++){
		pro.push_back(G[D[cur]][j]);
	}
}

long long exgcd(long long x, long long y, long long &u, long long &v){
	if(y){
		long long res = exgcd(y, x % y, v, u);
		v = v - x / y * u;
		return res;
	}	
	else{
		u = 1;
		v = 0;
		return x;
	}
}

int main(){
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; i++){
		int x;
		scanf("%d", &x);
		vis[x] = 1;
	}
	getdiv();
	int sz = D.size();
	for(int i = 0; i < sz; i++){
		dp[i] = val[D[i]];
		pre[i] = -1;
		for(int j = 0; j < i; j++){
			if(D[i] % D[j] == 0){
				if(dp[i] < dp[j] + val[D[i]]){
					dp[i] = dp[j] + val[D[i]];
					pre[i] = j;
				}
			}
		}
	}
	int mx = 0;
	int pos = 0;
	for(int i = 0; i < sz; i++){
		if(dp[i] > mx){
			mx = dp[i];
			pos = i;
		}
	}
	
	findpro(pos);
	
	cout << pro.size() << endl;
	
	long long tot = 1;
	long long last = 1;
	for(int i = 0; i < (int)pro.size(); i++){
		long long u, v;
		long long g = exgcd(last, n, u ,v);
		//cout << last << " " << n << " " << g << endl;
		g = pro[i] / g;
		u = (u * g % n + n) % n;
		printf("%I64d ", u);
		last = pro[i];
		tot = tot * u % n;
		//cout << tot << endl;
	}
	return 0;
}