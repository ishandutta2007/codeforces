#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

int n, m, t;

vector <int> e[maxn];

int color[maxn];

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		for(i=1;i<=n;i++){
			e[i].clear();
			color[i] = -1;
		}
		
		for(i=1;i<=m;i++){
			scanf("%d%d", &x, &y);
			e[x].push_back(y);
			e[y].push_back(x);
		}
		
		color[1] = 1;
		queue <int> q;
		for(auto y : e[1]){
			color[y] = 0;
			q.push(y);
		}
		
		while(q.size()){
			x = q.front();
			q.pop();
			
			for(auto y : e[x]){
				if(color[y] != -1) continue;
				color[y] = 1;
				for(auto z : e[y]){
					if(color[z] != -1) continue;
					color[z] = 0;
					q.push(z);
				}
			}
		}
		
		bool flag = false;
		vector <int> vec;
		for(i=1;i<=n;i++){
			if(color[i] == -1){
				flag = true;
				break;
			}
			if(color[i]){
				vec.push_back(i);
			}
		}
		
		if(flag){
			printf("NO\n");
			continue;
		}
		
		printf("YES\n");
		printf("%d\n", (int)vec.size());
		
		printf("%d", vec[0]);
		for(i=1;i<vec.size();i++){
			printf(" %d", vec[i]);
		}
		printf("\n");
	}
	
	return 0;
}