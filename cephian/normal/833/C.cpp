#include <bits/stdc++.h>
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long ll;

ll a,b;
// int dig[20];
int len = 0;
int A[20], B[20], C[20], ans=0;
int f[10], tf[10], uf[10];

void search(int l, int lb) {
	for(int i = 0; i <= 9; ++i)
		tf[i] = f[i];
	bool ok = true;
	for(int i = len-1; i >= 0; --i) {
		if(A[i] == B[i]) {
			if(!tf[A[i]]) {
				ok = false;
				break;
			} else {
				--tf[A[i]];
				continue;
			}
		}
		for(int d = A[i]+1; d < B[i]; ++d)
			if(tf[d])
				goto skp;
		for(int d = 0; d <= 9; ++d)
			uf[d] = tf[d];
		ok = false;
		if(tf[A[i]]) {
			ok = true;
			--tf[A[i]];
			int cur = 9;
			for(int j = i-1; j >= 0; --j) {
				while(!tf[cur]) --cur;
				if(cur < A[j]) {
					ok = false;
					break;
				}
				if(cur > A[j])
					break;
				--tf[cur];
			}
		}
		if(ok) break;
		swap(uf,tf);
		if(tf[B[i]]) {
			ok = true;
			--tf[B[i]];
			int cur = 0;
			for(int j = i-1; j >= 0; --j) {
				while(!tf[cur]) ++cur;
				if(cur > B[j]) {
					ok = false;
					break;
				}
				if(cur < B[j])
					break;
				--tf[cur];
			}
		}
		break;
	}
	skp:;
	ans += ok;
	if(l+1 <= len) {
		--f[0];
		for(int d = lb; d <= 9; ++d)
			++f[d], search(l+1,d), --f[d];
		++f[0];
	}
}

int main() {
	fio;	
	ll a,b;
	cin >> a >> b;
	ll pw = 0;
	while(a || b) {
		A[len] = a%10;
		B[len] = b%10;
		a/=10, b/=10;
		++len;
	}
	f[0] = len;
	search(0,1);
	printf("%d\n",ans);
}