#include<iostream>
#include<cmath>
#include<algorithm>
#include<deque>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 20;

int n;
int vec[MAXN];
deque<int>	q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];

	int ans = 0;
	for (int i = 0; i < n; i++){
		while (q.size() && q.back() < vec[i]){
			ans = max(ans, q.back() ^ vec[i]);
			q.pop_back();
		}
		q.push_back(vec[i]);
	}
	q.clear();

	reverse(vec, vec + n);
	for (int i = 0; i < n; i++){
		while (q.size() && q.back() < vec[i]){
			ans = max(ans, q.back() ^ vec[i]);
			q.pop_back();
		}
		q.push_back(vec[i]);
	}
	cout << ans << endl;
	return 0;
}