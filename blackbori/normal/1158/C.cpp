#include <bits/stdc++.h>

using namespace std;

vector <int> V[505050];
vector <int> S;
int D[505050], A[505050];
bool chk[505050];
int n, x;

void dfs(int p)
{
	chk[p] = true;
	
	for(int &t: V[p]){
		if(!chk[t]){
			dfs(t);
		}
	}
	
	A[p] = ++x;
}

bool validate()
{
	int i;
	
	S.clear();
	
	for(i=n; i>=1; i--){
		for(; !S.empty() && A[S.back()] < A[i]; S.pop_back());
		if(D[i] != -1 && ((S.empty() && D[i] != n + 1) || (!S.empty() && D[i] != S.back()))) return 0;
		S.push_back(i);
	}
	
	return 1;
}

void tc()
{
	int i;
	
	cin >> n;
	
	S.clear();
	
	for(i=1; i<=n; i++){
		cin >> D[i];
		V[i].clear();
		chk[i] = 0;
	}
	
	for(i=n; i>=1; i--){
		if(D[i] == -1){
			S.push_back(i);
			continue;
		}
		
		for(; !S.empty(); S.pop_back()){
			if(S.back() == D[i]) break;
			V[i].push_back(S.back());
		}
		
		if((S.empty() && D[i] != n + 1) || (!S.empty() && D[i] != S.back())){
			cout << -1 << endl;
			return;
		}
		
		if(D[i] != n + 1) V[D[i]].push_back(i);
		S.push_back(i);
	}
/*
	for(i=1; i<=n; i++) for(int &t: V[i]){
		cout << i << "*" << t << endl;
	}
*/	
	x = 0;
	
	for(i=1; i<=n; i++){
		if(!chk[i]) dfs(i);
	}
	
	if(!validate()){
		cout << -1 << endl;
	}
	else{
		for(i=1; i<=n; i++){
			cout << A[i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	
	cin >> t;
	
	for(; t--; ){
		tc();
	}
	
	return 0;
}