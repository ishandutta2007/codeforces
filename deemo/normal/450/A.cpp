#include<iostream>
#include<algorithm>
#include<deque>
#include<utility>

using namespace std;

deque<pair<int, int>>	q;

int main(){
	int n, m;	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int x;	cin >> x;
		q.push_back({i + 1, x});
	}
	while (q.size()){
		pair<int, int>	t = q.front();
		q.pop_front();
		t.second -= m;
		if (t.second > 0)
			q.push_back(t);
		if (q.empty())
			cout << t.first << endl; 
	}
	return	0;	
}