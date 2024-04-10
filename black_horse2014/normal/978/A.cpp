#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
const int maxv = 1100;
int a[maxn], flag[maxv];
int n, na[maxn];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int ind = 0;
	for(int i = n - 1; i >= 0; i--){
		if(!flag[a[i]]){
			flag[a[i]] = 1;
			na[ind++] = a[i];
		}
	}
	printf("%d\n", ind);
	for(int i = ind - 1; i >= 0; i--)
		printf("%d%c", na[i], i > 0 ? ' ' : '\n');
	return 0;
}