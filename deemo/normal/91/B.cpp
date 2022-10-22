#include<bits/stdc++.h>

using namespace std;

#define pb(x) push_back(x)

int n;
vector<int>	vec, ans;
vector<pair<int, int>>	sec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];	


	for (int i = n - 1; i >= 0; i--){
		int x = vec[i];
		{
			int b = 0, e = sec.size() - 1, mid, ret = sec.size();
			while (b <= e){
				mid = (b + e)/ 2;
				if (sec[mid].first < x){
					e = mid - 1;
					ret = mid;
				}
				else	b = mid + 1;
			}
			
			if (ret == sec.size())
				ans.pb(-1);
			else
				ans.pb(sec[ret].second - i - 1);
		}
		if (!sec.empty() && sec.back().first < x)	continue;
		sec.push_back({x, i});
	}
	

	for (int i = n - 1; i >= 0; i--)
		cout << ans[i] << ' ';
	cout << "\n";
	return 0;
}