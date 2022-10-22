#include <bits/stdc++.h>

#define MAXN (100010)
#define ll long long
#define lowbit(x) ((x) & (-(x)))

struct node{
	ll val;
	node *ch[2];
	
	node():val(0){ memset(ch, 0, sizeof ch); }
}*nd_pool, *root[MAXN];
int nd_res;

int n, m;
int a[MAXN];
std::set<int> pos[MAXN];

node* newnode(){
	if(!nd_res) nd_pool = new node[nd_res = MAXN * 10];
	return nd_pool + (-- nd_res);
}

void insert(node* &rt, int l, int r, int pos, int v){
	if(!rt) rt = newnode();
	rt -> val += v;
	if(l == r) return;
	int m = (l + r) >> 1;
	if(pos <= m) insert(rt -> ch[0], l, m, pos, v);
	else insert(rt -> ch[1], m + 1, r, pos, v);
}

ll query(node *rt, int l, int r, int ql, int qr){
	if(ql > qr || !rt) return 0;
	if(ql <= l && r <= qr) return rt -> val;
	int m = (l + r) >> 1;
	ll ret = 0;
	if(!(m < ql)) ret += query(rt -> ch[0], l, m, ql, qr);
	if(!(qr < m + 1)) ret += query(rt -> ch[1], m + 1, r, ql, qr);
	return ret;
}

void modify(int x, int y, int v){
	for(int i = x; i && i <= n; i += lowbit(i)){
		insert(root[i], 0, n, y, v);
	}
}

ll getans(int l, int r){
	ll ret = 0;
	for(int i = r; i; i -= lowbit(i)){
		ret += query(root[i], 0, n, l, r);
	}
	for(int i = l - 1; i; i -= lowbit(i)){
		ret -= query(root[i], 0, n, l, r);
	}
	return ret;
}

void change(int x, int flag){
	if(~flag) pos[a[x]].insert(x);
	auto it = pos[a[x]].find(x);
	int pre = *-- it; ++ it;
	modify(x, pre, (x - pre) * flag);
	if(++ it != pos[a[x]].end()){
		int nxt = *it;
		modify(nxt, x, (nxt - x) * flag);
		modify(nxt, pre, (pre - nxt) * flag);
	}
	-- it;
	if(!~flag) pos[a[x]].erase(it);
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i) pos[i].insert(0);
	for(int i = 1; i <= n; ++ i){
		scanf("%d", a + i);
		pos[a[i]].insert(i);
	}
	for(int i = 1; i <= n; ++ i){
		for(auto it = pos[i].begin(); ; ++ it){
			auto it2 = ++ it; -- it;
			if(it2 == pos[i].end()) break;
			modify(*it2, *it, *it2 - *it);
		}
	}
	
	while(m --){
		int opt, l, r;
		scanf("%d%d%d", &opt, &l, &r);
		if(opt == 1){
			change(l, -1); a[l] = r; change(l, 1);
		}
		else{
			printf("%I64d\n", getans(l, r));
		}
	}
	return 0;
}