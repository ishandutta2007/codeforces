#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int get(vector<pair<int, int>>	vec, int n, int c){
	int ret = 0, cur = 0;
	for (int i = 0; i < n; i++){
		cur += vec[i].second;
		ret += max(0, vec[i].first - cur * c);	
	}
	return	ret;
}

int main(){
	int n, c;	cin >> n >> c;
	vector<pair<int, int>>	vec(n);
	for (int i = 0; i < n; i++)	cin >> vec[i].first;
	for (int i = 0; i < n; i++)	cin >> vec[i].second;
	int a = get(vec, n, c);
	reverse(vec.begin(), vec.end());
	int b = get(vec, n, c);
	if (a > b)
		cout << "Limak\n";
	else if (b > a)
		cout << "Radewoosh\n";
	else
		cout << "Tie\n";
	return	0;
}