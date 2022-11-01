#include <bits/stdc++.h>

using namespace std;

int n, m, t;

struct ex {
	int x, y;
};

ex a[1005];

int main(){
	int i, j;
	int x, y;
	
	scanf("%d", &t);
	
	while(t--){
		scanf("%d%d", &n, &m);
		
		for(i=1;i<=n;i++){
			scanf("%d%d", &x, &y);
			a[i] = {x, y};
		}
		
		int f = -1;
		
		for(i=1;i<=n;i++){
			bool g = false;
			for(j=1;j<=n;j++){
				if(abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y) > m){
					g = true;
					break;
				}
			}
			if(!g){
				f = 1;
				break;
			}
		}
		
		printf("%d\n", f);
	}
	
	return 0;
}