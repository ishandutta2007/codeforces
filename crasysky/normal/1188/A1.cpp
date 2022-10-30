#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#define Pr pair <int, int>
#define fi first
#define se second
using namespace std;
const int maxn = 1000006;
int d[maxn];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i < n; ++ i){
		int u, v;
		scanf("%d %d", &u, &v);
		++ d[u], ++ d[v];
	}
	int c = 0;
	for (int i = 1; i <= n; ++ i)
		c += d[i] == 2;
	if (c >= 1)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}