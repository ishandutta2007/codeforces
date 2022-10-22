#include<iostream>
#include<algorithm>
#include<deque>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	deque<int>	vec(n);
	for (int i = 0; i < n; i++)	cin >> vec[i];
	sort(vec.begin(), vec.end());
	for (int i = 0; vec.size(); i++){
		if (i % 2)
			cout << vec.back() << " ", vec.pop_back();
		else
			cout << vec.front() << " ", vec.pop_front();
	}
	cout << "\n";
	return	0;
}