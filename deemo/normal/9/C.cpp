#include<bits/stdc++.h>

using namespace std;

int get(int mask){
	int ret = 0, cur = 1;
	while (mask){
		if (mask&1)
			ret += cur;
		cur *= 10;
		mask>>=1;
	}
	return ret;
}

int main(){
	int n;	cin >> n;
	int ans = 0;
	for (int i = 1; i < 1<<10; i++)
		if (get(i) <= n)	ans++;
	cout << ans << endl;
	return 0;
}