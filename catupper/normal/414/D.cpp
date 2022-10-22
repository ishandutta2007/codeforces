#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;
#define MOD 1000000007
vector<int> edge[108000];
Int ver[108000];
Int dep[108000];
Int imos[108000];
bool compare(const Int &a, const Int &b){
	return dep[a] > dep[b];
}

void dfs(Int x, Int last = -1, Int d = 1){
	dep[x] = d;
	for(Int i = 0;i < edge[x].size();i++){
		if(last == edge[x][i])continue;
		dfs(edge[x][i], x, d + 1);
	}
}

int main(){
	Int m, k, p, a, b;
	cin >> m >> k >> p;
	if(k == 0){
		cout << 0 << endl;
		return 0;
	}
	for(Int i = 1;i < m;i++){
		cin >> a >> b;
		a--,b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
		ver[i - 1] = i;
	}
	ver[m - 1] = m;
	dfs(0);
	sort(ver, ver + m, compare);
	for(int i = 1;i <= m;i++){
		imos[i] = imos[i - 1] + dep[ver[i - 1]];
	}
	m--;
	Int r = 0, res = 0;
	for(Int l = 0;l < m;l++){
		r = max(l, r);
		while(r < m && (r - l + 1) * dep[ver[l]] - (imos[r + 1] - imos[l])  <= p){
			r++;
		}
		r--;
		res = max(res, r - l + 1);
	}
	cout << min(k, res) << endl;
	return 0;
		
}