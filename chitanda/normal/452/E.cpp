#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const int maxn = 300100;
int tot, root, last, par[maxn * 2], go[maxn * 2][27], val[maxn * 2];
vector<int> son[maxn * 2];
//root=last=tot=1
void extend(int w){
	int p = last, np;
	if(!go[p][w]){
		np = ++tot; val[np] = val[p] + 1;
		while(p && !go[p][w]) go[p][w] = np, p = par[p];
		if(!p) par[np] = root;
		else{
			int q = go[p][w];
			if(val[p] + 1 == val[q]) par[np] = q;
			else{
				int nq = ++tot; val[nq] = val[p] + 1;
				memcpy(go[nq], go[q], sizeof(go[q]));
				par[nq] = par[q];
				par[q] = par[np] = nq;
				while(p && go[p][w] == q) go[p][w] = nq, p = par[p];
			}
		}
		last = np;
	}else{
		int q = go[p][w];
		if(val[p] + 1 == val[q]) last = q;
		else{
			int nq = ++tot; val[nq] = val[p] + 1;
			memcpy(go[nq], go[q], sizeof(go[q]));
			par[nq] = par[q];
			par[q] = nq;
			while(p && go[p][w] == q) go[p][w] = nq, p = par[p];
			last = nq;
		}
	}
}

char s1[maxn], s2[maxn], s3[maxn];
int w1[maxn * 2], w2[maxn * 2], w3[maxn * 2];
ll pre[maxn];

void dfs(int t){
	for(auto v : son[t]){
		dfs(v);
		pre[val[t] + 1] += (ll)w1[v] * w2[v] * w3[v];
		pre[val[v] + 1] -= (ll)w1[v] * w2[v] * w3[v];
		w1[t] += w1[v], w2[t] += w2[v], w3[t] += w3[v];
	}
}

int main(){
	root = last = tot = 1;

	auto func = [](char s1[], int w1[]){	
		last = root;
		scanf("%s", s1);
		for(int i = 0; s1[i]; ++i){
			extend(s1[i] - 'a');
			w1[last]++;
		}
	};
	func(s1, w1);
	func(s2, w2);
	func(s3, w3);
	for(int i = 2; i <= tot; ++i)
		son[par[i]].pb(i);
	dfs(1);
	int len = min({strlen(s1), strlen(s2), strlen(s3)});
	ll now = 0;
	for(int i = 1; i <= len; ++i){
		now += pre[i];
		printf("%lld ", now % M);
	}

#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}