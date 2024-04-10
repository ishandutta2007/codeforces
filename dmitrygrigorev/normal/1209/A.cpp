#include <bits/stdc++.h>
#define ll long long
 
using namespace std;


int main()
{
	#ifdef LOCAL
	    freopen("H_input.txt", "r", stdin);
	    //freopen("B_output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i < n; i++) cin >> v[i];
	int ans = 0;
	while (v.size()){
		sort(v.begin(), v.end());
		vector<int> t;
		ans++;
		for (int i=0; i < v.size(); ++i){
			if (v[i] % v[0] != 0) t.push_back(v[i]);
		}
		v=t;
	}
	cout << ans;
	

}