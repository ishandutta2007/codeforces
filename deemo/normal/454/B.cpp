#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 20;

int n, vec[MAXN], sec[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++)	cin >> vec[i];
	int ind = 1;
	for (int i = 1; i < n; i++)
		if (vec[i] >= vec[i - 1])	
			ind++;
		else
			break;

	if (ind == n){
		cout << 0 << endl;
		return	0;
	}
	
	rotate(vec, vec + ind, vec + n);
	copy(vec, vec + n, sec);
	sort(sec, sec + n);
	bool fl = 0;
	for (int i = 0; i < n; i++)
		if (sec[i] != vec[i]){
			cout << -1 << endl;
			return	0;
		}
	cout << n - ind << endl;
	return	0;
}