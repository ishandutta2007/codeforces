#include <bits/stdc++.h>
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;
vector<int> rmq, v, p;
void build(int i, int l, int r){
	if (r-l==1){
		rmq[i] = v[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*i+1, l, mid);
	build(2*i+2, mid, r);
	rmq[i] = min(rmq[2*i+1], rmq[2*i+2]);
}
void push(int i, int l, int r){
	if (r-l <= 1) return;
	int P = p[i];
	p[i] = 0;
	rmq[2*i+1] += P, rmq[2*i+2]+=P, p[2*i+1]+=P, p[2*i+2]+=P;
}
int get(int i, int l, int r){
	push(i, l, r);
	if (r-l==1) return l;
	int mid = (l+r)/2;
	if (rmq[2*i+2] <= rmq[2*i+1]){
		return get(2*i+2, mid, r);
	}
	return get(2*i+1, l, mid);
}
void change(int i, int l, int r, int l1, int r1, int v){
	push(i, l, r);
	if (l1 >= r1) return;
	if (l==l1 && r==r1){
		rmq[i]+=v, p[i]+=v;
		return;
	}
	int mid = (l+r)/2;
	change(2*i+1, l, mid, l1, min(r1, mid), v);
	change(2*i+2, mid, r, max(l1, mid), r1, v);
	rmq[i] = min(rmq[2*i+1], rmq[2*i+2]);
}
main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	v.assign(n, -1);
	for (int i=0; i < n; i++) cin >> v[i];
	rmq.assign(4*n, -1);
	p.assign(4*n, 0);
	build(0, 0, n);
	vector<int> ans(n);
	for (int i=0; i < n; i++){
		int index = get(0, 0, n);
		ans[index] = i+1;
		change(0, 0, n, index, index+1, 1e18);
		change(0, 0, n, index+1, n, -(i+1));
		//cout << rmq[2] << endl;
	}
	for (int i=0; i < n; i++) cout << ans[i] << " ";
}