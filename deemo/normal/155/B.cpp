#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	vector<int>	vec;
	int n;	cin >> n;
	int ans = 0, cn = 1;
	while (n--){
		int a, b;	cin >> a >> b;
		if (b){
			cn += b - 1;
			ans += a;
		}
		else
			vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	while (vec.size() && cn){
		ans += vec.back();
		vec.pop_back();
		cn--;
	}
	cout << ans << "\n";
	return	0;
}