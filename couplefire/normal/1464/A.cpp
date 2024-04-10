#include<bits/stdc++.h>
using namespace std;
 
const int maxn = 1e5 + 5;
 
int n,m;
int head[maxn], cnt[maxn], bad[maxn];
 
int findhead(int x) {
	if(x == head[x]) return x;
	return head[x] = findhead(head[x]);
}
 
void solve() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) head[i] = i, cnt[i] = 0;
	int ans = 0;
	for(int i=1;i<=m;i++) {
		int x,y; scanf("%d%d",&x,&y);
		if(x == y) continue;
		head[findhead(x)] = findhead(y);
		cnt[x]++; cnt[y]++;
		ans++;
	}
	for(int i=1;i<=n;i++) bad[i] = 0;
	for(int i=1;i<=n;i++) if(cnt[i] != 0) bad[findhead(i)] = 1;
	for(int i=1;i<=n;i++) {
		if(cnt[i] == 1) bad[findhead(i)] = 0;
	}
	for(int i=1;i<=n;i++) ans += bad[i];
	printf("%d\n",ans);
}
 
int main() {
	int tnum; scanf("%d",&tnum);
	while(tnum--) solve();
}