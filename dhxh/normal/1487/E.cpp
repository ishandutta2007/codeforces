#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n[4];
int m[3];

int a[4][maxn];

set <int> p[4][maxn];

int f[4][maxn];

int main(){
	int i, j;
	int x, y;
	
	for(i=0;i<4;i++) scanf("%d", &n[i]);
	
	for(i=0;i<4;i++){
		for(j=0;j<n[i];j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	for(i=0;i<3;i++){
		scanf("%d", &m[i]);
		for(j=0;j<m[i];j++){
			scanf("%d%d", &x, &y);
			p[i + 1][y - 1].insert(x - 1);
		}
	}
	
	for(i=0;i<n[0];i++) f[0][i] = a[0][i];
	
	for(i=1;i<4;i++){
		priority_queue <pair <int, int> > q;
		for(j=0;j<n[i-1];j++){
			q.push({-f[i - 1][j], j});
		}
		
		for(j=0;j<n[i];j++){
			stack <pair <int, int> > s;
			while(q.size() and p[i][j].count(q.top().second)){
				s.push(q.top());
				q.pop();
			}
			if(q.size()){
				f[i][j] = -q.top().first + a[i][j];
			}else{
				f[i][j] = 0x3f3f3f3f;
			}
			
			while(s.size()){
				q.push(s.top());
				s.pop();
			}
		}
	}
	
	int ans = 0x3f3f3f3f;
	
	for(i=0;i<n[3];i++){
		ans = min(ans, f[3][i]);
	}
	
	if(ans == 0x3f3f3f3f) ans = -1;
	
	printf("%d\n", ans);
	
	return 0;
}