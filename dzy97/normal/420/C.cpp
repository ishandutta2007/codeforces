#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int mo=1e9+7,N=3e5+10;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
struct treapnode{
	int ch[2],val,sz,pri,cnt;
}t[N * 2];
int pool[N * 2], ptot;
#define ls t[x].ch[0]
#define rs t[x].ch[1]
int tot,rt;
void init(){
	tot = ptot = rt = 0;
}
inline void upd(int x){
	t[x].sz = t[ls].sz + t[rs].sz + 1;
}
void rot(int &x,int f){// 1 zag  0 zig 
	int y = t[x].ch[!f];
	t[x].ch[!f] = t[y].ch[f];
	t[y].ch[f] = x;
	upd(x);
	upd(y);
	x = y;
}

void ins(int &x,int v){
	if(!x){
		if(ptot) x = pool[ptot --]; else x = ++ tot;
		t[x] = (treapnode){{0,0},v,1,rand()};
	}else{
		int f = (v >= t[x].val);
		ins(t[x].ch[f],v);
		if(t[t[x].ch[f]].pri > t[x].pri)	rot(x,!f);	
	}
	upd(x);
}
void del(int &x,int v){
	if(t[x].val == v){
		if(!ls || !rs){
			pool[++ ptot] = x;
			x = ls + rs;
			return;
		}else{
			int f = (t[ls].pri > t[rs].pri);
			rot(x,f);
			del(t[x].ch[f],v);
		}
	}else	del(t[x].ch[v >= t[x].val],v);
	upd(x);
}
int count(int v){// >=v :: size
	int x = rt,ret = 0;
	while(x){
		if(t[x].val >= v)	ret += t[rs].sz + 1, x = ls;
		else	x = rs;
	}
	return ret;
}
inline void ins(int v){ins(rt,v);}
inline void del(int v){del(rt,v);}
vector<int> g[N];
struct node{
	int x, y;
}a[N];
int n, m, cnt[N], vis[N], vt, rec[N];
bool cmp(const node &a, const node &b){
	return a.x < b.x;
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i ++){
		scanf("%d%d", &a[i].x, &a[i].y);
		if(a[i].x > a[i].y) swap(a[i].x, a[i].y);
		cnt[a[i].y] ++;
		cnt[a[i].x] ++;
		g[a[i].x].push_back(i);
		g[a[i].y].push_back(i);
	}
	init();
	for(int i = 1;i <= n;i ++) ins(cnt[i]);
	ll ans = 0;
	for(int i = 1;i <= n;i ++){
		del(cnt[i]);
		ans += count(m - g[i].size());
		ins(cnt[i]);
		for(int j = 0;j < g[i].size();j ++){
			int u = g[i][j];
			rec[a[u].x] = rec[a[u].y] = 0;
		}
		for(int j = 0;j < g[i].size();j ++){
			int u = g[i][j];
			rec[a[u].x] ++;
			rec[a[u].y] ++;
		}
		for(int j = 0;j < g[i].size();j ++){
			int u = g[i][j];
			if(vis[a[u].x] != i && a[u].x != i){
				vis[a[u].x] = i;
				if(cnt[a[u].x] >= (m - g[i].size()) && cnt[a[u].x] - rec[a[u].x] < (m - g[i].size())) ans --;
			}
			if(vis[a[u].y] != i && a[u].y != i){
				vis[a[u].y] = i;
				if(cnt[a[u].y] >= (m - g[i].size()) && cnt[a[u].y] - rec[a[u].y] < (m - g[i].size())) ans --;
			}
		}
	}
	cout << ans / 2 << endl;
	return 0;
}