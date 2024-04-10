#include<iostream>

using namespace std;

const int MAX = 100 + 5;

int n;
int vec[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i];

	int m;	cin >> m;
	while (m--){
		int x, y;	cin >> x >> y;	x--;
		if (x - 1 >= 0)	vec[x - 1] += y - 1;
		if (x + 1 < n)	vec[x + 1] += vec[x] - y;
		vec[x] = 0;
	}
	for (int i = 0; i < n; i++)	cout << vec[i] << endl;
	return 0;
}