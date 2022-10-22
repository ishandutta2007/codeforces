#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;	

int a = 111991, b = 1112129;

int query(int c, int d) {
	printf("? %d %d\n", c, d);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
	/*if((a ^ c) > (b ^ d))
		return 1;
	if((a ^ c) == (b ^ d))
		return 0;
	if((a ^ c) < (b ^ d))
		return -1;
	*/
	assert(0);
}

int res[2];
int r0;
int r1;

int equal(int b) {
	for(int i = b; 0 <= i; --i) {
		if(query(((1 << i) | r0), r1) == 1) {
			;
		}
		else {
			res[0] += (1 << i);
			res[1] += (1 << i);
		}
	}
	printf("! %d %d", res[0], res[1]);
	exit(0);
}
			
int main() {
	int k = query(0, 0);
	if(k == 0) {
		equal(29);
	}
	int i;
	r0 = 0;
	r1 = 0;
	for(i = 29; 0 <= i; --i) {
		int z = query(((1 << i) | r0), ((1 << i) | r1));
		if(z == k) {
			if(k == 1) {
				z = query(((1 << i) | r0), r1);
				if(z == -1) {
					res[0] += (1 << i);
					res[1] += (1 << i);
				}
				else {
					;
				}
			}
			else {
				z = query(r0, ((1 << i) | r1));
				if(z == 1) {
					res[0] += (1 << i);
					res[1] += (1 << i);
				}
				else {
					;
				}
			}
		}
		else {
			if(k == 1) {
				res[0] += (1 << i);
				r1 |= (1 << i);
			}
			else {
				res[1] += (1 << i);
				r0 |= (1 << i);
			}
			k = query(r0, r1);
			if(k == 0) {
				equal(i - 1);
			}
		}
	}
	equal(i);
	
	
	return 0;
}