#include<bits/stdc++.h>
#define LL long long
using namespace std;

int N; LL W, H;
struct node {
	int opt, id; LL p, t;
	bool operator < (const node b) const {
		if(p != b.p) return p < b.p;
		if(t != b.t) return t < b.t;
		return opt < b.opt;
	}
} A[100005];
int ans[100005];
LL val[100005]; int lv;
vector<int> ID1[100005], ID2[100005];
int lis[100005], ll;

int main() {
//	freopen("ex_bridge2.in", "r", stdin);
//	freopen("WA.out", "w", stdout);
	scanf("%d%lld%lld", &N, &W, &H);
	for(int i = 1; i <= N; i++) {
		A[i].id = i;
		scanf("%d%lld%lld", &A[i].opt, &A[i].p, &A[i].t);
		A[i].opt = 3 - A[i].opt;
		val[++lv] = A[i].p - A[i].t;
	}
	sort(A + 1, A + N + 1);
	sort(val + 1, val + lv + 1); lv = unique(val + 1, val + lv + 1) - val - 1;
	for(int i = 1; i <= N; i++) {
		int pos = lower_bound(val + 1, val + lv + 1, A[i].p - A[i].t) - val;
		if(A[i].opt == 1) ID1[pos].push_back(i);
		else ID2[pos].push_back(i);
	}
	for(int i = 1; i <= lv; i++) {
		ll = 0;
		for(int j = ID1[i].size() - 1; j >= 0; j--)
			lis[ll++] = ID1[i][j];
		for(int j = 0; j < ID2[i].size(); j++)
			lis[ll++] = ID2[i][j];
		for(int j = 0; j < ll; j++)
			ans[A[lis[j]].id] = lis[(j + ID1[i].size()) % ll];
	}
	for(int i = 1; i <= N; i++) {
		int u = ans[i];
		if(A[u].opt == 1) printf("%lld %lld\n", W, A[u].p);
		else printf("%lld %lld\n", A[u].p, H);
	}
}