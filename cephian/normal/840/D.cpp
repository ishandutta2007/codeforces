#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;


const int N = 3e5+5, k = 5;
int A[N];

//pass in 0-indexed array A of length n to constructor
template <class T>
struct elem_freq {
	unordered_map<T,vector<int> > idx;
	vector<T> v;
	
	void build(T* A, int n) {
		v = vector<T>(n,0);
		idx.clear();
		for(int i = 0; i < n; ++i) {
			v[i] = A[i];
			idx[A[i]].push_back(i);
		}
	}

	// finds the number of x's in [l,r] in O(log n)
	inline int in_range(T x, int l, int r) {
		if(r-l < 30) {
			int a=0;
			for(int i = l; i <= r; ++i)
				a+= v[i]==x;
			return a;
		}
		if(!idx.count(x)) return 0;
		const vector<int> &v = idx[x];
		if(v.back() < l || v[0] > r) return 0;
		int i=-1, k=v.size(),j=k-1;
		while(j-i>1) {
			int m = (i+j)/2;
			(v[m]<l?i:j)=m;
		}
		if(v[i=j]>r) return 0;
		while(k-i>1) {
			int m = (i+k)/2;
			(v[m]>r?k:i)=m;
		}
		return max(0,i-j+1);
	}
};

vector<int> segt[4*N];
int l[4*N],r[4*N];
elem_freq<int> e;

void build_st(int v, int i, int j) {
	l[v] = i, r[v] = j;
	if(i == j) {
		segt[v].pb(A[i]);
		return;
	}
	build_st(v*2,i,(i+j)/2);
	build_st(v*2+1,(i+j)/2+1,j);
	for(int a : segt[v*2])
		if(e.in_range(a,i,j) * k > j-i+1)
			segt[v].pb(a);
	for(int a : segt[v*2+1]) {
		bool ok = true;
		for(int b : segt[v*2])
			if(a == b) {
				ok = false;
				break;
			}
		if(ok && e.in_range(a,i,j) * k > j-i+1) {
			segt[v].pb(a);
		}
	}
	// for(int a : segt[v]) {
	// 	cout << "in " << i << " to " << j << " is " << a << endl;
	// }
}

set<int> all;

void query_st(int v, int i, int j) {
	// cout << v << " and " << l[v] << ", " << r[v] << endl;
	if(j < l[v] || r[v] < i) {
		return;
	}
	if(i <= l[v] && r[v] <= j) {
		for(int a : segt[v])
			all.insert(a);
		return;
	}
	//CHANGE ME
	query_st(v*2,i,j);
	query_st(v*2+1,i,j);
}

int query(int l, int r, int k) {
	// cout << l << " " << r << endl;
	all.clear();
	query_st(1,l,r);
	for(int a : all)
		if(e.in_range(a,l,r) * k > r-l+1)
			return a;
	return -1;
}

int main() {	
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i = 0; i < n; ++i)
		scanf("%d",A+i);
	e.build(A,n);
	build_st(1,0,n-1);
	while(q--) {
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k),--l,--r;
		printf("%d\n",query(l,r,k));
	}
}