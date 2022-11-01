#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 30005, M = N<<2;
int n, cnt[N], x[M], y[M], z[M];
bool vis[M], block[M];
vector<int> q, f[N];
void work(int t){
	for(int i:f[t])
		if(y[i]==z[i])
			if(cnt[y[i]]+2-(x[i]==y[i])<10) q.push_back(i), block[i]=0;
			else block[i]=1;
		else if(cnt[y[i]]+1-(x[i]==y[i])<10 && cnt[z[i]]+1-(x[i]==z[i])<10)
			q.push_back(i), block[i]=0;
		else block[i]=1;
}
int main() {
	scanf("%d", &n);
	fill(cnt+1, cnt+n+1, 4);
	for(int i=1; i<=n*4; ++i){
		scanf("%d%d%d", x+i, y+i, z+i);
		f[y[i]].push_back(i), f[z[i]].push_back(i);
		q.push_back(i);
	}
	puts("YES");
	while(1){
		while(!q.empty() && (vis[q.back()] || block[q.back()])) q.pop_back();
		if(q.empty()) break;
		int t=q.back();
		q.pop_back();
		printf("%d ", t);
		vis[t]=1;
		++cnt[y[t]], ++cnt[z[t]], --cnt[x[t]];
		work(y[t]), work(z[t]), work(x[t]);
		// for(int i=1; i<=n; ++i) assert(cnt[i]<=9);
	}
	return 0;
}