#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

pair<int, int>	vec[4];
bool fl;

int main(){
	for (int i = 0; i < 3; i++)
		cin >> vec[i].first >> vec[i].second;

	if (vec[0].first == vec[1].first && vec[1].first == vec[2].first)	cout << 1 << endl, fl = 1;
	else if (vec[0].second == vec[1].second && vec[1].second == vec[2].second)	cout << 1 << endl, fl = 1;
	else{
		if (vec[0].first == vec[1].first && (vec[2].second <= min(vec[0].second, vec[1].second) || vec[2].second >= max(vec[0].second, vec[1].second)))	cout << 2 << endl, fl = 1;
		else if (vec[0].first == vec[2].first && (vec[1].second <= min(vec[0].second, vec[2].second) || vec[1].second >= max(vec[0].second, vec[2].second)))	cout << 2 << endl, fl = 1;
		else if (vec[1].first == vec[2].first && (vec[0].second <= min(vec[1].second, vec[2].second) || vec[0].second >= max(vec[1].second, vec[2].second)))	cout << 2 << endl, fl = 1;
		else if (vec[0].second == vec[1].second && (vec[2].first <= min(vec[0].first, vec[1].first) || vec[2].first >= max(vec[0].first, vec[1].first)))	cout << 2 << endl, fl = 1;
		else if (vec[0].second == vec[2].second && (vec[1].first <= min(vec[0].first, vec[2].first) || vec[1].first >= max(vec[0].first, vec[2].first)))	cout << 2 << endl, fl = 1;
		else if (vec[1].second == vec[2].second && (vec[0].first <= min(vec[1].first, vec[2].first) || vec[0].first >= max(vec[1].first, vec[2].first)))	cout << 2 << endl, fl = 1;
	}
	if (!fl)
		cout << 3 << endl;
	return	0;
}