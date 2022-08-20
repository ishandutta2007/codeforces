#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int seg[1<<21],el[1000001],ans[1000001],cum[1000001],n,m;
pair<pii,int> q[1000001];
unordered_map<int,int> last;

void update(int ind, int l, int r, int d, int v) {
	if (l>d || r<d) return;
	if (l == d && r == d) {
		seg[ind] = v;
		return;
	}
	int m = (l+r)/2;
	update(2*ind,l,m,d,v);
	update(2*ind+1,m+1,r,d,v);
	seg[ind] = seg[2*ind]^seg[2*ind+1];
}

int query(int ind, int l, int r, int left, int right) {
	if (l>right || r<left) return 0;
	if (left <= l && r <= right) return seg[ind];
	int m = (l+r)/2;
	return query(2*ind,l,m,left,right)^query(2*ind+1,m+1,r,left,right);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	scanf("%d",&n);
	FOR(i,1,n+1) {
		scanf("%d",&el[i]);
		cum[i] = cum[i-1]^el[i];
	}
	scanf("%d",&m);
	F0R(i,m) {
		scanf("%d%d",&q[i].f.s,&q[i].f.f);
		q[i].s = i;
	}
	sort(q,q+m);
	
	int cur = 1;
 	F0R(i,m) {
		while (cur<=q[i].f.f) {
			if (last[el[cur]]) update(1,1,n,last[el[cur]],0);
			last[el[cur]] = cur;
			update(1,1,n,cur,el[cur]);
			cur++;
		}
		ans[q[i].s] = cum[q[i].f.s-1]^cum[q[i].f.f]^query(1,1,n,q[i].f.s,q[i].f.f);
	}
    F0R(i,m) printf("%d\n",ans[i]);
}