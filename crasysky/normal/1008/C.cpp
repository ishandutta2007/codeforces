#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[100005];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int ans = 0, p = 1;
	for (int i = 1; i <= n; ++ i){
		while (a[i] >= a[p] && p <= n)
			++ p;
		if (a[i] < a[p])
			++ ans, ++ p;
	}
	cout << ans << endl;
}