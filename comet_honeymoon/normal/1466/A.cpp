#include<bits/stdc++.h>
using namespace std;

int T, n;
int X[55];
set<int> hsh;

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		hsh.clear();
		for(int i = 1; i <= n; i++) scanf("%d", &X[i]);
		for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			if(!hsh.count(X[j] - X[i])) hsh.insert(X[j] - X[i]);
		printf("%d\n", hsh.size());
	}
}