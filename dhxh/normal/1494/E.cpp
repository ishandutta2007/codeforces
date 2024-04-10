#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m;

map <int, char> a[maxn];

int main(){
	int i, j;
	int ca = 0, cb = 0;
	
	scanf("%d%d", &n, &m);
	
	while(m--){
		char op;
		scanf(" %c", &op);
		if(op == '+'){
			int x, y;
			char c;
			scanf("%d%d %c", &x, &y, &c);
			a[x][y] = c;
			if(a[y].count(x)){
				cb++;
				if(c == a[y][x]) ca++;
			}
		}else if(op == '-'){
			int x, y;
			scanf("%d%d", &x, &y);
			if(a[y].count(x)){
				cb--;
				if(a[x][y] == a[y][x]) ca--;
				
			}
			a[x].erase(y);
		}else{
			int x;
			scanf("%d", &x);
			x--;
			if(ca){
				printf("YES\n");
			}else if(x % 2 == 0 and cb){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	
	return 0;
}