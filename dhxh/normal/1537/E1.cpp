#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e6 + 5;
const int maxlog = 20;
struct Suffix_Array {
	char s[maxn];
	int sa[maxn], rank[maxn], height[maxn];
	int t[maxn], t2[maxn], c[maxn], n;
	void init(char *str) {
		strcpy(s, str);
		n = strlen(s);
		memset(t, 0, sizeof(int) * (2 * n + 10));
		memset(t2, 0, sizeof(int) * (2 * n + 10));
	}
	void build_sa(int m = 256) {
		int *x = t, *y = t2;
		for (int i = 0; i < m; ++i) c[i] = 0;
		for (int i = 0; i < n; ++i) c[x[i] = s[i]]++;
		for (int i = 1; i < m; ++i) c[i] += c[i - 1];
		for (int i = n - 1; i >= 0; --i) sa[--c[x[i]]] = i;
		for (int k = 1; k <= n; k <<= 1) {
			int p = 0;
			for (int i = n - 1; i >= n - k; --i) y[p++] = i;
			for (int i = 0; i < n; ++i) if (sa[i] >= k) y[p++] = sa[i] - k;
			for (int i = 0; i < m; ++i) c[i] = 0;
			for (int i = 0; i < n; ++i) c[x[y[i]]]++;
			for (int i = 1; i < m; ++i) c[i] += c[i - 1];
			for (int i = n - 1; i >= 0; --i) sa[--c[x[y[i]]]] = y[i];
			swap(x, y);
			p = 1; x[sa[0]] = 0;
			for (int i = 1; i < n; ++i)
				x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++; //(1)
			if (p >= n) break;
			m = p;
		}
		for (int i = 0; i < n; ++i) rank[sa[i]] = i;
	}
}arr;

int n, m;
char str[maxn];

int main(){
	int i, j;
	
	scanf("%d%d", &n, &m);
	scanf("%s", str);
	for(i=0;i<n;i++) str[i + n] = str[i];
	
	arr.init(str);
	arr.build_sa();
	
	for(i=1;i<n;i++){
		if(arr.rank[i] > arr.rank[0]){
			break;
		}
	}
	
	for(j=0;j<m;j++){
		printf("%c", str[j % i]);
	}
	printf("\n");
	
	return 0;
}