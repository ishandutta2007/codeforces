#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int kkk;
int prime[maxn],tot,vis[maxn];
void init() {
	for (int i=2; i<=5000; ++i) {
		if (!vis[i])prime[++tot]=i;
		for (int j=1; j<=tot&&prime[j]*i<=5000; ++j) {
			vis[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
	}
}
struct rec{
	int a,b;
};
int main() {
	init();
	int n;
	scanf("%d", &n);
	vector<rec> ans;
	for(int i = 1; i < n; i++) ans.push_back(rec{i,i+1});
	ans.push_back(rec{n,1});
	for(int i = 1; i <= n; i++) {
		if(vis[ans.size()]==0) break;
		int v=i+(n/2);
		if(v>n)v-=n;
		ans.push_back(rec{i,v});
	}
	printf("%d\n", ans.size());
	for(int i=0;i<ans.size();++i) printf("%d %d\n",ans[i].a,ans[i].b);
	return 0;
}