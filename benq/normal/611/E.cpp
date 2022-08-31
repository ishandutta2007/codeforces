#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
int n,a,b,c,cr, ans=0, sum, nc[7];

void place(int k) {
	if (k <= a) nc[0] ++;
	else if (k <= b) nc[1] ++; // min(a+b,c)
	else if (k <= min(a+b,c)) nc[2] ++; // max(a+b,c)
	else if (k <= max(a+b,c)) nc[3] ++; // a+c
	else if (k <= a+c) nc[4]++; // b+c
	else if (k <= b+c) nc[5]++;
	else nc[6] ++;
}

int remove(int ind, int val) {
	if (val <= nc[ind]) {
		nc[ind] -= val;
		return val;
	} else {
		int z = nc[ind];
		nc[ind] = 0;
		if (ind) return z+remove(ind-1,val-z);
		else return z;
	}
}

int main() {
	scanf("%d%d%d%d",&n,&a,&b,&c);
	sum = a+b+c;
	if (a>b) swap(a,b);
	if (b>c) swap(b,c);
	if (a>b) swap(a,b);
	F0R(i,n) {
		scanf("%d",&cr);
		if (cr>sum) {
			cout << -1;
			return 0;
		}
		place(cr);
	}	
	ans += nc[6], nc[6] = 0; // a,b,c work together
	ans += nc[5], remove(0,nc[5]), nc[5] = 0; // b,c work together
	ans += nc[4], remove(1,nc[4]), nc[4] = 0; // a,c work together
	if (c >= a+b) {
		while (1) {
			int k = remove(1,1)+remove(0,1);
			if (!k) break;
			remove(3,1), ans++;
		}
		while (nc[2] || nc[3]) remove(2,1), remove(3,1), ans++;
	} else {
		remove(2,nc[3]), ans += nc[3], nc[3] = 0;
		while (1) {
			int k = remove(0,1)+remove(1,1);
			if (!k) break;
			remove(2,1), ans ++;
		}
		while (nc[2] || nc[3]) remove(2,1), remove(3,1), ans++;
	}
	cout << ans;
}