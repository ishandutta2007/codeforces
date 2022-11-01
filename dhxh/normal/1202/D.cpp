#include <bits/stdc++.h>

using namespace std;

int n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		string ans = "1";
		vector <int> vec;
		while(n){
			long long x = sqrt(n);
			while((x + 1) * x / 2 <= n)x++;
			n -= (x - 1) * x / 2;
			vec.push_back(x);
		}
		sort(vec.begin(), vec.end());
		j = 1;
		for(auto i : vec){
			for(;j<=i;j++)ans.push_back('3');
			ans.push_back('7');
		}
		cout << ans << endl;
	}
	
	return 0;
}