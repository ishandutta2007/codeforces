#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

template <class T>
struct range_leq {
	int N;
	vector<vector<T> > fen;
	range_leq(int *A, int n):N(n+1),fen(N) {
		for(int i = 1; i < N; ++i) {
			int p = 1;
			for(;!(p&i);p<<=1);
			for(;p;--p)
				fen[i].push_back(A[i-p]);
			sort(fen[i].begin(),fen[i].end());
		}
	}

	//# of elements with index <= i, and value <= v
	inline int prefix_query(int i, T v) {
		int ans = 0;
		for(++i;i;i^=i&-i) {
			int lo=-1,hi=fen[i].size();
			while(hi-lo!=1) {
				int md = (lo+hi)/2;
				(fen[i][md]<=v?lo:hi)=md;
			}
			ans += hi;
		}
		return ans;
	}

	inline int range_query(int l, int r, int v) {
		return prefix_query(r,v) - prefix_query(l-1,v);
	}

	inline int box_query(int l, int r, int w, int v) {
		return range_query(l,r,v) - range_query(l,r,w-1);
	}
};

const int N = 1e5+5;
int n,k,a[N],q,l,r,lk[N];
map<int,vi> m;

int main() {
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; ++i) {
		scanf("%d",a+i);
		m[a[i]].push_back(i);
	}
	for(auto p : m) {
		vi &v = p.second;
		for(int i = 0; i < v.size(); ++i) {
			if(i < k) lk[v[i]] = -1;
			else lk[v[i]] = v[i-k];
		}
	}
	range_leq<int> R(lk,n);
	int last = 0;
	scanf("%d",&q);
	while(q--) {
		scanf("%d%d",&l,&r);
		l = (l+last)%n;
		r = (r+last)%n;
		if(r < l) swap(l,r);
		last = R.range_query(l,r,l-1);
		printf("%d\n",last);
	}
	return 0;
}