#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int a[1003];
bool tag[1003];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n; ++ i)
		if (! tag[i]){
			++ ans;
			for (int j = i; j <= n; ++ j)
				if (a[j] % a[i] == 0)
					tag[j] = true;
		}
	cout << ans << endl;
}