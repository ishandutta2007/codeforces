#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5, MX = 1e5+2;
struct Node {
	Node *lc, *rc;
	int mx;
	Node () {lc = rc = NULL; mx = 0;}
} *seg[MN];
void update (Node *&root, int tl, int tr, int i, int v) {
	if (!root) root = new Node();
	if (tl == tr) return (void) (root->mx = max(root->mx,v));
	int mid = (tl + tr) / 2;
	if (i <= mid) update(root->lc,tl,mid,i,v); 
	else update(root->rc,mid+1,tr,i,v);
	root->mx = max(root->lc?root->lc->mx:0,root->rc?root->rc->mx:0);
}
int query (Node *root, int tl, int tr, int l, int r) {
	if (tl > r || tr < l || !root) return 0;
	if (tl >= l && tr <= r) return root->mx;
	int mid = (tl + tr) / 2;
	return max(query(root->lc,tl,mid,l,r),query(root->rc,mid+1,tr,l,r));
}
int main() {
	int n,m;
	scanf ("%d %d",&n,&m);
	int ans = 0;
	while (m--) {
		int a,b,c;
		scanf ("%d %d %d",&a,&b,&c); ++c;
		int can = query(seg[a],1,MX,1,c-1) + 1;
		ans = max(ans,can);
		update(seg[b],1,MX,c,can);
	}
	printf ("%d\n",ans);
    return 0;
}