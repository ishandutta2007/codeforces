//Code By CXY
#include<bits/stdc++.h>
using namespace std;

//#define int long long

const int MAXN = 5010;
const int INF = 2e9;

int T;
int n,d,mind,maxd,now;
int son[MAXN],fa[MAXN],dep[MAXN];
bool tag[MAXN];

signed main () {
	cin >> T;
	while(T--) {
		cin >> n >> d;
		now = maxd = (n - 1) * n / 2;
		mind = 0;
		memset(son,0,sizeof son);
		for(register int i = 1,tmp = -1;i <= n; ++i) {
			fa[i] = i - 1;
			dep[i] = i - 1;
			son[i - 1] = 1;
			tag[i] = false;
			if((i & (i - 1)) == 0) tmp++;
			mind += tmp;
		}
		//cout << mind << ' '<< maxd << endl;
		if(d < mind || d > maxd) {puts("NO"); continue;}
		while(now != d) {
			int s = 0,to = 0;
			for(register int i = 1;i <= n; ++i) 
				if(!tag[i] && (!son[i]) && (!s || dep[s] > dep[i]))
					s = i;
			for(register int i = 1;i <= n; ++i)
				if(son[i] < 2 && dep[i] == dep[s] - 2) {
					to = i; break;
				}
			if(!to) {tag[s] = true; continue;}
			son[fa[s]]--;
			fa[s] = to;
			dep[s]--;
			son[to]++;
			now--;
		}
		puts("YES");
		for(register int i = 2;i <= n; ++i)
			cout << fa[i] << ' ';
		cout << endl;
	}
	return 0;
}