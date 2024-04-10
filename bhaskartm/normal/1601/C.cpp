#include<bits/stdc++.h>
using namespace std;
 
#define st first
#define nd second
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int N = 1e6 + 5;
 
int n, m, a[N], b[N], t, ans[N], c[2 * N], eq[2 * N];
ll bt[2 * N];
pii d[2 * N];
 
void ded(int l1, int r1, int l2, int r2){
	if(l2 > r2)
		return;
	int mid = (l2 + r2) / 2;
	int pb = l1;
	ll cl = 0, cg = 0, claux = 0, cgaux = 0;
	for(int i = l1; i < r1; i++)
		cgaux += (a[i] < b[mid]);
	cg = cgaux;
	for(int i = l1 + 1; i <= r1; i++){
		if(a[i - 1] < b[mid])
			cgaux--;
		if(a[i - 1] > b[mid])
			claux++;
		if(cgaux + claux < cg + cl){
			pb = i;
			cg = cgaux;
			cl = claux;
		}
	}
	ans[mid] = pb;
	ded(l1, pb, l2, mid - 1);
	ded(pb, r1, mid + 1, r2);
}
 
ll get(int p){
	ll r = 0;
	while(p){
		r += bt[p];
		p -= p & (-p);
	}
	return r;
}
 
void ins(int p){
	while(p <= n + m){
		bt[p]++;
		p += p & (-p);
	}
}
 
ll cnt(){
	ll r = 0;
	for(int i = 0; i < n + m; i++)
		d[i] = {c[i], i};
	sort(d, d + n + m);
	for(int i = 0; i < n + m; i++)
		eq[d[i].nd] = i + 1;
	for(int i = 0; i < n + m; i++){
		r += i - get(eq[i]);
		ins(eq[i]);
	}
	return r;
}
 
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i <= n + m; i++)
			bt[i] = 0;
		for(int i = 0; i < m; i++)
			scanf("%d", &b[i]);
		sort(b, b + m);
		ded(0, n, 0, m - 1);
		int l = 0;
		for(int i = 0; i < n; i++){
			while(l < m && ans[l] == i){
				c[i + l] = b[l];
				l++;
			}
			c[i + l] = a[i];
		}
		while(l < m){
			c[n + l] = b[l];
			l++;
		}
		printf("%lld\n", cnt());
	}
	return 0;
}