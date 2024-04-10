#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 10;

struct Pseg {
	int l,r,sum;
} seg[MAXN * 50];

int n,m,cnt;
int root[MAXN];
int a[MAXN],R;
vector<int> v;

inline int getid(int x) {return lower_bound(v.begin(),v.end(),x) - v.begin() + 1;}

void update(int pre,int &now,int l,int r,int pos,int val) {
	seg[now = ++cnt] = seg[pre];
	seg[now].sum++;
	if(l == r) return;
	int mid = (l + r) >> 1;
	if(pos <= mid) update(seg[pre].l,seg[now].l,l,mid,pos,val);
	else update(seg[pre].r,seg[now].r,mid + 1,r,pos,val);
}

int query(int pre,int now,int l,int r,int val) {
	int mid = (l + r) >> 1,res;
	if(l == r) return l;
	int L = seg[seg[now].l].sum - seg[seg[pre].l].sum;
	int R = seg[seg[now].r].sum - seg[seg[pre].r].sum;
	if(L > val) {
		res = query(seg[pre].l,seg[now].l,l,mid,val);
		if(res != -1) return res;
	}
	if(R > val) {
		res = query(seg[pre].r,seg[now].r,mid + 1,r,val);
		if(res != -1) return res;
	}
	else return -1;
}

int main () {
	scanf("%d%d",&n,&m);
	for(register int i = 1;i <= n; ++i) {
		scanf("%d",&a[i]);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	R = v.size();
	for(register int i = 1;i <= n; ++i)
		update(root[i - 1],root[i],1,R,getid(a[i]),1);
	for(register int T = 1,l,r,k;T <= m; ++T) {
		scanf("%d%d%d",&l,&r,&k);
		int V = (r - l + 1) / k;
		int pos = query(root[l - 1],root[r],1,R,V);
		if(pos == -1) puts("-1");
		else printf("%d\n",v[pos - 1]);
	}
	return 0;
}