#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cmath>
#include<string>

using namespace std;

const int max_n = 1e5 + 100;

string s;
int n, z[max_n];
vector<int>	vec;
vector<pair<int, int>>	ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.size();

	int L = 0, R = 0;
	for (int i = 1; i < n; i++){
		if (R < i){
			L = R = i;
			while (R < n && s[R] == s[R - i])	R++;
			R--;
			z[i] = R - i + 1;
		}
		else{
			if (z[i - L] < R - i)	z[i] = z[i - L];
			else{
				L = i;
				while (R < n && s[R] == s[R - i])	R++;
				R--;
				z[i] = R - i + 1;
			}
		}
		vec.push_back(z[i]);
	}
	sort(vec.begin(), vec.end());
	
	for (int i = 1; i < n; i++){
		if (z[n - i] != i)	continue;
		int t = lower_bound(vec.begin(), vec.end(), i) - vec.begin();
		t = n - 1 - t;
		ans.push_back({i, t + 1});
	}
	ans.push_back({n, 1});
	cout << ans.size() << endl;
	for (pair<int, int> u:ans)
		cout << u.first << " " << u.second << "\n";
	return 0;
}