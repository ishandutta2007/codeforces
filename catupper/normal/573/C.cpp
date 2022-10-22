#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool ok[108000];
vector<int> edge[108000];
int cntleaf[108000];
int a, b, n;
int distx[108000];
int disty[108000];
int leaf;
vector<int> up;

int far(int x, int *dist, int last = -1, int d = 0){
	dist[x] = d;
	int res = x;
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i];
		if(to == last)continue;
		int tmp = far(to, dist, x, d + 1);
		if(dist[tmp] > dist[res] && !ok[tmp])res = tmp;
	}
	return res;
}




void dfs(int x, int last = -1){
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i];
		if(to == last)continue;
		dfs(to, x);
		cntleaf[x] += cntleaf[to];
	}
	if(cntleaf[x] < 2 || leaf - cntleaf[x] < 2){
		ok[x] = true;
	}
	if((cntleaf[x] == 2 || leaf - cntleaf[x] == 2) && edge[x].size() == 3){
		ok[x] = true;
	}
}

void yes(){
	cout << "Yes" << endl;
	exit(0);
}
void no(){
	cout << "No" << endl;
	exit(0);
}

int main(){
	cin >> n;
	for(int i = 0;i < n - 1;i++){
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(int i = 1;i <= n;i++){
		if(edge[i].size() == 1){
			leaf++;
			cntleaf[i]++;	
		}
	}
	dfs(1);
	
	for(int i = 1;i <= n;i++){
		if(!ok[i]){
			up.push_back(i);
		}
	}
	if(up.size() <= 2)yes();
	int s = up[0];
	int x = far(s, distx);
	int y = far(x, distx);
	far(y, disty);
	int d = distx[y];
	for(int i = 1;i <= n;i++){
		if(ok[i])continue;
		if(distx[i] + disty[i] != d)no();
	}
	yes();
	return 0;
}