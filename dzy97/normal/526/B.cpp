#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, a[50000], sum[50000], Max[50000], mx, ret;
#define ls (u*2)
#define rs (u*2+1)

void dfs(int u){
	if(u>m)return;
	dfs(ls);
	dfs(rs);
	ret+=abs(a[ls]-a[rs]+Max[ls]-Max[rs]);
	Max[u]=max(Max[ls]+a[ls],Max[rs]+a[rs]);
}
	
int main(){
	scanf("%d", &n);
	m = (1 << (n + 1)) - 1;
	for(int i = 2;i <= m;i ++) scanf("%d", &a[i]);
	dfs(1);
	cout << ret << endl;
	return 0;
}