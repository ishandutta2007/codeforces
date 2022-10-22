//As a child, You would wait
//And watch from far away
//But you always knew that you'd be the one 
//To work while they all play..

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;
const int LOG = 30 + 1;

int n, q;
int weed[4 * MAXN], ans[MAXN], le[MAXN], ri[MAXN], val[MAXN];

void sprout(int v){	weed[v] = weed[v<<1] & weed[v<<1^1];}

void plant(int v, int b, int e, int x = 0){
	x |= weed[v];
	if (e - b == 1){
		weed[v] = x;
		ans[b] = x;
		return;
	}

	int mid = (b + e)/ 2;
	plant(v<<1, b, mid, x);
	plant(v<<1^1, mid, e, x);
	sprout(v);
}	

void water(int v, int b, int e, int l, int r, int x){
	if (l <= b && e <= r){
		weed[v] |= x;
		return;
	}
	if (r <= b || e <= l)	return;

	int mid = (b + e)/ 2;
	water(v<<1, b, mid, l, r, x);
	water(v<<1^1, mid, e, l, r, x);
}

int smoke(int v, int b, int e, int l, int r){
	if (l <= b && e <= r)	return	weed[v];
	if (r <= b || e <= l)	return	(1 << 30) - 1;

	int mid = (b + e)/ 2;
	return	smoke(v<<1, b, mid, l, r) & smoke(v<<1^1, mid, e, l, r);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < q; i++){
		int l, r, x;	cin >> l >> r >> x;	l--;
		le[i] = l;	ri[i] = r;	val[i] = x;
		water(1, 0, n, l, r, x);
	}	
	plant(1, 0, n);

	for (int i = 0; i < q; i++)
		if (smoke(1, 0, n, le[i], ri[i]) != val[i]){
			cout << "NO\n";
			return	0;
		}
	cout << "YES\n";
	for (int i = 0; i < n; i++)	
		cout << ans[i] << " ";
	cout << "\n";
	return	0;
}