#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> arr;

int main (int argc, char *argv[])
{
	scanf("%d%d", &n, &k);
	arr.resize(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end());
	int ans = 0;
	for(int i = 0; i < k; ++i) {
		ans += arr[i];
	}
	printf("%d", ans);
	
	return 0;
}