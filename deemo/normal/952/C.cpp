#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 10 + 3;

int n;
vector<int> vec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vec.resize(n);
	for (int i = 0; i < n; i++) cin >> vec[i];
	vector<int> sec;
	sec.assign(vec.begin(), vec.end());
	sort(sec.begin(), sec.end());
	for (int i = 0; i +1 < sec.size(); i++)
		if (sec[i+1] - sec[i] > 1){
			cout << "NO\n";
			return 0;
		}
	while (vec.size()){
		for (int i = 0; i +1 < vec.size(); i++)
			if (abs(vec[i+1] - vec[i]) > 1){
				cout << "NO\n";
				return 0;
			}
		int mx = max_element(vec.begin(), vec.end()) - vec.begin();
		vec.erase(vec.begin()+mx);
	}
	cout << "YES\n";
	return 0;
}