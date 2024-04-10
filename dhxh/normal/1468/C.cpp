#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int n, m, t;

bool vis[maxn];

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	priority_queue <pair <int, int> > q;
	int c = 0;
	
	while(t--){
		int x;
		scanf("%d", &x);
		if(x == 1){
			scanf("%d", &x);
			n++;
			q.push({x, -n});
		}else if(x == 2){
			while(vis[++c]);
			printf("%d ", c);
			vis[c] = true;
		}else if(x == 3){
			while(vis[-q.top().second]) q.pop();
			vis[-q.top().second] = true;
			printf("%d ", -q.top().second);
			q.pop();
		}
	}
	printf("\n");
	
	return 0;
}