#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#define maxn 100009
using namespace std;
int a[maxn];
int main(){
	int n;
	cin >> n;
	int mi = 1e9 + 7;
	int ma = -1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mi = min(mi, a[i]);
		ma = max(ma, a[i]);
	}
	int ans = 0;
	for(int i = 1;i <= n; i++){
		if(a[i] != mi && a[i] != ma)
		ans++;
	}
	cout << ans << endl;
	return 0;
}