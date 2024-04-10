//Code By CXY
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5 + 10;

int n,ans,out[MAXN];
int m[MAXN],l[MAXN],r[MAXN],pre[MAXN],suf[MAXN];
int seg[MAXN << 2];

void build(int root,int l,int r) {
	if(l == r) return (void)(seg[root] = m[l]);
	int mid = (l + r) >> 1;
	build(root << 1,l,mid);
	build(root << 1 | 1,mid + 1,r);
	seg[root] = min(seg[root << 1],seg[root << 1 | 1]); 
}

int findr(int root,int l,int r,int L,int R,int v) {//right first
	if(l == r) {
		if(seg[root] < v) return l;
		else return 0;
	}
	int mid = (l + r) >> 1,res = 0;
	if(mid < R && seg[root << 1 | 1] < v) res = findr(root << 1 | 1,mid + 1,r,L,R,v);
	if(res) return res;
	if(L <= mid && seg[root << 1] < v) res = findr(root << 1,l,mid,L,R,v);
	return res;
}

int findl(int root,int l,int r,int L,int R,int v) {//left first
	if(l == r) {
		if(seg[root] < v) return l;
		else return 0;
	}
	int mid = (l + r) >> 1,res = 0;
	if(L <= mid && seg[root << 1] < v) res = findl(root << 1,l,mid,L,R,v);
	if(res) return res;
	if(mid < R && seg[root << 1 | 1] < v) res = findl(root << 1 | 1,mid + 1,r,L,R,v);
	return res;
}

signed main () {
	cin >> n;
	for(register int i = 1;i <= n; ++i)
		cin >> m[i];
	build(1,1,n);
	l[1] = m[1],pre[1] = 0;
	r[n] = m[n],pre[n] = n + 1;
	for(register int i = 2,p;i <= n; ++i) {
		p = findr(1,1,n,1,i - 1,m[i]);
		pre[i] = p;
		l[i] = l[p] + (i - p) * m[i];
	}
	for(register int i = n - 1,p;i >= 1; --i) {
		p = findl(1,1,n,i + 1,n,m[i]);
		if(!p) p = n + 1;
		suf[i] = p;
		r[i] = r[p] + (p - i) * m[i];
	}
	for(register int i = 1;i <= n; ++i) 
		if(l[i] + r[i] - m[i] > l[ans] + r[ans] - m[ans]) ans = i;
	int tmp = m[ans];
	for(register int i = ans;i <= n; ++i) {
		tmp = min(tmp,m[i]);
		out[i] = tmp;
	}
	tmp = m[ans];
	for(register int i = ans;i >= 1; --i) {
		tmp = min(tmp,m[i]);
		out[i] = tmp;
	}
	for(register int i = 1;i <= n; ++i)
		cout << out[i] << ' ';
	cout << endl;
	return 0;
}