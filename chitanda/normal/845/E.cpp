#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

struct line{
	int x, l, r, v;
	line(){}
	line(int x, int l, int r, int v) : x(x), l(l), r(r), v(v) {}
	bool operator < (const line &o) const{
		return x < o.x;
	}
};

int n, m, k;
int x[510], y[510];
int cnt[1010];

bool check(int d){
	vector<line> q;
	q.pb(line(1, 1, 1, 1));
	q.pb(line(n + 1, 1, 1, 1));
	vector<int> tq; 
	tq.pb(1); tq.pb(m + 1);
	for(int i = 1; i <= k; ++i){
		q.pb(line(max(1, x[i] - d), max(1, y[i] - d), min(y[i] + d + 1, m + 1), 1));
		q.pb(line(min(n + 1, x[i] + d + 1), max(1, y[i] - d), min(y[i] + d + 1, m + 1), -1));
		tq.pb(max(1, y[i] - d));
		tq.pb(min(y[i] + d + 1, m + 1));
	}
	sort(all(tq));
	tq.erase(unique(all(tq)), tq.end());
	sort(all(q));
	
	int L = n, R = 1, U = 1, D = m;
	//if(q[0].x > 1) L = 1, R = q[0].x - 1;
	//if(q[2 * k - 1].x < n) R = n, L = min(L, q[2 * k - 1].x + 1);
	
	memset(cnt, 0, sizeof(cnt));
	for(int i = 0, j = 0; i < q.size(); i = j){
		while(j < q.size() && q[j].x == q[i].x){
			int l = lower_bound(all(tq), q[j].l) - tq.begin();
			int r = lower_bound(all(tq), q[j].r) - tq.begin();
			for(int k = l; k < r; ++k) cnt[k] += q[j].v;
			j++;
		}
		if(q[i].x <= n)
			for(int k = 0; k < tq.size() - 1; ++k)
				if(cnt[k] == 0){
					U = max(U, tq[k + 1] - 1);
					D = min(D, tq[k]);
					R = max(R, q[j].x - 1);
					L = min(L, q[i].x);
				}
	}
	
	if(R - L <= 2 * d && U - D <= 2 * d) return 1;
	else return 0;
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= k; ++i)
		scanf("%d%d", x + i, y + i);
	
	int l = -1, r = max(n, m);
	while(l + 1 < r){
		int d = l + (r - l) / 2;
		if(check(d)) r = d;
		else l = d;
	}
	printf("%d\n", r);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}