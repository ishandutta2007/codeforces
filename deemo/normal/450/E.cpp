#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAX = 1e6 + 10;

int n;
vector<pair<int, int>>	ans;
vector<int>	vec, sec;
bool pr[MAX];
bool mark[MAX];

int main(){
	cin >> n;
	pr[1] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = i + i; j <= n; j += i)
			pr[j] = 1;

	for (int i = n; i > 1; i--)
		if (!pr[i] && 2 * i <= n){
			sec.clear();
			for (int j = i; j <= n; j += i)
				if (!mark[j])
					sec.push_back(j);

			if ((int)sec.size() % 2 == 1)
				sec.erase(find(sec.begin(), sec.end(), 2 * i));

			for (int j = 0; j < sec.size(); j += 2){
				ans.push_back({sec[j], sec[j + 1]});
				mark[sec[j]] = mark[sec[j + 1]] = 1;
			}
		}
	for (int i = 2; i <= n; i++)
		if (!mark[i] && i % 2 == 0)
			vec.push_back(i);

	for (int i = 1; i < vec.size(); i++)
		ans.push_back({vec[i], vec[i - 1]});

	cout << ans.size() << "\n";
	for (pair<int, int>	v:ans)
		cout << v.first << " " << v.second << "\n";
	return	0;	
}