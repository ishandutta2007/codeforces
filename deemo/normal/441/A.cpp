#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>	vec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, v;	cin >> n >> v;
	for (int i = 0; i < n; i++){
		int t;	cin >> t;
		int mini = 1e9;
		while (t--){
			int temp;	cin >> temp;
			mini = min(temp, mini);
		}
		if (mini < v)	vec.push_back(i + 1);
	}
	sort(vec.begin(), vec.end());
	cout << vec.size() << endl;
	for (int v:vec)
		cout << v << " ";
	cout << endl;
	return	0;
}