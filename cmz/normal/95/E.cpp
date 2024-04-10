#include<bits/stdc++.h>
#define DEBUG cerr << "Call out: " << __func__ << "\t" << "Line: " << __LINE__ << "\t :"
using namespace std;

vector <int> f[100010];
int vis[100010];
int DFS(int x) {
	vis[x] = 1;
	int total = 1;
	for (auto i : f[x]) {
		if (!vis[i]) total += DFS(i);
	}
	return total;
}
int n,m;
map <int,int> t;
int a[100010];
int b[100010];
int DP[100010];
int q[100010];
int num[100010];
int check(int x) {
	while (x > 0) {
		if (x % 10 != 4 && x % 10 != 7) return 0;
		x /= 10;
	}
	return 1;
}
int MAIN() {
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(vis,0,sizeof(vis));
	t.clear();
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		f[i].clear();
	}
	for (int i=1; i<=m; i++) {
		int tp1,tp2;
		scanf("%d%d",&tp1,&tp2);
		f[tp1].push_back(tp2);
		f[tp2].push_back(tp1);
	}
	for (int i=1; i<=n; i++) {
		if (!vis[i]) t[DFS(i)] ++;
	}
	int pl = 0;
	memset(DP,0x3f3f3f3f,sizeof(DP));
	DP[0] = 0;
	for (auto i : t) {
		int tp = i.first;
		int tot = i.second;
		int w,v,s;
		w = tp;
		v = 1;
		s = tot;
		if(s>n/w)s=n/w;
		for(int d=0; d<w; d++) {
			int he=1;
			int ta=1;
			for(int j=0; j<=(n-d)/w; j++) {
				int tmp=DP[j*w+d]-v*j;
				while(he<ta&&q[ta-1]>tmp)--ta;
				q[ta]=tmp,num[ta++]=j;
				while(he<ta&&j-num[he]>s)++he;
				DP[j*w+d]=min(DP[j*w+d],q[he]+v*j);
			}
		}
	}
	int ANS = 0x3f3f3f3f;
	for (int i=1; i<=n; i++) {
//		cout << DP[i] << endl;
		if (check(i)) ANS = min(ANS, DP[i]);
	}
	if (ANS > n) {
		cout << -1 << endl;
		return 0;
	}
	cout << ANS-1 << endl;
	return 0;
}

int main() {
	int T;
	T=1;
	while (T--) {
		MAIN();
	}
}