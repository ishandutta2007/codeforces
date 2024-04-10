#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <int> G[202020], T;
int D[202020], S[202020], A[202020];
int chk[202020], scc[202020];
int n, q, g, ans, cnt;

int dfs(int p)
{
	int ret;
	
	ret = chk[p] = ++cnt;
	T.push_back(p);
	
	for(int &t: G[p]){
		if(!chk[t]) ret = min(ret, dfs(t));
		else if(!scc[t]) ret = min(ret, chk[t]);
	}
	
	if(ret == chk[p]){
		for(g ++; !scc[p]; T.pop_back()){
			scc[T.back()] = g;
			D[g] = max(D[g], S[T.back()]);
		}
	}
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int i;
	
	cin >> n >> q;
	
	for(i=1; i<=n; i++){
		cin >> A[i];
		S[A[i]] ++;
	}
	
	for(i=2; i<=n; i++){
		G[A[i]].push_back(A[i - 1]);
	}
	
	for(i=1; i<=2e5; i++){
		if(!chk[i]){
			dfs(i);
		}
	}
	
	ans = n;
	
	for(i=1; i<=g; i++){
		ans -= D[i];
	}
	
	cout << ans << "\n";
	
	return 0;
}