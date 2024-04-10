#include<cstdio>
#include<algorithm>
#include<cctype>
#include<string.h>
#include<cmath>
#include<vector>

using namespace std;
#define ll long long

const int N = 100005, M = 17, K = 1<<M;
int n, p, a[M][M], f[M][N];
bool BAN[K], g[K], ban[M][M][K];
char s[N];
vector<int> pos[M];
int main() {
	scanf("%d%d%s", &n, &p, s+1);
	for(int i=0; i<p; ++i) for(int j=0; j<p; ++j) scanf("%d", a[i]+j);
	for(int i=1; i<=n; ++i) pos[(int)(s[i]-='a')].push_back(i);
	for(int i=0; i<p; ++i){
		for(int j=1; j<=n; ++j) f[i][j]=(s[j]==i?0:f[i][j-1]|(1<<s[j]));
		if(!a[i][i]) for(unsigned j=1; j<pos[i].size(); ++j)
			ban[i][i][f[i][pos[i][j]-1]]=1;
	}
	for(int i=0; i<p; ++i) for(int j=i+1; j<p; ++j) if(!a[i][j]){
		vector<int> tmp;
		merge(pos[i].begin(), pos[i].end(), pos[j].begin(), pos[j].end(), back_inserter(tmp));
		for(unsigned int k=1; k<tmp.size(); ++k) if(s[tmp[k]]!=s[tmp[k-1]])
			ban[i][j][f[(int)s[tmp[k-1]]][tmp[k]-1]]=1;
	}
	for(int x=0; x<p; ++x) for(int y=x; y<p; ++y) if(!a[x][y]){
		bool *Ban=ban[x][y];
		for(int i=1; i<1<<p; i<<=1) for(int j=0; j<1<<p; j+=i<<1)
			for(int k=j; k<j+i; ++k) Ban[k+i]|=Ban[k];
		for(int i=0; i<1<<p; ++i) if(!(i>>x&1) && !(i>>y&1)) BAN[((1<<p)-1)^i]|=Ban[i];
		// if(BAN[15]) printf("-- %d %d\n", x, y);
	}
	int Ans=n;
	g[(1<<p)-1]=1;
	// printf(">> %d\n", BAN[15]);
	for(int i=1<<p; i--;) if(g[i] && !BAN[i]){
		int cnt=0;
		for(int j=0; j<p; ++j) if(i>>j&1)
			cnt+=pos[j].size(), g[i^(1<<j)]|=1;
		Ans=min(Ans, cnt);
	}
	return printf("%d", Ans), 0;
}