#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int n;
vector<int>	vec, ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	
	vec.resize(n);
	for (int i = 0; i < n; i++)	cin >> vec[i];
	ans.push_back(vec[0]);
	int lst = vec[0];
	for (int i = 1; i < n; i++){
		if (__gcd(vec[i], lst) == 1){
			ans.push_back(vec[i]);
			lst = vec[i];
			continue;
		}

		ans.push_back(1);
		lst = vec[i];
		ans.push_back(vec[i]);
	}
	cout << ans.size() - n << "\n";
	for (int v:ans)
		cout << v << " ";
	cout << "\n";
	return	0;
}