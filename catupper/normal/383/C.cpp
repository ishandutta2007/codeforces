#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long int n, m, u, v, q, x, a[1 << 19];
vector<int> edge[210000];
int dep[1 << 19], p = 0, come[1 << 19], out [1 << 19];

void dfs(int x, int last = -1, int d = 0){
	dep[x] = d;
	come[x] = p++;
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i];
		if(to == last)continue;
		dfs(to, x, d + 1);
	}
	out[x] = p++;
}

int seg[1 << 20];

void add(int left, int right, int val, int bottom = 0, int top = 1 << 19, int pos = 1){
	if(right <= bottom || top <= left)return;
	if(left <= bottom && top <= right)seg[pos] += val;
	else{
		int mid = (bottom + top) / 2;
		add(left, right, val, bottom, mid, pos * 2);
		add(left, right, val, mid, top, pos * 2 + 1);
	}
}

int val(int pos){
	pos += 1 << 19;
	int res = 0;
	while(pos){
		res += seg[pos];
		pos /= 2;
	}
	return res;
}

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)cin >> a[i];
	for(int i = 0;i < n - 1;i++){
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);    	
	}
	dfs(1);
	for(int i = 1;i <= n;i++){
		if(dep[i] % 2 == 1)a[i] *= -1;
		add(come[i], come[i] + 1, a[i]);
	}
	for(int i = 0;i < m;i++){
		cin >> q;
		if(q == 1){
			cin >> x >> v;
			if(dep[x] % 2 == 1)v *= -1;
			add(come[x], out[x], v);
		}
		else{
			cin >> x;
			int res = val(come[x]);
			if(dep[x] % 2 == 1)res *= -1;
			cout << res << endl;
		}
	}
	return 0;
}