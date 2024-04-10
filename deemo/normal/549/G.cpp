//Be Careful what you Wish for..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 2e5 + 20;

int n, vec[MAXN];
pair<int, int>	sec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = n - 1; i >= 0; i--){
		cin >> vec[i];
		sec[i].second = i, sec[i].first = (n - i) + vec[i];
	}
	sort(sec, sec + n);
	for (int i = 0; i < n - 1; i++)
		if (sec[i].first == sec[i + 1].first){
			cout << ":(\n";
			return	0;		
		}

	for (int i = 0; i < n; i++)
		cout << sec[i].first - (i + 1) << " ";
	cout << "\n";
	return	0;
}