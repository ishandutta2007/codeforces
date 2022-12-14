#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
#define N 200010
int n, K, cs[N], cv[N], tmp1[N], tmp2[N], sa[N], st[N], len[N], q[N], pos[N], vis[N], color, rig[N], ra[N], he[N], f[18][N], lg[N], val[N], s[N];
ll ans[N];
char str[N];

#define A(x,y) ((sa[x] + y - 1 < cur) ? (str[sa[x] + y - 1]) : (0))
int cmp(int *r, int a, int b, int l){ return (r[a] == r[b]) && (r[a + l] == r[b + l]);}
void da(int *r, int n, int m){
	int i, j, k = 0, p, *x = tmp1, *y = tmp2, *t;
	for(i = 0;i < m;i ++) cs[i] = 0;
	for(i = 0;i < n;i ++) cs[x[i] = r[i]] ++;
	for(i = 1;i < m;i ++) cs[i] += cs[i - 1];
	for(i = n - 1;~i;i --) sa[-- cs[x[i]]] = i;
	for(j = p = 1;p < n;j <<= 1, m = p){
		for(p = 0, i = n - j;i < n;i ++) y[p ++] = i;
		for(i = 0;i < n;i ++) if(sa[i] >= j) y[p ++] = sa[i] - j;
		for(i = 0;i < m;i ++) cs[i] = 0;
		for(i = 0;i < n;i ++) cs[cv[i] = x[y[i]]] ++;
		for(i = 1;i < m;i ++) cs[i] += cs[i - 1];
		for(i = n - 1;~i;i --) sa[-- cs[cv[i]]] = y[i];
		for(t = x, x = y, y = t, p = i = 1, x[sa[0]] = 0;i < n;i ++) x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p ++;
	}
	for(int i = 0;i < n;i ++) ra[sa[i]] = i;
	for(int i = 0;i < n;he[ra[i ++]] = k) for(k = max(k - 1, 0), j = sa[ra[i] - 1];r[i + k] == r[j + k];k ++);
}

inline void add(int x){ if(++ vis[x] == 1) color ++;}
inline void del(int x){ if(-- vis[x] == 0) color --;}

inline int ask(int l, int r){
	int k = lg[r - l + 1];
	return min(f[k][l], f[k][r - (1 << k) + 1]);
}

int main(){
	scanf("%d%d", &n, &K);
	int cur = 0, kk = 'z';
	for(int i = 1;i <= n;i ++) st[i] = cur, scanf("%s", str + cur), cur += len[i] = strlen(str + cur), str[cur ++] = '$';
	for(int i = 0;i < cur;i ++) if(str[i] == '$') s[i] = ++ kk; else s[i] = str[i];
	if(K == 1){
		for(int i = 1;i <= n;i ++) printf("%I64d%c", 1LL * len[i] * (len[i] + 1) / 2, (i == n) ? '\n' : ' ');
		return 0;
	}
	++ cur;
//	printf("%s\n", str);
	da(s, cur, kk + 10);
	int m = cur - n;
	for(int i = 1;i <= n;i ++) for(int j = 1;j <= len[i];j ++) pos[st[i] + j - 1] = i;
	for(int i = 2;i <= 200000;i ++) if(i & (i - 1)) lg[i] = lg[i - 1]; else lg[i] = lg[i - 1] + 1;
	for(int i = 0;i < m;i ++) f[0][i] = he[i];
	for(int j = 1;j <= 17;j ++)
		for(int i = 0;i + (1 << j) - 1 < m;i ++)
			f[j][i] = min(f[j - 1][i], f[j - 1][i + (1 << (j - 1))]);
	int j = -1;
	for(int i = 0;i < m;i ++){
		while(color < K && j + 1 < m) add(pos[sa[j + 1]]), j ++;
		rig[i] = (color == K) ? j : 1e9;
		if(rig[i] < 1e9) val[i] = ask(i + 1, rig[i]);
	//	cout << i <<" " << rig[i] << endl;
		del(pos[sa[i]]);
	}
	//cout <<"ASK31,39:"<<ask(31,39)<< endl;
/*	for(int i = 0;i <= m;i ++){
		cout << i << "(" << pos[sa[i]] << ")" << "["<<he[i] <<" " <<rig[i]<<" "<< val[i] << "] : ";
		for(int j = sa[i];j < cur;j ++) putchar(str[j]);
		cout << endl;
	}
	*/
	int s = 1, e = 0;
	j = -1;
	for(int i = 0;i < m;i ++){
		while(j + 1 < m && rig[j + 1] < i) j ++;
		int tmp = (~j) ? ask(j + 1, i) : 0;
		while(s <= e && rig[q[s]] < i) s ++;
		while(s <= e && val[q[e]] < val[i]) e --;
		q[++ e] = i;
	//	for(int i = s;i <= e;i ++) cout << q[i] <<" ";cout << endl;
		if(s <= e) tmp = max(tmp, val[q[s]]);
	//	cout << i << " "<< tmp << endl;
		ans[pos[sa[i]]] += tmp;
	}
/*	for(int i = 0;i < m;i ++){
		int tmp = 0;
		for(int j = 0;j <= i;j ++){
			if(rig[j] == 1e9) break;
			if(rig[j] >= i) tmp = max(tmp, val[j]); else tmp = max(tmp, ask(j + 1, i));
		}
		cout << i << " "<< tmp << endl;
		ans[pos[sa[i]]] += tmp;
	}	*/
	for(int i = 1;i <= n;i ++) printf("%I64d%c", ans[i], (i == n) ? '\n' : ' ');
	return 0;
}