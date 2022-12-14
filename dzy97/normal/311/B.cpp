#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long ll;
const int mo=1e9+7,N=1e5+10;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
int n, m, P, d[N];
ll f[N][105], g[105], a[N], b[N];
deque<int> q[105];
void ins(int u, int k){
	while(q[u].size() > 1){
		int j = q[u].back();
		q[u].pop_back();
		int i = q[u].back();
		q[u].push_back(j);
		if((f[k][u] + b[k] - f[j][u] - b[j]) * (j - i) < (f[j][u] + b[j] - f[i][u] - b[i]) * (k - j)) q[u].pop_back(); else break;
	}
	q[u].push_back(k);
}
void del(int u, int o){
	while(q[u].size() > 1){
		int i = q[u].front();
		q[u].pop_front();
		int j = q[u].front();
		q[u].push_front(i);
		if((f[j][u] + b[j] - f[i][u] - b[i]) < 1LL * (j - i) * a[o]) q[u].pop_front(); else break;
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &P);
	for(int i = 2;i <= n;i ++) scanf("%d", &d[i]), d[i] += d[i - 1];
	int x, y;
	for(int i = 1;i <= m;i ++){
		scanf("%d%d", &x, &y);
		a[i] = y - d[x];
	}
	sort(a + 1, a + m + 1);
	for(int i = 1;i <= m;i ++) b[i] = b[i - 1] + a[i];
	memset(g, 63, sizeof(g));
	memset(f, 63, sizeof(f));
	f[0][0] = 0;
	g[0] = 0;
	ins(0, 0);
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= P;j ++){
			del(j - 1, i);
			if(q[j - 1].size()){
				int k = q[j - 1].front();
				f[i][j] = min(f[i][j], f[k][j - 1] + b[k] - b[i] + 1LL * (i - k) * a[i]);
			}
		}
		for(int j = 1;j <= P;j ++) ins(j, i);
	}
	cout << f[m][P] << endl;
	return 0;
}