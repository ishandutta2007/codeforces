# include <bits/stdc++.h>
# define int long long
# define inf (1e14)
using namespace std;
const int N=1e6+10;
int n;
vector< pair<int,int> >v[N];
vector< int >tmp;
struct Seg {
	int ret,id,tag;
	Seg() { ret=-inf;}
}tr[N<<2];
struct node{ int l,r,w; }a[N];
# define lson ls,l,mid
# define rson rs,mid+1,r
# define mid (l+r>>1)
# define ls (x<<1)
# define rs (x<<1|1)
void up(int x) {
	tr[x].ret = max(tr[ls].ret,tr[rs].ret);
	if (tr[ls].ret < tr[rs].ret) tr[x].id = tr[rs].id;
	else tr[x].id = tr[ls].id;
}
void down(int x) {
	if (!tr[x].tag) return;
	tr[ls].tag+=tr[x].tag; tr[ls].ret+=tr[x].tag;
	tr[rs].tag+=tr[x].tag; tr[rs].ret+=tr[x].tag;
	tr[x].tag=0;
}
void build(int x,int l,int r) {
	if (l==r) { tr[x].ret = -tmp[l-1],tr[x].id=l; return;}
	build(lson); build(rson);
	up(x);
}
void update(int x,int l,int r,int opl,int opr,int d) {
	if (opl<=l&&r<=opr) {
		tr[x].tag+=d; tr[x].ret+=d;
		return;
	}
	down(x);
	if (opl<=mid) update(lson,opl,opr,d);
	if (opr>mid) update(rson,opl,opr,d);
	up(x);
}
pair<int,int> query(int x,int l,int r,int opl,int opr) {
	if (opl<=l && r<=opr) {
		return make_pair(tr[x].ret,tr[x].id);
	}
	down(x);
	pair<int,int> ret = make_pair(-inf,-1);
	if (opl<=mid) ret = max(ret,query(lson,opl,opr));
	if (opr>mid) ret= max(ret,query(rson,opl,opr));
	return ret;
}
signed main() {
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) {
		int x,y,c; scanf("%lld%lld%lld",&x,&y,&c);
		tmp.push_back(x); tmp.push_back(y);
		a[i] = (node) {min(x,y),max(x,y),c};
	}
	int T = 0;
	sort(tmp.begin(),tmp.end());
	tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
	for (int i=1;i<=n;i++) {
		int l = lower_bound(tmp.begin(),tmp.end(),a[i].l) - tmp.begin() + 1;
		int r = lower_bound(tmp.begin(),tmp.end(),a[i].r) - tmp.begin() + 1;
		T=max(T,r);
		v[l].push_back(make_pair(r,a[i].w));
	}
	build(1,1,T);
	int ans = -inf,ansl,ansr;
	for (int i=T;i>=1;i--) {
		for (int j=0;j<v[i].size();j++) {
			pair<int,int> to = v[i][j];
			update(1,1,T,to.first,T,to.second);
		}
		pair<int,int>ret = query(1,1,T,i,T);
		ret.first +=tmp[i-1];
		if (ret.first > ans) {
			ans  = ret.first;
			ansl = tmp[i-1]; ansr = tmp[ret.second-1];
		}
	}
	if (ans < 0) {
		ans = 0; ansl=ansr=tmp[T-1]+1;
	}
	printf("%lld\n%lld %lld %lld %lld\n",ans,ansl,ansl,ansr,ansr);
	return 0;
}