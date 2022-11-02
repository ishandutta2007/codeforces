#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;
int main(){
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int ans1 = d / t + 1;
	
	int res = max(0, n - ans1 * k);
	if(res > 0)
		puts("YES");
	else
		puts("NO");
	return 0;
}