#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

int n, m, ans;
vector<int>	vec, atk, def, sec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		string type;	int x;	cin >> type >> x;
		if (type == "ATK")	atk.push_back(x);
		else	def.push_back(x);
	}
	vec.resize(m);
	for (int i = 0; i < m; i++)	cin >> vec[i];
	sort(atk.begin(), atk.end());
	sort(def.begin(), def.end());
	sort(vec.begin(), vec.end());
	
	for (int i = 1; i <= atk.size(); i++){
		int ret = 0;
		bool fl = 0;
		if (vec.size() < i)	break;
		sec.assign(vec.begin(), vec.end());
		for (int j = i - 1; j >= 0; j--){
			int dif = sec.back() - atk[j];
			if (dif < 0){
				fl = 1;
				break;
			}
			ret += dif;
			sec.pop_back();
		}
		if (fl)	break;
		ans = max(ans, ret);
	}

	if (n >= m){
		cout << ans << endl;
		return 0;
	}

	for (int i = 0; i < def.size(); i++)
		for (int j = 0; j < vec.size(); j++)
			if (vec[j] > def[i]){
				vec.erase(vec.begin() + j);
				break;
			}

	bool fl = 0;
	int ret = 0;
	for (int i = atk.size() - 1; i >= 0; i--){
		int dif = vec.back() - atk[i];
		if (dif < 0){
			fl = 1;
			break;
		}
		ret += dif;
		vec.pop_back();
	}
	for (int i = 0; i < vec.size(); i++)
		ret += vec[i];
	if (!fl)	ans = max(ans, ret);

	cout << ans << endl;
	return 0;
}