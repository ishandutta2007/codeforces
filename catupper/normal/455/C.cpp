#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int u[324000], depth[324000], done[324000], dia[324000];
vector<int> edge[324000];

int r(int x){
	if(u[x] == x)return x;
	return u[x] = r(u[x]);
}

void unin(int a, int b){
	a = r(a), b = r(b);
	u[a] = b;
}

int far(int x, int last = -1, int d = 0){
	depth[x] = d;
	int p = x;
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i];
		if(to == last)continue;
		int tmp = far(to, x, d + 1);
		if(depth[tmp] > depth[p])p = tmp;
	}
	return p;
}

int main(){
	int n, m, q, a, b, x, y, qq;
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1;i <= n;i++)u[i] = i;
	for(int i = 0;i < m;i++){
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
		unin(a, b);
	}
	for(int i = 1;i <= n;i++){
		if(done[r(i)])continue;
		done[r(i)] = true;
		int p = far(i);
		p = far(p);
		dia[r(i)] = depth[p];		
	}
	
	for(int i = 0;i < q;i++){
		scanf("%d", &qq);
		if(qq == 1){
			scanf("%d", &x);
			printf("%d\n", dia[r(x)]);
		}
		else{
			scanf("%d%d", &x, &y);
			if(r(x) == r(y))continue;
			int xd = dia[r(x)];
			int yd = dia[r(y)];
			int xr = xd / 2 + xd % 2;
			int yr = yd / 2 + yd % 2;
			unin(x, y);
			dia[r(x)] = max(max(xd, yd), xr + yr + 1);
		}
	}
	
	return 0;	
}