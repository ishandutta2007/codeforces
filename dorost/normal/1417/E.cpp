#pragma GCC target ("avx2,sse")
#pragma GCC optimization ("O3,Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 300001, L = 31;
int a[N];
bool b[N][L], ans[L];
int c[N], d[N], p2[L] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824}, e[N], temp[N];

ll _mergeSort(int left, int right); 
ll merge(int left, int mid, int right); 

long long cnt(int array_size) { 
	return _mergeSort(0, array_size - 1); 
} 

long long _mergeSort(int left, int right) { 
	int mid;
	ll inv_count = 0; 
	if (right > left) { 
		mid = (right + left) / 2; 
		inv_count += _mergeSort(left, mid) + _mergeSort(mid + 1, right) + merge(left, mid + 1, right); 
	} 
	return inv_count; 
} 

long long merge(int left, int mid, int right) { 
	int i, j, k; 
	long long inv_count = 0; 
	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) { 
		if (e[i] <= e[j]) { 
			temp[k++] = e[i++]; 
		} 
		else { 
			temp[k++] = e[j++]; 
			inv_count = inv_count + (ll)(mid - i); 
		} 
	} 
	while (i <= mid - 1) 
		temp[k++] = (ll)e[i++]; 
	while (j <= right) 
		temp[k++] = (ll)e[j++]; 
	for (i = left; i <= right; i++) 
		e[i] = temp[i]; 
	return inv_count; 
} 

ll _mergeSort2(int left, int right); 
ll merge2(int left, int mid, int right); 

long long cnt2(int array_size) { 
	return _mergeSort2(0, array_size - 1); 
} 

long long _mergeSort2(int left, int right) { 
	int mid;
	ll inv_count = 0; 
	if (right > left) { 
		mid = (right + left) / 2; 
		inv_count += _mergeSort2(left, mid) + _mergeSort2(mid + 1, right) + merge2(left, mid + 1, right); 
	} 
	return inv_count; 
} 

long long merge2(int left, int mid, int right) { 
	int i, j, k; 
	long long inv_count = 0; 
	i = left;
	j = mid;
	k = left;
	while ((i <= mid - 1) && (j <= right)) { 
		if (c[i] <= c[j]) { 
			temp[k++] = c[i++]; 
		} else { 
			temp[k++] = c[j++]; 
			inv_count = inv_count + (ll)(mid - i); 
		} 
	} 
	while (i <= mid - 1) 
		temp[k++] = (ll)c[i++]; 
	while (j <= right) 
		temp[k++] = (ll)c[j++]; 
	for (i = left; i <= right; i++) 
		c[i] = temp[i]; 
	return inv_count; 
}

int32_t main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
		d[i] = a[i];
		int x = a[i];
		int j = 0;
		while (x) {
			b[i][j] = x % 2;
			x >>= 1;
			j++;
		}
	}
	for (int i = L - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			e[j] = d[j];
		}
		ll a1 = cnt(n);
		for (int j = 0; j < n; j++) {
			if (b[j][i]) {
				d[j] -= p2[i];
			} else {
				d[j] += p2[i];
			}
		}
		for (int j = 0; j < n; j++) {
			e[j] = d[j];
		}
		ll a2 = cnt(n);
		ans[i] = !(a1 <= a2);
	}
	int x = 0;
	reverse(ans, ans + L);
	for (int i = 0; i < L; i++) {
		x <<= 1;
		if (ans[i])
			x++;
	}
	for (int i = 0; i < n; i++) {
		c[i] = a[i] ^ x;
	}
	printf("%lld %d", cnt2(n), x);
}