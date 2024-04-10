#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n;
pair<int, int>	vec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;
	sort(vec, vec + n);
	for (int i = 0; i < n - 1; i++)
		if (vec[i].second > vec[i + 1].second){
			cout << "Happy Alex\n";
			return	0;
		}
	cout << "Poor Alex\n";
	return	0;	
}