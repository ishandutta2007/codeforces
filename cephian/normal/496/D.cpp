#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;
int a[N]={0},b[N]={0},w,n;


const int INF  = 1e9;
int find(int* A, int lo, int hi, int v) {
	while(hi-lo-1) {
		int md = (lo+hi)/2;
		((A[md]<v)?lo:hi) = md;
	}
	if(A[hi] != v) return INF;
	return hi;
}

int test(int t) {
	int p = 0;
	int aw=0,bw=0;
	while(p < n) {
		int ap = find(a,p,n+1,a[p]+t);
		int bp = find(b,p,n+1,b[p]+t);
		if(ap == INF && bp == INF) return -1;
		p = min(ap,bp);
		aw += ap==p;
		bw += bp==p;
	}
	if(aw == bw) return -1;
	if((aw > bw) != (a[n] > a[n-1])) return -1;
	return max(aw,bw);
}

vector<pii> ans;

int main() {
	scanf("%d",&n);

	for(int i = 1; i <= n; ++i) {
		scanf("%d",&w);
		a[i] = a[i-1] + (w==1);
		b[i] = b[i-1] + (w==2);
	}
	for(int t = 1; t <= n; ++t) {
		int s = test(t);
		if(s != -1) {
			ans.emplace_back(s,t);
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",(int)ans.size());
	for(int i = 0; i < ans.size(); ++i) {
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}