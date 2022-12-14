#include <bits/stdc++.h>
using namespace std;

int n, d, a[41000];
int f[31000][605], maxans, MX;

void upd(int &x, int y){
	x = max(x, y);
}

int find(int x, int y){
	if(x > 30000) return 0;
	if(~f[x][y - d + 300]) return f[x][y - d + 300];
	int c = max(find(x + y, y), find(x + y, y + 1));
	if(y > 1) c = max(c, find(x + y, y - 1));
	return f[x][y - d + 300] = a[x] + c;
}

int main(){
	memset(f, -1, sizeof(f));
	scanf("%d%d", &n, &d);
	int x;
	for(int i = 1;i <= n;i ++) scanf("%d", &x), a[x] ++;
	cout << find(0, d) << endl;
	return 0;
}