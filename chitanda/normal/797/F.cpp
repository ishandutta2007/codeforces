#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

const ll inf = 1LL << 60;
const int maxn = 5010;

int n, m;
int x[maxn];
pair<int, int> y[maxn];
ll f[2][maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", x + i);
	}
	sort(x + 1, x + n + 1);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", &y[i].fi, &y[i].se);
	}
	sort(y + 1, y + m + 1);

	int cnt = 0, cur = 0, pre = 1;
	memset(f[cur], 127, sizeof(f[cur]));
	f[cur][0] = 0;

	for(int i = 1; i <= m; ++i){
		swap(cur, pre);
		memset(f[cur], 127, sizeof(f[cur]));
		f[cur][0] = 0;
		cnt += y[i].se; cnt = min(cnt, n);
		ll cost = 0;
		for(int j = 1, len = 0; j <= cnt; ++j){
			len++;
			cost += abs(x[j] - y[i].fi);
			ll tmp = f[pre][j - len] < inf && len <= y[i].se ? f[pre][j - len] + cost : inf;
			while(len){
				len--;
				ll ncost = cost - abs(x[j - len] - y[i].fi);
				ll ntmp = f[pre][j - len] < inf ? f[pre][j - len] + ncost : inf;
				if(ntmp < tmp){
					cost = ncost;
					tmp = ntmp;
				}else{
					len++; 
					break;
				}
			}
			f[cur][j] = tmp;
		}
	}
	printf("%lld\n", f[cur][n] < inf ? f[cur][n] : -1);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}